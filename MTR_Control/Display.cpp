#include "Display.hpp"
#include <Arduino.h>

void displayInit(){
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
}

void TaskPrint(dataPackageVESC_t *ptrVESC_Values, state_t *ptrSTATE)  // This is a task.
{
  Serial.print(ptrVESC_Values->rpm);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->avgInputCurrent);
  Serial.print(", ");
  Serial.print(ptrVESC_Values->avgMotorCurrent);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->dutyCycleNow);
  Serial.print(", ");
  Serial.print(dif_tachometer);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->inpVoltage);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->ampHours);
  //Serial.print(", ");
  //Serial.println(ptrVESC_Values->ampHoursCharged);
  Serial.print(", ");

  if(*ptrSTATE == INIT) Serial.println("INIT");
  else if(*ptrSTATE == TRANS_I_TO_B) Serial.println("TRANS_I_TO_B");
  else if(*ptrSTATE == BRAKING) Serial.println("BRAKING");
  else if(*ptrSTATE == TRANS_B_TO_R) Serial.println("TRANS_B_TO_R");
  else if(*ptrSTATE == RECOVERING) Serial.println("RECOVERING");
  else if(*ptrSTATE == TRANS_R_TO_B) Serial.println("TRANS_R_TO_B");
  else if(*ptrSTATE == HANDBRAKING) Serial.println("HANDBRAKING");

}
