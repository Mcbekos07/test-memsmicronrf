#pragma once

#include <Arduino.h>

class SoftTimer {
 public:
  SoftTimer();
  void start(uint32_t intervalMs);
  bool expired() const;
  void stop();

 private:
  uint32_t startMs_;
  uint32_t intervalMs_;
  bool active_;
};
