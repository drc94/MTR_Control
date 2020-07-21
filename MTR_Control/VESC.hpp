#include <VescUart.h>
#include <SoftwareSerial.h>
#include "TimerInt.hpp"

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

typedef enum {
  INIT = 0,
  TRANS_I_TO_B,
  BRAKING,
  TRANS_B_TO_R,
  RECOVERING,
  TRANS_R_TO_B,
  HANDBRAKING
} state_t;

extern dataPackageVESC_t VESC_Values;
extern state_t STATE;
extern long dif_tachometer;

void VESCInit(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE);

void TaskGetValues(dataPackageVESC_t *ptrVESC_Values);

void TaskVESC_Control(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE, timerRef_t *ptrTIMER);
void VESC_setCurrent(float current);
void VESC_setBrakeCurrent(float current);
void VESC_setHandBrakeCurrent(float current);
