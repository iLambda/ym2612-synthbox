#include "menuitem.h"

#ifndef YM2612_SYNTHBOX_MENUITEMS_H
#define YM2612_SYNTHBOX_MENUITEMS_H

ym2612menuitem_t item_ch1 = { "DT1", -1, &menuitem_range_detune, &menuitem_display_detune, 0, 0, 0, 0 };
ym2612menuitem_t item_ch2 = { "MUL", 0, &menuitem_range_16, &menuitem_display_mul, 0, 0, 0, 0 };
ym2612menuitem_t item_ch3 = { "TL", 0, 0, 0, 0, 0, 0, 0  };
ym2612menuitem_t item_ch4 = { "RR", 0, 0, 0, 0, 0, 0, 0 };
ym2612menuitem_t item_ch5 = { "DM1", 0, 0, 0, 0, 0, 0, 0 };

void menu_load() {
  // Tying tree
  menuitem_makesibling(&item_ch1, &item_ch2);
  menuitem_makesibling(&item_ch2, &item_ch3);
  menuitem_makesibling(&item_ch3, &item_ch4);
  menuitem_makesibling(&item_ch4, &item_ch5);
}

#endif
