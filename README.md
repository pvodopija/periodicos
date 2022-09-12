# periodicOS
Modified [freeRTOS](https://github.com/pvodopija/periodicos/blob/master/FreeRTOS/src/FreeRTOSConfig.h) kernel for Arduino now supports periodic tasks and EDF scheduling. <br/>To enable this feature  ```#define configPERIODIC_EDF_SCHEDULER``` in the 
[config](FreeRTOS/src/FreeRTOSConfig.h) and the preprocessor will generate necessary code in the kernel. This is fork is for **educational purposes only**.
