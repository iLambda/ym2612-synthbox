#include "../inc/config.h"
#include "../inc/xtal.h"
#include "../inc/eeprom.h"

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>

#include "../inc/renderer.h"
#include "../inc/input.h"
#include "../inc/menu.h"
#include "../inc/menuitem.h"
#include "../inc/menutree.h"

uint8_t midimap[6] = {0, 0, 0, 0, 0, 0};
ym2612menuitem_t* node = 0; 

void main(void) {
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
  
  // Init renderer
  renderer_init();
  // Load menu from memory
  menu_load();
  // Init menu
  menu_init(&item_lfo);

  // Program loop
  while(1) {
    // update input
//  input_update();
    // check scrolling
    if (input_getscrollknob()) {
      // scroll
      if (input_getscrollknob() > 0) {
        menu_goprevious();
      } else {
        menu_gonext();
      }
      // schedule redraw
      renderer_dirty();
    }
    // check value scrolling
    if (input_getvalueknob()) {
      if (node->modulus) {
        node->value = ((unsigned char)(node->value + input_getvalueknob())) % node->modulus;
        // schedule redraw
        renderer_dirty();
      }
    }
    
    // render ui
    renderer_draw();
  }
  
  return;
}
