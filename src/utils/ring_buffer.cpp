#include "ring_buffer.h"

RingBuffer::RingBuffer()
    : data_(nullptr), frameSize_(0), frameCount_(0), head_(0), tail_(0), used_(0) {}

bool RingBuffer::init(size_t frameSize, size_t frameCount) {
  frameSize_ = frameSize;
  frameCount_ = frameCount;
  data_ = static_cast<int16_t*>(malloc(sizeof(int16_t) * frameSize_ * frameCount_));
  clear();
  return data_ != nullptr;
}

bool RingBuffer::push(const int16_t* frame) {
  if (used_ >= frameCount_ || data_ == nullptr) return false;
  memcpy(data_ + (head_ * frameSize_), frame, sizeof(int16_t) * frameSize_);
  head_ = (head_ + 1) % frameCount_;
  ++used_;
  return true;
}

bool RingBuffer::pop(int16_t* outFrame) {
  if (used_ == 0 || data_ == nullptr) return false;
  memcpy(outFrame, data_ + (tail_ * frameSize_), sizeof(int16_t) * frameSize_);
  tail_ = (tail_ + 1) % frameCount_;
  --used_;
  return true;
}

void RingBuffer::clear() {
  head_ = 0;
  tail_ = 0;
  used_ = 0;
}

size_t RingBuffer::size() const { return used_; }
