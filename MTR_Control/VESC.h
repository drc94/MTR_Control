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

typedef enum {
  initial = 0,
  braking,
  recovering
} state_t;

static dataPackageVESC_t VESC_Values;
static state_t STATE;

void VESCInit(dataPackageVESC_t *ptrVESC_Values);

void TaskGetValues(dataPackageVESC_t *ptrVESC_Values);

void TaskVESC_Control(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE);
void VESC_setCurrent(float current);
void VESC_setBrakeCurrent(float current);
void VESC_setHandBrakeCurrent(float current);
