#pragma once

#include <Arduino.h>

class Max98357Output {
 public:
  bool begin(uint32_t sampleRateHz);
  void setVolume(uint8_t volume);
  bool playFrame(const int16_t* frame, size_t samples);

 private:
  uint8_t volume_ = 255;
};
