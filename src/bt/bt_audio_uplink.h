#pragma once

#include <Arduino.h>

#include "bt_link.h"

class BtAudioUplink {
 public:
  bool begin(BtLink* link);
  bool sendPcm16(const int16_t* samples, uint16_t sampleCount);

 private:
  BtLink* link_ = nullptr;
};
