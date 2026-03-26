#include "bt_link.h"

#include <Arduino.h>

bool BtLink::begin(BtManager* manager) {
  manager_ = manager;
  return manager_ != nullptr;
}

bool BtLink::send(const uint8_t*, uint16_t size) {
  if (!manager_ || !manager_->isConnected()) return false;
  Serial.print("[BT] tx bytes=");
  Serial.println(size);
  return true;
}

uint16_t BtLink::receive(uint8_t*, uint16_t) {
  if (!manager_ || !manager_->isConnected()) return 0;
  return 0;
}
