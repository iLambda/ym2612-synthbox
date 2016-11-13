#include "menu.h"
#include "menuitems.h"

#define DISPLAY_DEPTH 1

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

const char chr_oneandhalf[] = {17,18,20,10,21,1,2,7};
const char chr_separator[] = {0,0,3,31,3,0,0,0};
const char chr_selector[] = {0,4,6,31,6,4,0,0};
const char chr_epsilon[] = {0,0,14,16,12,17,14,0};
const char chr_plusorminus[] = {4,4,31,4,4,0,31,0};

char valuestr[16];
unsigned char i = 0;
unsigned char j = 0;
unsigned char dirty = 0;
unsigned char depth = 0;
ym2612menuitem_t* rendered = 0;

unsigned char input = 1;
unsigned char oldinputstate = 0x00;
unsigned char inputstate = 0x00;

unsigned char midimap[6] = {1, 1, 1, 1, 1, 1};

int main(void) {
  // All input digital
  ADCON1 = 0x0F;
  CCP1CON = 0x00;
  CMCON = 0x07;
  CVRCON = 0;
  SPPCON = 0;
  UCON = 0;
  UCFG = 0x08;
  // Setting up I/O
  TRISB = 0x03;
  TRISC = 0xB0;
  // Reset I/O
  PORTB = 0x00;
  PORTC = 0x00;

  // Init LCD library
  Lcd_Init();
  // Clear screen
  Lcd_Cmd(_LCD_CLEAR);
  // Cursor off
  Lcd_Cmd(_LCD_CURSOR_OFF);
  // Adding custom character selector
  Lcd_Cmd(64);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(chr_selector[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
  // Adding custom character 1/2
  Lcd_Cmd(72);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(chr_oneandhalf[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
  // Adding custom character separator
  Lcd_Cmd(80);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(chr_separator[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
  // Adding custom character epsilon
  Lcd_Cmd(88);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(chr_epsilon[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);
  // Adding custom character +or-
  Lcd_Cmd(96);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(chr_plusorminus[i]);
  Lcd_Cmd(_LCD_RETURN_HOME);

  // Load menu from memory
  menu_load();
  // Init menu
  menu_init(&item_lfo);

  // First draw
  dirty = 1;

  // Program loop
  while(1) {
    // If input is allowed
    if (input) {
      // save inputstate
      oldinputstate = inputstate;
      /* construct inputstate
          B0-1 is scroll rotary encoder
          B2-3 is value rotary encoder
          B4 is fwd button
          B5 is bck button
      */
      inputstate = (PORTB & 0x03) | ((PORTC & 0x30) >> 2) | ((PORTC & 0x80) >> 3);
      // check for scrolling
      if (!(inputstate & 0x01) && (oldinputstate & 0x01)) {
        // scroll
        if (!(inputstate & 0x02)) {
          // up
          menu_goprevious();
        } else {
          // down
          menu_gonext();
        }
        // redraw needed
        dirty = 1;
      }

      // check for value editing
      if (!(inputstate & 0x04) && (oldinputstate & 0x04)) {
        // edit current value
        rendered = menu_current();
        // if value can be edited
        if (rendered->compute) {
          rendered->value = rendered->compute(rendered->value + (inputstate & 0x08 ? -1 : 1));
          // redraw needed
          dirty = 1;
        }
      }

      // check for forward btn pressed
      if ((inputstate & 0x10) && !(oldinputstate & 0x10)) {
        // if we're on chan selection, load channel
        if (menu_current() == &item_ch) {
          menu_loadchannel();
        }
        // if we're on op selection, load operator
        if (menu_current() == &item_ch_op) {
          menu_loadoperator();
        }

        // go fwd
        menu_goforward();
        // redraw needed
        dirty = 1;
      }
    }

    // If redraw is needed
    if (dirty) {
      // Cursor off
      Lcd_Cmd(_LCD_CLEAR);
      // Compute depth
      depth = DISPLAY_DEPTH ? menu_depth() : 0;
      // Draw items on screen
      i = 0, rendered = menu_current();
      while (rendered && i < 2) {
        // Draw text
        Lcd_Out(1+i, depth + 1 + ((!i?1:0) * (!depth)), rendered->text);
        // Draw value
        if (rendered->display) {
          // Value to str
          rendered->display(rendered->value, valuestr);
          // Draw
          Lcd_Out(1+i, 17 - strlen(valuestr), valuestr);
        }
        // Render depth
        if (DISPLAY_DEPTH) {
          j = 1;
          while (j++ <= depth) {
            Lcd_Chr(1+i, j, 0x02);
          }
        }
        // Render next
        rendered = rendered->nextSibling;
        i++;
      }
      // Draw arrow
      Lcd_Chr(1, !depth + depth, 0);
      // Undirty, redraw done
      dirty = 0;
    }
  }

  // Return
  return 0;
}
