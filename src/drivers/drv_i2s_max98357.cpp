#include "drv_i2s_max98357.h"

namespace drv_i2s_max98357 {
bool begin(uint32_t) { return true; }

bool writeFrame(const int16_t*, size_t) {
  // TODO: replace with real I2S write for MAX98357A.
  return true;
}
}  // namespace drv_i2s_max98357
