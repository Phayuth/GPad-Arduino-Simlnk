#include <PS4BT.h>
#include <usbhub.h>
//#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
//PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device
PS4BT PS4(&Btd);

int Ltwo;
int Rtwo;
void setup() {
  Serial.begin(115200);
  //#if !defined(__MIPSEL__)
  //  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  //#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}
void loop() {
  Usb.Task();
  if (PS4.connected()) {
    //    Serial.println(PS4.getAnalogHat(LeftHatX));
    if (PS4.getButtonClick(TRIANGLE)) {
      Serial.println("Dddd");
    }
    //        Serial.println(PS4.getAnalogHat(LeftHatY));
    //        Serial.println(PS4.getAnalogHat(RightHatX));
    //        Serial.println(PS4.getAnalogHat(RightHatY));
    //    Ltwo = PS4.getAnalogButton(L2);
    //    Rtwo = PS4.getAnalogButton(R2);
    //    Serial.println(Ltwo);
    //    Serial.println(Rtwo);
    if (PS4.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
  }
  //    PS4.getButtonClick(TRIANGLE);
  //    PS4.getButtonClick(CIRCLE);
  //    PS4.getButtonClick(CROSS);
  //    PS4.getButtonClick(SQUARE);
  //    PS4.getButtonClick(UP);
  //    PS4.getButtonClick(RIGHT);
  //    PS4.getButtonClick(DOWN);
  //    PS4.getButtonClick(LEFT);
  //    PS4.getButtonClick(L1);
  //    PS4.getButtonClick(L3);
  //    PS4.getButtonClick(R1);
  //    PS4.getButtonClick(R3)
}
