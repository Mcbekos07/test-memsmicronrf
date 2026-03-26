#include "timer.h"

SoftTimer::SoftTimer() : startMs_(0), intervalMs_(0), active_(false) {}

void SoftTimer::start(uint32_t intervalMs) {
  intervalMs_ = intervalMs;
  startMs_ = millis();
  active_ = true;
}

bool SoftTimer::expired() const {
  return active_ && (millis() - startMs_ >= intervalMs_);
}

void SoftTimer::stop() { active_ = false; }
