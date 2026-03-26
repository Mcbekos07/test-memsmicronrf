#pragma once

#include <Arduino.h>

class Inmp441Input {
 public:
  bool begin(uint32_t sampleRateHz);
  bool readFrame(int16_t* outSamples, size_t samples);
};
