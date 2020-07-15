/** Todo lo relacionado con el VESC **/
#include <VescUart.h>
#include <SoftwareSerial.h>
#include <Arduino_FreeRTOS.h>

void VESC_Init();
void VESC_printValues(void *param);
void VESC_getValues(void *param);
void VESC_control(void *param);
void VESC_setCurrent(float current);
void VESC_setBrakeCurrent(float current);
void VESC_setHandBrake(float current);

struct dataPackageVESC {
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
};
