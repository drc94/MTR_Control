/** Todo lo relacionado con el VESC **/
#include <VescUart.h>
#include <SoftwareSerial.h>
#include <Arduino_FreeRTOS.h>

void VESC_Init();
void VESC_PrintValues(void *param);
void VESC_GetValues(void *param);
void VESC_SetCurrent(float current);
void VESC_SetBrakeCurrent(float current);
void VESC_SetHandBrake(float current);
void VESC_Control(void *param);

TaskHandle_t Task_Handle_PrintValues;
TaskHandle_t Task_Handle_Control;
