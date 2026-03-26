#pragma once

#include <Arduino.h>

namespace drv_i2s_max98357 {
bool begin(uint32_t sampleRateHz);
bool writeFrame(const int16_t* samples, size_t count);
}
