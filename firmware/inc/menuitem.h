#ifndef YM2612_SYNTHBOX_MENUITEM_H
#define YM2612_SYNTHBOX_MENUITEM_H

typedef struct {
  unsigned char min;
  unsigned char max;
  unsigned char value;
} ym2612ranged_t;

typedef struct ym2612menuitem{
  char* text;
  unsigned char value;
  ym2612ranged_t (*compute)(unsigned char);

  struct ym2612menuitem* child;
  struct ym2612menuitem* parent;
  struct ym2612menuitem* nextSibling;
  struct ym2612menuitem* prevSibling;
} ym2612menuitem_t;


void menuitem_makechild(ym2612menuitem_t* parent, ym2612menuitem_t* child);
void menuitem_makesibling(ym2612menuitem_t* base, ym2612menuitem_t* sibling);

ym2612ranged_t menuitem_range_empty(unsigned char value);
ym2612ranged_t menuitem_range_0_32(unsigned char value);
ym2612ranged_t menuitem_range_0_127(unsigned char value);

#endif
