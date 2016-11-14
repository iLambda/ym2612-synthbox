#include "../inc/lcd.h"
#include "../inc/xtal.h"

#include <xlcd.h>
#include <delays.h>

void lcd_init(){ 
  // Open XLCD
  OpenXLCD(FOUR_BIT & LINES_5X7);
  // Wait
  __delay_us(100);
  // Setup
  WriteCmdXLCD(XLCD_CMD_CLEAR);
  WriteCmdXLCD(XLCD_CMD_CURSOR_OFF);
}

void lcd_clear() {
  // Clear
  WriteCmdXLCD(XLCD_CMD_CLEAR);
}

void lcd_goto(uint8_t row, uint8_t col) {
  // Set pos
  SetDDRamAddr((row * 0x40) + (col < 0x28 ? col : 0x27));
}

void lcd_put(uint8_t row, uint8_t col, const uint8_t* text){ 
  // Goto 
  lcd_goto(row, col);
  // draw text
  putrsXLCD(text);
}

void lcd_putc(uint8_t row, uint8_t col, uint8_t chr){ 
  // Goto
  lcd_goto(row,col);
  // write char
  WriteDataXLCD(chr);
}

void lcd_setchar(uint8_t id, const uint8_t* chr) {
  unsigned char i = 0, addr = XLCD_CMD_CUSTOMCHAR(id);
  for(i=0; i<8; i++) {
    // Send customchar command
    WriteCmdXLCD(addr + i);
    // Write data chunk
    WriteDataXLCD(chr[i]);
  }
  // Return home
  WriteCmdXLCD(XLCD_CMD_HOME);
}

void DelayPORXLCD() {
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
  __delay_ms(1);
}

void DelayFor18TCY() {
  Delay10TCYx(0x2);
}