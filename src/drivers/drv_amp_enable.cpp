#include "drv_amp_enable.h"

#include <Arduino.h>

#include "../config/pins.h"

namespace {
bool g_enabled = false;
}

namespace drv_amp {
void init() {
  pinMode(pins::kAmpEnable, OUTPUT);
  setEnabled(false);
}

void setEnabled(bool enabled) {
  g_enabled = enabled;
  digitalWrite(pins::kAmpEnable, enabled ? HIGH : LOW);
}

bool isEnabled() { return g_enabled; }
}  // namespace drv_amp
