#include <PS4BT.h>
#include <usbhub.h>
#include <Wire.h>

USB Usb;
BTD Btd(&Usb);
PS4BT PS4(&Btd);

const int SLAVE_ADDR = 8;

struct {
  uint8_t w1;
  uint8_t w2;
  uint8_t w3;
  uint8_t w4;
  uint8_t w5;
  uint8_t w6;
} response;

void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  if (Usb.Init() == -1) {
    while (1); // Halt
  }
}

void loop() {
  Usb.Task();
  SensorsRead();
}

void requestEvent() {

  // as expected by master
  Wire.write(response.w1);
  Wire.write(response.w2);
  Wire.write(response.w3);
  Wire.write(response.w4);
  Wire.write(response.w5);
  Wire.write(response.w6);
}

void SensorsRead() {
  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 || PS4.getAnalogHat(RightHatX) > 137 || PS4.getAnalogHat(RightHatX) < 117 || PS4.getAnalogHat(RightHatY) > 137 || PS4.getAnalogHat(RightHatY) < 117) {
      response.w1 = PS4.getAnalogHat(LeftHatX);
      response.w2 = PS4.getAnalogHat(LeftHatY);
      response.w3 = PS4.getAnalogHat(RightHatX);
      response.w4 = PS4.getAnalogHat(RightHatY);
      if (PS4.getButtonClick(PS)) {
        PS4.disconnect();
      }
    }
    if (PS4.getButtonPress(UP)) {
      response.w5 = 1;
    }
    else {
      response.w5 = 0;
    }
    if (PS4.getButtonPress(DOWN)) {
      response.w6 = 1;
    }
    else {
      response.w6 = 0;
    }
  }
}
