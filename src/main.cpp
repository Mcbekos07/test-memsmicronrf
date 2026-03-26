#include <Arduino.h>

#include "intercom/intercom_app.h"

IntercomApp app;

void setup() { app.begin(); }

void loop() { app.tick(); }
