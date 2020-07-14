/** Todo lo relacionado con el VESC **/
#include "VESC.h"

/** Initiate VescUart class */
VescUart UART;

/** Create software serial port using 2 digital extra outputs */
SoftwareSerial vescSerial(2, 3); // Rx, Tx

struct VESC_Values{
  int
}

void VESC_Init(){
    /** Setup vescSerial port **/
  vescSerial.begin(19200);
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&vescSerial);
}

void VESC_GetValues(void *param){
  UART.data.rpm
}


void VESC_PrintValues(void *param){
/** Call the function getVescValues() to acquire data from VESC */
  if ( UART.getVescValues() ) {
    //Serial.print(toggle);
    //Serial.print(", ");
    Serial.print(UART.data.rpm);
    Serial.print(", ");
    Serial.print(UART.data.avgInputCurrent);
    Serial.print(", ");
    Serial.print(UART.data.avgMotorCurrent);
    Serial.print(", ");
    Serial.print(UART.data.dutyCycleNow);
    Serial.print(", ");
    Serial.print(UART.data.tachometer);
    Serial.print(", ");
    Serial.print(UART.data.inpVoltage);
    Serial.print(", ");
    Serial.print(UART.data.ampHours);
    Serial.print(", ");
    Serial.println(UART.data.ampHoursCharged);
    //Serial.print(", ");
    //Serial.println(UART.data.tachometerAbs);
  }
  else
  {
    Serial.println("Failed to get data!");
  }
}

void VESC_SetCurrent(float current){
  UART.setCurrent(param);
}

void VESC_SetBrakeCurrent(float current){
  UART.setBrakeCurrent(param);
}
