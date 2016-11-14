#include "../inc/menu.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

ym2612menuitem_t* menu_mroot;
ym2612menuitem_t* menu_mcurrent;

void menu_init(ym2612menuitem_t* proot) {
  // save root
  menu_mroot = proot;
  // start at root
  menu_mcurrent = menu_mroot;
}

uint8_t menu_depth() {
  uint8_t i = 0;
  ym2612menuitem_t* itr = 0;
  itr = menu_mcurrent;
  while (itr) {
    while (itr->prevSibling) {
      itr = itr->prevSibling;
    }
    itr = itr->parent;
    i++;
  }
  return i-1;
}

ym2612menuitem_t* menu_next() {
  return menu_mcurrent->nextSibling;
}

ym2612menuitem_t* menu_previous() {
  return menu_mcurrent->prevSibling;
}

ym2612menuitem_t* menu_back() {
  ym2612menuitem_t* tmp = menu_mcurrent;
  while(tmp->prevSibling) { tmp = tmp->prevSibling; }
  return tmp->parent;
}

ym2612menuitem_t* menu_forward() {
  return menu_mcurrent->child;
}


ym2612menuitem_t* menu_gonext() {
  if (menu_mcurrent->nextSibling) {
    return menu_mcurrent = menu_mcurrent->nextSibling;
  }
  return NULL;
}

ym2612menuitem_t* menu_goprevious() {
  if (menu_mcurrent->prevSibling) {
    return menu_mcurrent = menu_mcurrent->prevSibling;
  }
  return NULL;
}

ym2612menuitem_t* menu_goback() {
  ym2612menuitem_t* tmp = menu_mcurrent;
  while(tmp->prevSibling) { tmp = tmp->prevSibling; }
  if (tmp->parent) {
    return menu_mcurrent = tmp->parent;
  }
  return NULL;
}

ym2612menuitem_t* menu_goforward() {
  if (menu_mcurrent->child) {
    return menu_mcurrent = menu_mcurrent->child;
  }
  return NULL;
}



ym2612menuitem_t* menu_root() {
  return menu_mroot;
}

ym2612menuitem_t* menu_current() {
  return menu_mcurrent;
}
