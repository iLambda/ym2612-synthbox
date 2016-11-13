#ifndef YM2612_SYNTHBOX_MENUITEM_H
#define YM2612_SYNTHBOX_MENUITEM_H

typedef struct ym2612menuitem{
  char* text;
  unsigned char value;

  unsigned char (*compute)(unsigned char);
  void (*display)(unsigned char, char*);

  struct ym2612menuitem* child;
  struct ym2612menuitem* parent;
  struct ym2612menuitem* nextSibling;
  struct ym2612menuitem* prevSibling;
} ym2612menuitem_t;

unsigned char menuitem_range_2(unsigned char value);
unsigned char menuitem_range_4(unsigned char value);
unsigned char menuitem_range_6(unsigned char value);
unsigned char menuitem_range_8(unsigned char value);
unsigned char menuitem_range_16(unsigned char value);
unsigned char menuitem_range_32(unsigned char value);
unsigned char menuitem_range_64(unsigned char value);
unsigned char menuitem_range_128(unsigned char value);
unsigned char menuitem_range_detune(unsigned char value);
unsigned char menuitem_range_lfo(unsigned char value);

void menuitem_display_algo(unsigned char value, char* out);
void menuitem_display_ams(unsigned char value, char* out);
void menuitem_display_fms(unsigned char value, char* out);
void menuitem_display_bool(unsigned char value, char* out);
void menuitem_display_detune(unsigned char value, char* out);
void menuitem_display_lfo(unsigned char value, char* out);
void menuitem_display_mul(unsigned char value, char* out);
void menuitem_display_rs(unsigned char value, char* out);
void menuitem_display_byteplusone(unsigned char value, char* out);

#endif
