#include "Display.h"

void setup() {
  displayInit();

  VESCInit(&VESC_Values);
}

void loop()
{
  TaskPrint(&VESC_Values);
  TaskGetValues(&VESC_Values);
  VESC_setCurrent(2);
  delay(100);
}
