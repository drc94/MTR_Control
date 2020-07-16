#include "VESC.h"

/** Initiate VescUart class */
VescUart UART;

/** Create software serial port using 2 digital extra outputs */
SoftwareSerial vescSerial(2, 3); // Rx, Tx

void VESCInit(dataPackageVESC_t *ptrVESC_Values){
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
}

void VESCgetValues(dataPackageVESC_t *ptrVESC_Values){
  ptrVESC_Values->avgMotorCurrent = UART.data.avgMotorCurrent;
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
}
