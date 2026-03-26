#include "bt_manager.h"

#include <Arduino.h>

bool BtManager::begin(const char* deviceName) {
  Serial.print("[BT] init stack, name=");
  Serial.println(deviceName);
  return true;
}

bool BtManager::connectToGateway() {
  Serial.println("[BT] connecting to gateway...");
  connected_ = true;
  return true;
}

bool BtManager::isConnected() const { return connected_; }

void BtManager::disconnect() {
  connected_ = false;
  Serial.println("[BT] disconnected");
}
