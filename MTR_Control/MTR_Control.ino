#include <Arduino_FreeRTOS.h>
#include "VESC.h"

TaskHandle_t Task_Handle_printValues;

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(9600);

  xTaskCreate(VESC_PrintValues, "Task_PrintValues", 100, NULL, 1, &Task_Handle_printValues);
}

void loop() {

  //Don't put code right here (we're working with RTOS)
  
}
 
