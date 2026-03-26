#pragma once

#include "../utils/timer.h"

class IntercomSession {
 public:
  void begin(uint32_t timeoutMs);
  void refreshActivity();
  bool timedOut() const;

 private:
  SoftTimer timeout_;
  uint32_t timeoutMs_ = 3000;
};
