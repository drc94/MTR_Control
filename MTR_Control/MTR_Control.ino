#include "Display.h"

void setup() {
  displayInit();

  VESCInit(&VESC_Values);
}

void loop()
{
  TaskPrint(&VESC_Values);
  TaskGetValues(&VESC_Values);
  TaskVESC_Control(&VESC_Values, &STATE);
  delay(100);
}
