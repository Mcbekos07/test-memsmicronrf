#pragma once

#include <Arduino.h>

namespace pins {
constexpr uint8_t kInmpSck = 8;
constexpr uint8_t kInmpWs = 9;
constexpr uint8_t kInmpSd = 10;

constexpr uint8_t kMaxBclk = 11;
constexpr uint8_t kMaxLrc = 12;
constexpr uint8_t kMaxDin = 13;

constexpr uint8_t kAmpEnable = 7;
constexpr uint8_t kBatteryAdc = A0;
}
