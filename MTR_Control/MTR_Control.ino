#include "Display.hpp"
#define DEBUG

void setup() {
  timerInit();
  #ifdef DEBUG
  displayInit();
  #endif
  VESCInit(&VESC_Values, &STATE);
}

void loop()
{
  #ifdef DEBUG
  TaskPrint(&VESC_Values, &STATE);
  #endif
  TaskGetValues(&VESC_Values);
  TaskVESC_Control(&VESC_Values, &STATE, &TIMER_REF);
  delay(50);
}
