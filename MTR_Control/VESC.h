/** Todo lo relacionado con el VESC **/
#include <VescUart.h>
#include <SoftwareSerial.h>

void VESC_Init();
void VESC_PrintValues(void *param);
void VESC_GetValues(void *param);
void VESC_SetCurrent(float current);
void VESC_SetBrakeCurrent(float current);
void VESC_SetHandBrake(float current);
void VESC_Control(void *param);

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
