#pragma once

#include <Arduino.h>

enum class IntercomCmd : uint8_t {
  CMD_SESSION_START = 0x01,
  CMD_SESSION_STOP = 0x02,
  CMD_AUDIO_UPLINK = 0x03,
  CMD_AUDIO_DOWNLINK = 0x04,
  CMD_SET_THRESHOLD = 0x05,
  CMD_SET_VOLUME = 0x06,
  CMD_KEEPALIVE = 0x07,
  CMD_STATUS = 0x08,
};

struct ProtoFrame {
  IntercomCmd cmd;
  uint16_t size;
  const uint8_t* payload;
};
