/*
 * lvgl_init_f407.h
 *
 *  Created on: Nov 15, 2020
 *      Author: KlokockaJir
 */

#ifndef LVGL_INIT_F407_H_
#define LVGL_INIT_F407_H_

#ifdef __cplusplus
extern "C" {
#endif


/*#include <stdint.h>
#include "lvgl/src/lv_misc/lv_color.h"
#include "lvgl/src/lv_misc/lv_area.h"*/

/*********************
 *      DEFINES
 *********************/

#define TFT_EXT_FB		0		/*Frame buffer is located into an external SDRAM*/
#define TFT_USE_GPU		0		/*Enable hardware accelerator*/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_lcd_init(void);
void lv_touchpad_init(void);

#ifdef __cplusplus
}
#endif

#endif /* LVGL_INIT_F407_H_ */
