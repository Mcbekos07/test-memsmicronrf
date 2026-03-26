#pragma once

#include <Arduino.h>

namespace cfg {
constexpr uint32_t kLogBaudRate = 115200;
constexpr uint32_t kSampleRateHz = 16000;
constexpr size_t kAudioFrameSamples = 160;      // 10 ms @ 16kHz
constexpr size_t kAudioBufferFrames = 64;
constexpr float kTriggerThresholdDb = 45.0f;
constexpr float kTriggerHysteresisDb = 3.0f;
constexpr uint32_t kSessionSilenceTimeoutMs = 3000;
constexpr uint32_t kKeepAlivePeriodMs = 1000;
constexpr uint8_t kDefaultVolume = 200;          // 0..255
}
