#include "drv_battery.h"

#include <Arduino.h>

#include "../config/pins.h"

namespace drv_battery {
void init() { pinMode(pins::kBatteryAdc, INPUT); }

float readVoltage() {
  const int raw = analogRead(pins::kBatteryAdc);
  return (raw / 1023.0f) * 3.3f * 2.0f;  // divider x2 assumption
}
}  // namespace drv_battery
