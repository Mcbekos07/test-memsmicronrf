#include "inmp441_input.h"

#include "../drivers/drv_i2s_inmp441.h"

bool Inmp441Input::begin(uint32_t sampleRateHz) { return drv_i2s_inmp441::begin(sampleRateHz); }
bool Inmp441Input::readFrame(int16_t* outSamples, size_t samples) {
  return drv_i2s_inmp441::readFrame(outSamples, samples);
}
