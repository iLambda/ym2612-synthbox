#ifndef YM2612_SYNTHBOX_MENU_H
#define YM2612_SYNTHBOX_MENU_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>

#include "../inc/menuitem.h"

void menu_init(ym2612menuitem_t* pRoot);
void menu_current_value(uint8_t* out);

ym2612menuitem_t* menu_root();
ym2612menuitem_t* menu_current();
uint8_t menu_depth();

ym2612menuitem_t* menu_next();
ym2612menuitem_t* menu_previous();
ym2612menuitem_t* menu_back();
ym2612menuitem_t* menu_forward();

ym2612menuitem_t* menu_gonext();
ym2612menuitem_t* menu_goprevious();
ym2612menuitem_t* menu_goback();
ym2612menuitem_t* menu_goforward();

#endif
