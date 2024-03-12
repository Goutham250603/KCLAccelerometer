#include "KCLAccelerometer.h"

KCLAccelerometer::KCLAccelerometer() {
  // Constructor implementation
}

void KCLAccelerometer::begin() {
  // Initialize the Wire library for I2C communication
  Wire.begin();
  
  // Enable the accelerometer by writing to the POWER_CTL register
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(ADXL345_REG_POWER_CTL);
  Wire.write(0x08); // Set measure bit in POWER_CTL register (0x08)
  Wire.endTransmission();
}

void KCLAccelerometer::collectData() {
  // Collect acceleration data from the accelerometer
  readFromAccelerometer(ADXL345_REG_DATA_X0, sampleDataX);
  readFromAccelerometer(ADXL345_REG_DATA_Y0, sampleDataY);
  readFromAccelerometer(ADXL345_REG_DATA_Z0, sampleDataZ);
}

int16_t* KCLAccelerometer::getXData() {
  return sampleDataX;
}

int16_t* KCLAccelerometer::getYData() {
  return sampleDataY;
}

int16_t* KCLAccelerometer::getZData() {
  return sampleDataZ;
}

void KCLAccelerometer::readFromAccelerometer(byte regAddress, int16_t* data) {
  //
