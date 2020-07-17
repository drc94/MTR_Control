/** Todo lo relacionado con el VESC **/
#include "VESC.h"

void VESC_setCurrent(float current){
  UART.setCurrent(current);
}

void VESC_setBrakeCurrent(float current){
  UART.setBrakeCurrent(current);
}

void VESC_setHandBrakeCurrent(float current){
  UART.setHandBrakeCurrent(current);
}

void VESC_control(){
  vTaskDelay(200/portTICK_PERIOD_MS); //200ms
}
