/*
 * JKLCDLog.h
 *
 *  Created on: 13. 11. 2020
 *      Author: KlokockaJir
 */

#ifndef INC_JKLCDLOG_H_
#define INC_JKLCDLOG_H_


#include "main.h"

void JKLCDLog_Init(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t bcolor, uint16_t fcolor);
void JKLCDLog_SetColors(uint16_t fcolor,uint16_t bcolor);
void JKLCDLog_SetFColor(uint16_t fcolor);
void JKLCDLog_SetBColor(uint16_t bcolor);
void JKLCDLog_LogToLCD(char* buff );


#endif /* INC_JKLCDLOG_H_ */
