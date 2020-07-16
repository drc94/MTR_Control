#include "Display.h"

void displayInit(){
    // initialize serm  ial communication at 9600 bits per second:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
}

void TaskPrint(void *pvParameters)  // This is a task.
{
  dataPackageVESC_t TaskVESC_Values = *(dataPackageVESC_t *) pvParameters;
  for (;;) // A Task shall never return or exit.
  {
    Serial.print(TaskVESC_Values.rpm);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.avgInputCurrent);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.avgMotorCurrent);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.dutyCycleNow);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.tachometer);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.inpVoltage);
    Serial.print(", ");
    Serial.print(TaskVESC_Values.ampHours);
    Serial.print(", ");
    Serial.println(TaskVESC_Values.ampHoursCharged);
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}
