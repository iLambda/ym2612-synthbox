#include "menuitem.h"

#ifndef YM2612_SYNTHBOX_MENUITEMS_H
#define YM2612_SYNTHBOX_MENUITEMS_H

ym2612menuitem_t item_ch1 = { "CH1", 0, &menuitem_range_empty, 0, 0, 0, 0 };
ym2612menuitem_t item_ch2 = { "CH2", 0, &menuitem_range_empty, 0, 0, 0, 0 };
ym2612menuitem_t item_ch3 = { "CH3", 0, &menuitem_range_empty, 0, 0, 0, 0  };
ym2612menuitem_t item_ch4 = { "CH4", 0, &menuitem_range_empty, 0, 0, 0, 0 };
ym2612menuitem_t item_ch5 = { "CH5", 0, &menuitem_range_empty, 0, 0, 0, 0 };

void menu_load() {
  menuitem_makesibling(&item_ch1, &item_ch2);
  menuitem_makesibling(&item_ch2, &item_ch3);
  menuitem_makesibling(&item_ch3, &item_ch4);
  menuitem_makesibling(&item_ch4, &item_ch5);
}

#endif
