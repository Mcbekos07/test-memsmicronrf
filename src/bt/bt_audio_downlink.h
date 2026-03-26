#pragma once

#include <Arduino.h>

#include "bt_link.h"

class BtAudioDownlink {
 public:
  bool begin(BtLink* link);
  uint16_t readPcm16(int16_t* outSamples, uint16_t maxSamples);

 private:
  BtLink* link_ = nullptr;
};
