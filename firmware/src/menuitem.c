#include "menuitem.h"

void menuitem_makechild(ym2612menuitem_t* parent, ym2612menuitem_t* child) {
  // Check if kid
  if (parent->child) {
    menuitem_makesibling(parent->child, child);
  } else {
    parent->child = child;
    child->parent = parent;
  }
}

void menuitem_makesibling(ym2612menuitem_t* base, ym2612menuitem_t* sibling) {
  // Search last sibling
  while (base->nextSibling) { base = base->nextSibling; }
  // Bind
  base->nextSibling = sibling;
  sibling->prevSibling = base;
}


unsigned char menuitem_range_detune(unsigned char value) {
  return ((char)value) >= 3 ? 3 : (((char)value) <= -3 ? ((unsigned char)-3) : value);
}

unsigned char menuitem_range_8(unsigned char value) {
  return value % 8;
}

unsigned char menuitem_range_16(unsigned char value) {
  return value % 16;
}

unsigned char menuitem_range_32(unsigned char value) {
  return value % 32;
}

unsigned char menuitem_range_64(unsigned char value) {
  return value % 64;
}

unsigned char menuitem_range_128(unsigned char value) {
  return value % 128;
}

void menuitem_display_detune(unsigned char value, char* out) {
  if(value != 0) {
    strcpy(out, "x1  \x03");
    out[2] = value > 128 ? '-' : '+';
    out[3] = 0x30 + (value > 128 ? -value : value);
  } else {
    strcpy(out, "x1");
  }
}

void menuitem_display_mul(unsigned char value, char* out) {
  ByteToStr(value, out);
  if (value == 0) {
    strcpy(out, "x\01");
  } else {
    out[value < 10 ? 1 : 0] = 'x';
  }
}
