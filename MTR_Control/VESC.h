#include <Arduino_FreeRTOS.h>
#include <VescUart.h>
#include <SoftwareSerial.h>

typedef struct {
    float avgMotorCurrent;
    float avgInputCurrent;
    float dutyCycleNow;
    float rpm;
    float inpVoltage;
    float ampHours;
    float ampHoursCharged;
    float wattHours;
    float wattHoursCharged;
    long tachometer;
    long tachometerAbs;
    float tempMosfet;
    float tempMotor;
    uint8_t error; 
    float pidPos;
    uint8_t id; 
} dataPackageVESC_t ;

void VESCInit(dataPackageVESC_t *ptrVESC_Values);

void VESCgetValues(dataPackageVESC_t *ptrVESC_Values);
