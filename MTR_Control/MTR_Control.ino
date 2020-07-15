#include "VESC.h"

TaskHandle_t Task_Handle_printValues;
TaskHandle_t Task_Handle_getValues;
TaskHandle_t Task_Handle_control;

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(9600);

  VESC_Init();

  xTaskCreate(VESC_printValues, "Task_printValues", 100, NULL, 1, &Task_Handle_printValues);
  xTaskCreate(VESC_getValues, "Task_getValues", 100, NULL, 2, &Task_Handle_getValues);
  xTaskCreate(VESC_control, "Task_control", 100, NULL, 2, &Task_Handle_control);
}

void loop() {
  //Don't put code right here (we're working with RTOS)
}
 
