#ifndef YM2612_SYNTHBOX_MENUITEM_H
#define YM2612_SYNTHBOX_MENUITEM_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct ym2612menuitem{
  const uint8_t* text;
  uint8_t value;
  uint8_t modulus;
  
  void (*display)(uint8_t, uint8_t*);
  void (*gonefwd)(void);
  void (*frombwd)(void);

  struct ym2612menuitem* child;
  struct ym2612menuitem* parent;
  struct ym2612menuitem* nextSibling;
  struct ym2612menuitem* prevSibling;
} ym2612menuitem_t;

void menuitem_display_algo(uint8_t value, uint8_t* out);
void menuitem_display_ams(uint8_t value, uint8_t* out);
void menuitem_display_fms(uint8_t value, uint8_t* out);
void menuitem_display_bool(uint8_t value, uint8_t* out);
void menuitem_display_detune(uint8_t value, uint8_t* out);
void menuitem_display_lfo(uint8_t value, uint8_t* out);
void menuitem_display_mul(uint8_t value, uint8_t* out);
void menuitem_display_rs(uint8_t value, uint8_t* out);
void menuitem_display_byteplusone(uint8_t value, uint8_t* out);
void menuitem_display_byte(uint8_t value, uint8_t* out);

#endif
