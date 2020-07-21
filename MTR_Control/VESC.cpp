#include "VESC.hpp"

state_t STATE;
dataPackageVESC_t VESC_Values;

long dif_tachometer;
static long init_tachometer;


/** Initiate VescUart class */
VescUart UART;

/** Create software serial port using 2 digital extra outputs */
SoftwareSerial vescSerial(2, 3); // Rx, Tx

void VESCInit(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE){
  /** Define which ports to use as UART */
  UART.setSerialPort(&vescSerial);
  
  /** Setup vescSerial port **/
  vescSerial.begin(19200);
  
  ptrVESC_Values->avgMotorCurrent = 0;
  ptrVESC_Values->avgInputCurrent = 0;
  ptrVESC_Values->dutyCycleNow = 0;
  ptrVESC_Values->rpm = 0;
  ptrVESC_Values->inpVoltage = 0;
  ptrVESC_Values->ampHours = 0;
  ptrVESC_Values->ampHoursCharged = 0;
  ptrVESC_Values->wattHours = 0;
  ptrVESC_Values->wattHoursCharged = 0;
  ptrVESC_Values->tachometer = 0;
  ptrVESC_Values->tachometerAbs = 0;
  ptrVESC_Values->tempMosfet = 0;
  ptrVESC_Values->tempMotor = 0;
  ptrVESC_Values->error = 0; 
  ptrVESC_Values->pidPos = 0;
  ptrVESC_Values->id = 0; 

  TaskGetValues(&VESC_Values);

  init_tachometer = ptrVESC_Values->tachometer;

  dif_tachometer = ptrVESC_Values->tachometer - init_tachometer;

  *ptrSTATE = INIT;
}

void TaskGetValues(dataPackageVESC_t *ptrVESC_Values){
  if(UART.getVescValues()){
    ptrVESC_Values->avgMotorCurrent = UART.data.avgMotorCurrent;
    ptrVESC_Values->avgInputCurrent = UART.data.avgInputCurrent;
    ptrVESC_Values->dutyCycleNow = UART.data.dutyCycleNow;
    ptrVESC_Values->rpm = UART.data.rpm;
    ptrVESC_Values->inpVoltage = UART.data.inpVoltage;
    ptrVESC_Values->ampHours = UART.data.ampHours;
    ptrVESC_Values->ampHoursCharged = UART.data.ampHoursCharged;
    ptrVESC_Values->wattHours = UART.data.wattHours;
    ptrVESC_Values->wattHoursCharged = UART.data.wattHoursCharged;
    ptrVESC_Values->tachometer = UART.data.tachometer;
    ptrVESC_Values->tachometerAbs = UART.data.tachometerAbs;
    ptrVESC_Values->tempMosfet = UART.data.tempMosfet;
    ptrVESC_Values->tempMotor = UART.data.tempMotor;
    ptrVESC_Values->error = UART.data.error;
    ptrVESC_Values->pidPos = UART.data.pidPos;
    ptrVESC_Values->id = UART.data.id;

    dif_tachometer = ptrVESC_Values->tachometer - init_tachometer;
  }
  else
  {
    Serial.println("Failed to get data!");
  }
}

void VESC_setCurrent(float current){
  UART.setCurrent(current);
}

void VESC_setBrakeCurrent(float current){
  UART.setBrakeCurrent(current);
}

void VESC_setHandBrakeCurrent(float current){
  UART.setHandBrakeCurrent(current);
}

void TaskVESC_Control(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE, timerRef_t *ptrTIMER){
  if(*ptrSTATE == INIT){
    VESC_setBrakeCurrent(20.0);
    if(ptrVESC_Values->rpm<-200){
      *ptrSTATE = TRANS_I_TO_B;
      enableTimer();
    }
  }
  else if(*ptrSTATE == TRANS_I_TO_B){
    VESC_setBrakeCurrent(20.0);
    if(*ptrTIMER == TIMER_FINISH){
      *ptrSTATE = BRAKING;
      disableTimer();
    }
  }
  else if(*ptrSTATE == BRAKING){
    VESC_setBrakeCurrent(20.0);
    if(ptrVESC_Values->rpm>-1000){
      *ptrSTATE = TRANS_B_TO_R;
      enableTimer();
    }
  }
  else if(*ptrSTATE == HANDBRAKING){
    VESC_setHandBrakeCurrent(5.0);
    if(*ptrTIMER == TIMER_FINISH){
      *ptrSTATE = TRANS_B_TO_R;
      enableTimer();
    }
  }
  else if(*ptrSTATE == TRANS_B_TO_R){
    VESC_setCurrent(2.0);
    if(*ptrTIMER == TIMER_FINISH){
      *ptrSTATE = RECOVERING;
      disableTimer();
    }
  }
  else if(*ptrSTATE == RECOVERING){
    VESC_setCurrent(4.0);
//    if((ptrVESC_Values->avgMotorCurrent>4.9) && (ptrVESC_Values->rpm<500)||(ptrVESC_Values->rpm<-200)){
    if(ptrVESC_Values->rpm<400){
      *ptrSTATE = INIT;
      init_tachometer = ptrVESC_Values->tachometer;
    }
  }
}
