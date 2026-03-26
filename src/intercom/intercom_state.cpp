#include "intercom_state.h"

const char* toString(IntercomState state) {
  switch (state) {
    case IntercomState::IDLE_LISTEN: return "IDLE_LISTEN";
    case IntercomState::TRIGGER_DETECTED: return "TRIGGER_DETECTED";
    case IntercomState::BT_LINK_START: return "BT_LINK_START";
    case IntercomState::UPLINK_ACTIVE: return "UPLINK_ACTIVE";
    case IntercomState::DOWNLINK_ACTIVE: return "DOWNLINK_ACTIVE";
    case IntercomState::SESSION_TIMEOUT: return "SESSION_TIMEOUT";
    case IntercomState::RETURN_TO_IDLE: return "RETURN_TO_IDLE";
    default: return "UNKNOWN";
  }
}
