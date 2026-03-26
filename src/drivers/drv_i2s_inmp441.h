#pragma once

#include <Arduino.h>

namespace drv_i2s_inmp441 {
bool begin(uint32_t sampleRateHz);
bool readFrame(int16_t* outSamples, size_t samples);
}
