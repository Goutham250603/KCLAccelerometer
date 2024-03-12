#ifndef KCLAccelerometer_h
#define KCLAccelerometer_h

#include <Arduino.h>
#include <Wire.h> // Include the Wire library for I2C communication

// ADXL345 register addresses
#define ADXL345_ADDRESS 0x53
#define ADXL345_REG_POWER_CTL 0x2D
#define ADXL345_REG_DATA_X0 0x32
#define ADXL345_REG_DATA_Y0 0x34
#define ADXL345_REG_DATA_Z0 0x36

class KCLAccelerometer {
  public:
    KCLAccelerometer();

    // Function to initialize the accelerometer
    void begin();

    // Function to collect acceleration data
    void collectData();

    // Function to get X-axis acceleration data
    int16_t* getXData();

    // Function to get Y-axis acceleration data
    int16_t* getYData();

    // Function to get Z-axis acceleration data
    int16_t* getZData();

  private:
    // Variables to store acceleration data
    int16_t sampleDataX[100];
    int16_t sampleDataY[100];
    int16_t sampleDataZ[100];

    // Function to read data from the ADXL345 accelerometer
    void readFromAccelerometer(byte regAddress, int16_t* data);
};

#endif
