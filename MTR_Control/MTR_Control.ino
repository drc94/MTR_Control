<<<<<<< HEAD
#include "Display.h"
=======
#include "VESC.h"
>>>>>>> origin/hand_brake_function

void setup() {
  displayInit();

  VESCInit(&VESC_Values);

<<<<<<< HEAD
// Now set tasks to run independently.
  xTaskCreate(
    &TaskPrint
    ,  "Print"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    &TaskGetValues
    ,  "GetValues"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
//vTaskStartScheduler();
=======
>>>>>>> origin/hand_brake_function
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
