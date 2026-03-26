#include "intercom_session.h"

void IntercomSession::begin(uint32_t timeoutMs) {
  timeoutMs_ = timeoutMs;
  timeout_.start(timeoutMs_);
}

void IntercomSession::refreshActivity() { timeout_.start(timeoutMs_); }

bool IntercomSession::timedOut() const { return timeout_.expired(); }
