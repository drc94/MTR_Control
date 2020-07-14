#include "VESC.h"
#include <Arduino_FreeRTOS.h>

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(9600);

  xTaskCreate(Task_
}

void loop() {

  //Don't put code right here (we're working with RTOS)
  
}
 
