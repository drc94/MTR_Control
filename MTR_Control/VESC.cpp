/** Todo lo relacionado con el VESC **/
#include "VESC.h"

/** Initiate VescUart class */
VescUart UART;

/** Create software serial port using 2 digital extra outputs */
SoftwareSerial vescSerial(2, 3); // Rx, Tx

dataPackageVESC VESC_Values;

void VESC_Init(){
    /** Setup vescSerial port **/
  vescSerial.begin(19200);
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&vescSerial);
}

void VESC_getValues(void *param){
/** Call the function getVescValues() to acquire data from VESC */
  if ( UART.getVescValues() ) {
    VESC_Values.avgMotorCurrent = UART.data.avgMotorCurrent;
    VESC_Values.avgInputCurrent = UART.data.avgInputCurrent;
    VESC_Values.dutyCycleNow = UART.data.dutyCycleNow;
    VESC_Values.rpm = UART.data.rpm;
    VESC_Values.inpVoltage = UART.data.inpVoltage;
    VESC_Values.ampHours = UART.data.ampHours;
    VESC_Values.ampHoursCharged = UART.data.ampHoursCharged;
    VESC_Values.wattHours = UART.data.wattHours;
    VESC_Values.wattHoursCharged = UART.data.wattHoursCharged;
    VESC_Values.tachometer = UART.data.tachometer;
    VESC_Values.tachometerAbs = UART.data.tachometerAbs;
    VESC_Values.tempMosfet = UART.data.tempMosfet;
    VESC_Values.error = UART.data.error;
    VESC_Values.pidPos = UART.data.pidPos;
    VESC_Values.id = UART.data.id;
  }
  else
  {
    Serial.println("Failed to get data!");
  }
  vTaskDelay(200/portTICK_PERIOD_MS); //200ms
}

void VESC_printValues(void *param){
  Serial.print(VESC_Values.rpm);
  Serial.print(", ");
  Serial.print(VESC_Values.avgInputCurrent);
  Serial.print(", ");
  Serial.print(VESC_Values.avgMotorCurrent);
  Serial.print(", ");
  Serial.print(VESC_Values.dutyCycleNow);
  Serial.print(", ");
  Serial.print(VESC_Values.tachometer);
  Serial.print(", ");
  Serial.print(VESC_Values.inpVoltage);
  Serial.print(", ");
  Serial.print(VESC_Values.ampHours);
  Serial.print(", ");
  Serial.println(VESC_Values.ampHoursCharged);
  //Serial.print(", ");
  //Serial.println(VESC_Values.tachometerAbs);
  vTaskDelay(200/portTICK_PERIOD_MS); //200ms
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

void VESC_control(void *param){
  vTaskDelay(200/portTICK_PERIOD_MS); //200ms
}
