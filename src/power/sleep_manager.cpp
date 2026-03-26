#include "sleep_manager.h"

#include <Arduino.h>

void SleepManager::idleTick() {
  // Hook for low-power idle sleep integration.
  delay(1);
}
