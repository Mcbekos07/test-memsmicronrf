#include "bt_audio_downlink.h"

uint16_t BtAudioDownlink::readPcm16(int16_t* outSamples, uint16_t maxSamples) {
  if (!link_) return 0;
  return link_->receive(reinterpret_cast<uint8_t*>(outSamples), maxSamples * sizeof(int16_t)) / sizeof(int16_t);
}

bool BtAudioDownlink::begin(BtLink* link) {
  link_ = link;
  return link_ != nullptr;
}
