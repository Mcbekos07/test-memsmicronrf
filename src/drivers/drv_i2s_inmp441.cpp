#include "drv_i2s_inmp441.h"

namespace drv_i2s_inmp441 {
bool begin(uint32_t) { return true; }

bool readFrame(int16_t* outSamples, size_t samples) {
  // TODO: replace with real I2S read for INMP441.
  for (size_t i = 0; i < samples; ++i) outSamples[i] = random(-1000, 1000);
  return true;
}
}  // namespace drv_i2s_inmp441
