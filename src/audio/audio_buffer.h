#pragma once

#include "../utils/ring_buffer.h"

class AudioBuffer {
 public:
  bool begin(size_t frameSamples, size_t frameCount);
  bool pushFrame(const int16_t* frame);
  bool popFrame(int16_t* outFrame);
  void clear();
  size_t queuedFrames() const;

 private:
  RingBuffer rb_;
};
