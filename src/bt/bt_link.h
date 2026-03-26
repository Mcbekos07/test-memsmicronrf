#pragma once

#include "bt_manager.h"

class BtLink {
 public:
  bool begin(BtManager* manager);
  bool send(const uint8_t* data, uint16_t size);
  uint16_t receive(uint8_t* out, uint16_t maxSize);

 private:
  BtManager* manager_ = nullptr;
};
