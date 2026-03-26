#pragma once

#include <Arduino.h>

class TriggerDetector {
 public:
  void configure(float thresholdDb, float hysteresisDb);
  bool processFrame(const int16_t* frame, size_t samples, float* outDb);

 private:
  float thresholdDb_ = 45.0f;
  float hysteresisDb_ = 3.0f;
  bool armed_ = true;
};
