#include "VESC.h"

<<<<<<< HEAD
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

void TaskGetValues(void *pvParameters){
  dataPackageVESC_t *ptrVESC_Values = &VESC_Values;
  for (;;) // A Task shall never return or exit.
  {
    if(UART.getVescValues()){
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
    else
    {
      Serial.println("Failed to get data!");
    }
  }
=======
void VESC_setCurrent(float current){
  UART.setCurrent(current);
}

void VESC_setBrakeCurrent(float current){
  UART.setBrakeCurrent(current);
}

void VESC_setHandBrakeCurrent(float current){
  UART.setHandBrakeCurrent(current);
}

void VESC_control(){
  vTaskDelay(200/portTICK_PERIOD_MS); //200ms
>>>>>>> origin/hand_brake_function
}
