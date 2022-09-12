#include <Arduino_FreeRTOS.h>


void vTestTask(void* pxParams){
  Serial.print(F("task1 "));
  Serial.print(xTaskGetTickCount());
  Serial.print(F("\n"));

  for(int i=0; i<1000; i++);
  
  vTaskDelete(NULL);
}

void vTestTask2(void* pxParams){
  Serial.print(F("task2 "));
  Serial.print(xTaskGetTickCount());
  Serial.print(F("\n"));
    
  for(int i=0; i<1000; i++);

  vTaskDelay(120);
  
  vTaskDelete(NULL);
}

void vTestTask3(void* pxParams){
  Serial.print(F("task3 "));
  Serial.print(xTaskGetTickCount());
  Serial.print(F("\n"));

  for(int i=0; i<1000; i++);
  
  vTaskDelete(NULL);
}

void vConsoleTask(void* pxParams){
  if(Serial.available() > 0){
    char a = Serial.read();
    if(a == '1'){
      xTaskCreatePeriodic(vTestTask, "task1", configMINIMAL_STACK_SIZE, NULL, 500, 5, NULL);
    }else if(a == '2'){
      xTaskCreatePeriodic(vTestTask2, "task2", configMINIMAL_STACK_SIZE, NULL, 50, 51, NULL);
    }else if(a == '3'){
      xTaskCreatePeriodic(vTestTask3, "task3", configMINIMAL_STACK_SIZE, NULL, 700, 5, NULL);
    }
  }

  
  Serial.print(F("<CONSOLE> "));
  Serial.print(xTaskGetTickCount());
  Serial.print(F("\n"));
  
  vTaskDelete(NULL);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT); /* initialize digital pin LED_BUILTIN as an output. */

  
// xTaskCreatePeriodic(vTestTask, "", configMINIMAL_STACK_SIZE, NULL, 500, 5, NULL);
//  xTaskCreatePeriodic(vTestTask2, "", configMINIMAL_STACK_SIZE, NULL, 50, 5, NULL);
//  xTaskCreatePeriodic(vTestTask3, "", configMINIMAL_STACK_SIZE, NULL, 700, 5, NULL);
  
  vTaskStartScheduler();
  
}

/* this is init (idle) task in freeRTOS */
void loop() {
  //Serial.print(F("."));
}
