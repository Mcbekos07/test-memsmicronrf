#include "audio_buffer.h"

bool AudioBuffer::begin(size_t frameSamples, size_t frameCount) { return rb_.init(frameSamples, frameCount); }
bool AudioBuffer::pushFrame(const int16_t* frame) { return rb_.push(frame); }
bool AudioBuffer::popFrame(int16_t* outFrame) { return rb_.pop(outFrame); }
void AudioBuffer::clear() { rb_.clear(); }
size_t AudioBuffer::queuedFrames() const { return rb_.size(); }
