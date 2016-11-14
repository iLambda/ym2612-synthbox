#ifndef YM2612_SYNTHBOX_LCD_H
#define YM2612_SYNTHBOX_LCD_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>
#include <delays.h>

#define XLCD_CMD_CLEAR         0x01
#define XLCD_CMD_HOME          0x02
#define XLCD_CMD_CUSTOMCHAR(i) (0x40 + i*0x08)
#define XLCD_CMD_CURSOR_OFF    0x0D

void lcd_init();
void lcd_clear();
void lcd_setchar(uint8_t id, const uint8_t* chr);
void lcd_goto(uint8_t row, uint8_t col);
void lcd_put(uint8_t row, uint8_t col, const uint8_t* text);
void lcd_putc(uint8_t row, uint8_t col, uint8_t chr);

#endif
