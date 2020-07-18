#include "Display.h"
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
  Serial.print(ptrVESC_Values->tachometer);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->inpVoltage);
  //Serial.print(", ");
  //Serial.print(ptrVESC_Values->ampHours);
  //Serial.print(", ");
  //Serial.println(ptrVESC_Values->ampHoursCharged);
  Serial.print(", ");
  Serial.println(*ptrSTATE);
}
