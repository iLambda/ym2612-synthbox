#include "../inc/input.h"

void input_update() {
  // save old input state
  oldinputstate = inputstate;
  /* construct inputstate
    B0-1 is scroll rotary encoder
    B2-3 is value rotary encoder
    B4 is fwd button
    B5 is bck button
  */
  inputstate = (PORTB & 0x03) | ((PORTC & 0x30) >> 2) | ((PORTC & 0x80) >> 3);
}

uint8_t input_getstate() {
  // return new state
  return inputstate;
}

uint8_t input_getoldstate() {
  // return old input state
  return oldinputstate;
}

uint8_t input_getscrollknob() {
  // return 1 or -1 if scroll, 0 if not.
  return (oldinputstate & INPUT_SCROLL) && !(inputstate & INPUT_SCROLL) 
          ? (inputstate & INPUT_SCROLL_DIR ? 1 : -1) : 0;
}
uint8_t input_getvalueknob() {
  return (oldinputstate & INPUT_VALUE) && !(inputstate & INPUT_VALUE) 
          ? (inputstate & INPUT_VALUE_DIR ? 1 : -1) : 0;
}