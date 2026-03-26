#pragma once

class BtManager {
 public:
  bool begin(const char* deviceName);
  bool connectToGateway();
  bool isConnected() const;
  void disconnect();

 private:
  bool connected_ = false;
};
