#pragma once

#include <Arduino.h>

class RingBuffer {
 public:
  RingBuffer();
  bool init(size_t frameSize, size_t frameCount);
  bool push(const int16_t* frame);
  bool pop(int16_t* outFrame);
  void clear();
  size_t size() const;

 private:
  int16_t* data_;
  size_t frameSize_;
  size_t frameCount_;
  volatile size_t head_;
  volatile size_t tail_;
  volatile size_t used_;
};
