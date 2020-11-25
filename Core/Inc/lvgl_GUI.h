/*
 * lvgl_GUI.h
 *
 *  Created on: Nov 19, 2020
 *      Author: KlokockaJir
 */

#ifndef INC_LVGL_GUI_H_
#define INC_LVGL_GUI_H_

#ifdef __cplusplus
extern "C" {
#endif

void lvgl_GUI(void);


void LCD_UpdateTime(uint8_t hrs, uint8_t mnts, uint8_t scnds);
void LCD_UpdateDate(uint8_t wd, uint8_t dy, uint8_t mnth, uint16_t yr);

#ifdef __cplusplus
}
#endif

#endif /* INC_LVGL_GUI_H_ */
