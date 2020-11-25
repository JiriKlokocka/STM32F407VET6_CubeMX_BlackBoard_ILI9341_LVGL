#ifndef XPT2046_TOUCH_H_
#define XPT2046_TOUCH_H_

#include "main.h"
#include <stdbool.h>

#define XPT2046_SPI_PORT hspi2
extern SPI_HandleTypeDef XPT2046_SPI_PORT;

#define XPT2046_IRQ_Pin       T_PEN_Pin
#define XPT2046_IRQ_GPIO_Port T_PEN_GPIO_Port
#define XPT2046_CS_Pin        T_CS_Pin
#define XPT2046_CS_GPIO_Port  T_CS_GPIO_Port

// change depending on screen orientation
#define XPT2046_SCALE_X 320  
#define XPT2046_SCALE_Y 240 

#define XPT2046_MIN_RAW_X 1500   
#define XPT2046_MAX_RAW_X 31000  
#define XPT2046_MIN_RAW_Y 3276  
#define XPT2046_MAX_RAW_Y 30110  

// call before initializing any SPI devices
bool XPT2046_TouchPressed();
bool XPT2046_TouchGetCoordinates(uint16_t* x, uint16_t* y);

#endif 