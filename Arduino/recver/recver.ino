#include <Wire.h>

// Define Slave I2C Address
const int SLAVE_ADDR = 8;

struct {
  uint8_t w1;
  uint8_t w2;
  uint8_t w3;
  uint8_t w4;
  uint8_t w5;
  uint8_t w6;
} response;

uint8_t anlgLx;
uint8_t anlgLy;
uint8_t anlgRx;
uint8_t anlgRy;
uint8_t up;
uint8_t dn;

// Define Slave answer size
const int ANSWERSIZE = sizeof(response);

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  ReceiveSlave();
  Decode();
}

void ReceiveSlave()  {
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);
  response.w1 = Wire.read();
  response.w2 = Wire.read();
  response.w3 = Wire.read();
  response.w4 = Wire.read();
  response.w5 = Wire.read();
  response.w6 = Wire.read();
}

void Decode() {
  anlgLx = response.w1;
  anlgLy = response.w2;
  anlgRx = response.w3;
  anlgRy = response.w4;
  up = response.w5;
  dn = response.w6;
  Serial.print(anlgLx);
  Serial.print(" ");
  Serial.print(anlgLy);
  Serial.print(" ");
  Serial.print(anlgRx);
  Serial.print(" ");
  Serial.print(anlgRy);
  Serial.print(" ");
  Serial.print(up);
  Serial.print(" ");
  Serial.print(dn);
  Serial.println(" ");
}
