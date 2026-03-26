#include "max98357_output.h"

#include "../drivers/drv_i2s_max98357.h"

bool Max98357Output::begin(uint32_t sampleRateHz) { return drv_i2s_max98357::begin(sampleRateHz); }

void Max98357Output::setVolume(uint8_t volume) { volume_ = volume; }

bool Max98357Output::playFrame(const int16_t* frame, size_t samples) {
  static int16_t scaled[320];
  if (samples > 320) return false;
  for (size_t i = 0; i < samples; ++i) {
    scaled[i] = static_cast<int16_t>((static_cast<int32_t>(frame[i]) * volume_) / 255);
  }
  return drv_i2s_max98357::writeFrame(scaled, samples);
}
