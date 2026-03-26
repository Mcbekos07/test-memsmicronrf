#include "bt_audio_uplink.h"

bool BtAudioUplink::begin(BtLink* link) {
  link_ = link;
  return link_ != nullptr;
}

bool BtAudioUplink::sendPcm16(const int16_t* samples, uint16_t sampleCount) {
  if (!link_) return false;
  return link_->send(reinterpret_cast<const uint8_t*>(samples), sampleCount * sizeof(int16_t));
}
