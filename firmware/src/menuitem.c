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


ym2612ranged_t menuitem_range_empty(int value) {
  ym2612ranged_t range = { 0, 0, 0 };
  return range;
}

ym2612ranged_t menuitem_range_0_32(int value) {
  ym2612ranged_t range = { 0, 32, 0 };
  range.value = value % 32;
  return range;
}

ym2612ranged_t menuitem_range_0_127(int value) {
  ym2612ranged_t range = { 0, 127, 0 };
  range.value = value % 127;
  return range;
}
