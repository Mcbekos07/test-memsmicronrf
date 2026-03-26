#include "power_manager.h"

#include <Arduino.h>

void PowerManager::begin() { Serial.println("[PWR] power manager init"); }
void PowerManager::enterStandbyMode() { Serial.println("[PWR] enter standby"); }
void PowerManager::exitStandbyMode() { Serial.println("[PWR] exit standby"); }
