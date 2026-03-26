#pragma once

enum class IntercomState {
  IDLE_LISTEN,
  TRIGGER_DETECTED,
  BT_LINK_START,
  UPLINK_ACTIVE,
  DOWNLINK_ACTIVE,
  SESSION_TIMEOUT,
  RETURN_TO_IDLE,
};

const char* toString(IntercomState state);
