#include "menu.h"
#include "menuitems.h"

sbit LCD_EN at RB2_bit;
sbit LCD_RS at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_EN_Direction at TRISB2_bit;
sbit LCD_RS_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

unsigned char dirty = 0;
char out[] = "aaaaaaaa";

int main(void) {
  // All input digital
  ADCON1 = 0x0F;
  CCP1CON = 0x00;
  CMCON = 0x07;
  CVRCON = 0;
  SPPCON = 0;
  UCON = 0;
  UCFG = 0x08;
  // Set all PORTB as outputs and reset
  TRISB = 0x00;
  PORTB = 0x02;

  // Init LCD library
  Lcd_Init();
  // Clear screen
  Lcd_Cmd(_LCD_CLEAR);
  // Cursor off
  Lcd_Cmd(_LCD_CURSOR_OFF);

  // Load menu from memory
  menu_load();
  // Init menu
  menu_init(&item_ch1);

  // First draw
  dirty = 1;

  // Program loop
  while(1) {
    // If redraw is needed
    if (dirty) {
      // Cursor off
      Lcd_Cmd(_LCD_CLEAR);
      // Draw text
      Lcd_Chr(1, 1, 0x7E);
      Lcd_Out(1, 2, menu_current()->text);
      // Draw next if exists
      if (menu_next()) {
        Lcd_Out(2, 1, menu_next()->text);
      }
      // Undirty, redraw done
      dirty = 0;
    }

  }

  // Return
  return 0;
}
