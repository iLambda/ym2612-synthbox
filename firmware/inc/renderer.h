#ifndef YM2612_SYNTHBOX_RENDERER_H
#define YM2612_SYNTHBOX_RENDERER_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "menuitem.h"

#define DISPLAY_DEPTH

const int8_t chrtable[5][8] = 
{
  {17,18,20,10,21,1,2,7},
  {0,0,3,31,3,0,0,0},
  {0,4,6,31,6,4,0,0},
  {0,0,14,16,12,17,14,0},
  {4,4,31,4,4,0,31,0}
};

static uint8_t dirty = 1;
static uint8_t i = 0, j = 0;
static uint8_t depth = 0;
static uint8_t valuestr[16];
static ym2612menuitem_t* rendered;

void renderer_init();
void renderer_draw();

void renderer_dirty();
uint8_t renderer_isdirty();

#endif
