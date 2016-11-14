#ifndef YM2612_SYNTHBOX_INPUT_H
#define YM2612_SYNTHBOX_INPUT_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>

#define INPUT_SCROLL       0x01
#define INPUT_SCROLL_DIR   0x02
#define INPUT_VALUE        0x04
#define INPUT_VALUE_DIR    0x08

static uint8_t oldinputstate = 0x00;
static uint8_t inputstate = 0x00;

void input_update();
uint8_t input_getstate();
uint8_t input_getoldstate();

uint8_t input_getscrollknob();
uint8_t input_getvalueknob();

#endif
