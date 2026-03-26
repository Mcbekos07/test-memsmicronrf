#include "intercom_app.h"

#include <Arduino.h>

#include "../audio/audio_buffer.h"
#include "../audio/inmp441_input.h"
#include "../audio/max98357_output.h"
#include "../audio/trigger_detector.h"
#include "../bt/bt_audio_downlink.h"
#include "../bt/bt_audio_uplink.h"
#include "../bt/bt_link.h"
#include "../bt/bt_manager.h"
#include "../config/defaults.h"
#include "../drivers/drv_amp_enable.h"
#include "../drivers/drv_battery.h"
#include "../power/power_manager.h"
#include "../power/sleep_manager.h"
#include "intercom_session.h"
#include "intercom_state.h"

namespace {
IntercomState g_state = IntercomState::IDLE_LISTEN;
Inmp441Input g_input;
Max98357Output g_output;
TriggerDetector g_trigger;
BtManager g_btManager;
BtLink g_btLink;
BtAudioUplink g_uplink;
BtAudioDownlink g_downlink;
PowerManager g_power;
SleepManager g_sleep;
IntercomSession g_session;

int16_t g_micFrame[cfg::kAudioFrameSamples];
int16_t g_rxFrame[cfg::kAudioFrameSamples];

void setState(IntercomState newState) {
  if (newState == g_state) return;
  Serial.print("[STATE] ");
  Serial.print(toString(g_state));
  Serial.print(" -> ");
  Serial.println(toString(newState));
  g_state = newState;
}
}  // namespace

void IntercomApp::begin() {
  Serial.begin(cfg::kLogBaudRate);
  delay(300);
  Serial.println("\n[BOOT] BLE Intercom (nRF52840 Pro Micro)");

  drv_amp::init();
  drv_battery::init();
  g_power.begin();
  g_input.begin(cfg::kSampleRateHz);
  g_output.begin(cfg::kSampleRateHz);
  g_output.setVolume(cfg::kDefaultVolume);
  g_trigger.configure(cfg::kTriggerThresholdDb, cfg::kTriggerHysteresisDb);

  g_btManager.begin("nRF52840-Intercom");
  g_btLink.begin(&g_btManager);
  g_uplink.begin(&g_btLink);
  g_downlink.begin(&g_btLink);

  setState(IntercomState::IDLE_LISTEN);
}

void IntercomApp::tick() {
  float db = 0.0f;
  g_input.readFrame(g_micFrame, cfg::kAudioFrameSamples);

  switch (g_state) {
    case IntercomState::IDLE_LISTEN: {
      if (g_trigger.processFrame(g_micFrame, cfg::kAudioFrameSamples, &db)) {
        Serial.print("[TRIG] level=");
        Serial.print(db, 1);
        Serial.println(" dB");
        setState(IntercomState::TRIGGER_DETECTED);
      } else {
        g_sleep.idleTick();
      }
      break;
    }

    case IntercomState::TRIGGER_DETECTED:
      setState(IntercomState::BT_LINK_START);
      break;

    case IntercomState::BT_LINK_START:
      g_power.exitStandbyMode();
      if (g_btManager.connectToGateway()) {
        g_session.begin(cfg::kSessionSilenceTimeoutMs);
        setState(IntercomState::UPLINK_ACTIVE);
      } else {
        setState(IntercomState::RETURN_TO_IDLE);
      }
      break;

    case IntercomState::UPLINK_ACTIVE:
      g_uplink.sendPcm16(g_micFrame, cfg::kAudioFrameSamples);
      if (g_session.timedOut()) {
        setState(IntercomState::SESSION_TIMEOUT);
      } else {
        setState(IntercomState::DOWNLINK_ACTIVE);
      }
      break;

    case IntercomState::DOWNLINK_ACTIVE: {
      const uint16_t n = g_downlink.readPcm16(g_rxFrame, cfg::kAudioFrameSamples);
      if (n > 0) {
        drv_amp::setEnabled(true);
        g_output.playFrame(g_rxFrame, n);
        g_session.refreshActivity();
      } else {
        drv_amp::setEnabled(false);
      }
      if (g_session.timedOut()) setState(IntercomState::SESSION_TIMEOUT);
      else setState(IntercomState::UPLINK_ACTIVE);
      break;
    }

    case IntercomState::SESSION_TIMEOUT:
      Serial.println("[SESSION] timeout");
      g_btManager.disconnect();
      setState(IntercomState::RETURN_TO_IDLE);
      break;

    case IntercomState::RETURN_TO_IDLE:
      drv_amp::setEnabled(false);
      g_power.enterStandbyMode();
      Serial.print("[BAT] V=");
      Serial.println(drv_battery::readVoltage(), 2);
      setState(IntercomState::IDLE_LISTEN);
      break;
  }
}
