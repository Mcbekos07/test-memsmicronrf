#include "trigger_detector.h"

#include <math.h>

void TriggerDetector::configure(float thresholdDb, float hysteresisDb) {
  thresholdDb_ = thresholdDb;
  hysteresisDb_ = hysteresisDb;
}

bool TriggerDetector::processFrame(const int16_t* frame, size_t samples, float* outDb) {
  double sum = 0;
  for (size_t i = 0; i < samples; ++i) {
    const float x = frame[i] / 32768.0f;
    sum += x * x;
  }
  const float rms = sqrt(sum / samples);
  const float db = 20.0f * log10f(rms + 1e-6f) + 90.0f;
  if (outDb) *outDb = db;

  if (armed_ && db >= thresholdDb_) {
    armed_ = false;
    return true;
  }
  if (!armed_ && db < (thresholdDb_ - hysteresisDb_)) {
    armed_ = true;
  }
  return false;
}
