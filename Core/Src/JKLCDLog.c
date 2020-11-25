/*
 * JKLCDLog.c
 *
 *  Created on: 13. 11. 2020
 *      Author: KlokockaJir
 */
#include "ili9341.h"

#define LCD_LOG_WIDTH (ILI9341_PIXEL_WIDTH / 2)
#define LCD_LOG_HEIGHT ILI9341_PIXEL_HEIGHT / 2

extern lcdFontPropTypeDef lcdFont;


uint16_t LCD_HEIGHT = ILI9341_PIXEL_HEIGHT;
uint16_t LCD_WIDTH	 = ILI9341_PIXEL_WIDTH;

uint16_t JKLCDLog_FCOLOR = COLOR_WHITE;
uint16_t JKLCDLog_BCOLOR = ASSEMBLE_RGB(30,30,50);
uint16_t JKLCDLog_FONTNR = 0; //0-2

uint16_t JKLCDLog_Width = LCD_LOG_WIDTH;
uint16_t JKLCDLog_Height = LCD_LOG_HEIGHT;

uint16_t JKLCDLog_Posx = (ILI9341_PIXEL_WIDTH - LCD_LOG_WIDTH)/2;
uint16_t JKLCDLog_Posy = (ILI9341_PIXEL_WIDTH - LCD_LOG_HEIGHT)/2;



void JKLCDLog_Init(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t bcolor, uint16_t fcolor){

	//Vychazet z okraje a modulo urcit sirku a vysku


	JKLCDLog_FCOLOR=fcolor;
	JKLCDLog_BCOLOR=bcolor;
	JKLCDLog_Posx = x+5;
	JKLCDLog_Posy = y+5;

	if((x+width)>LCD_WIDTH) {
		width = width - (((x+width)-LCD_WIDTH));
	}
	JKLCDLog_Width = width;
	JKLCDLog_Width-=10;

	if((y+height)>LCD_HEIGHT) {
		height = height - ((y+height)-LCD_HEIGHT);
	}
	JKLCDLog_Height = height;
	JKLCDLog_Height-=10;
}

void JKLCDLog_SetColors(uint16_t fcolor,uint16_t bcolor){
	JKLCDLog_FCOLOR=fcolor;
	JKLCDLog_BCOLOR=bcolor;
}

void JKLCDLog_SetFColor(uint16_t fcolor){
	JKLCDLog_FCOLOR=fcolor;
}

void JKLCDLog_SetBColor(uint16_t bcolor){
	JKLCDLog_BCOLOR=bcolor;
}




void JKLCDLog_LogToLCD(char* buff ) {

	static uint16_t xindex = 0;//JKLCDLog_Posx
	static uint16_t yindex = 0;//JKLCDLog_Posy;
	//FontDef fonts[] = {Font_7x10,Font_11x18, Font_16x26};

	//lcdFont.pFont = &Font16;

	uint16_t i = 0;

	bool specCharFlag = 0;

	while(*buff) {

		if(buff[i] == '\r' || buff[i] == '\n') {
			specCharFlag = 1;
		}


		if( (xindex > ((JKLCDLog_Width/lcdFont.pFont->Width) -1   )) || specCharFlag == 1) {
			xindex=0;
			if(yindex >= (((JKLCDLog_Height)/lcdFont.pFont->Height) -1  )) {
				yindex = 0;
			} else {
				yindex++;
			}
			//ILI9341_Draw_Rectangle(xindex + JKLCDLog_Posx, (yindex*lcdFont.pFont->Height) + JKLCDLog_Posy, JKLCDLog_Width, lcdFont.pFont->Height, JKLCDLog_BCOLOR);
			lcdFillRect(xindex + JKLCDLog_Posx, (yindex*lcdFont.pFont->Height) + JKLCDLog_Posy, JKLCDLog_Width, lcdFont.pFont->Height, JKLCDLog_BCOLOR);
		}


		if(!specCharFlag) {

			//ILI9341_WriteChar(xindex*lcdFont.pFont->Width + JKLCDLog_Posx, (yindex*lcdFont.pFont->Height) + JKLCDLog_Posy , *buff, &Font16, JKLCDLog_FCOLOR, JKLCDLog_BCOLOR);
			lcdDrawChar(xindex*lcdFont.pFont->Width + JKLCDLog_Posx, (yindex*lcdFont.pFont->Height) + JKLCDLog_Posy, *buff, JKLCDLog_FCOLOR, JKLCDLog_BCOLOR);
			specCharFlag = 0;
			xindex++;
		}

		buff++;
	}

}
