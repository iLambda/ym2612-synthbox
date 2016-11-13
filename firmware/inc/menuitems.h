#include "menuitem.h"

#ifndef YM2612_SYNTHBOX_MENUITEMS_H
#define YM2612_SYNTHBOX_MENUITEMS_H

#define MAKESIBLING(b, s) b->nextSibling = s; s->prevSibling = b;
#define MAKEPARENT(p, c) p->child = c; c->parent = p;

ym2612menuitem_t item_lfo = { "LFO", 0, &menuitem_range_lfo, &menuitem_display_lfo, 0, 0, 0, 0 };
ym2612menuitem_t item_ch36 = { "CH36", 0, &menuitem_range_2, &menuitem_display_bool, 0, 0, 0, 0 };

ym2612menuitem_t item_ch = { "CHANNEL", 0, &menuitem_range_6, &menuitem_display_byteplusone, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_algo = { "ALGO", 0, &menuitem_range_8, &menuitem_display_algo, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_feedback = { "FEEDBACK", 0, &menuitem_range_8, &ByteToStr, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_ams = { "AMS", 0, &menuitem_range_4, &menuitem_display_ams, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_fms = { "FMS", 0, &menuitem_range_8, &menuitem_display_fms, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_op = { "OPERATOR", 0, &menuitem_range_4, &menuitem_display_byteplusone, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_dt1 = { "DT1", 0, &menuitem_range_detune, &menuitem_display_detune, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_mul = { "MUL", 0, &menuitem_range_16, &menuitem_display_mul, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_am = { "AM", 0, &menuitem_range_2, &menuitem_display_bool, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_tl = { "TL", 0, &menuitem_range_128, &ByteToStr, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_rs = { "RS", 0, &menuitem_range_4, &menuitem_display_rs, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_ar = { "AR", 0, &menuitem_range_32, &ByteToStr, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d1r = { "D1R", 0, &menuitem_range_32, &ByteToStr, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d2r = { "D2R", 0, &menuitem_range_32, &ByteToStr, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d1l = { "D1L", 0, &menuitem_range_16, &ByteToStr, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_rr = { "RR", 0, &menuitem_range_16, &ByteToStr, 0, 0, 0, 0 };

unsigned char chanmap[6][5] = {
  {0, 2, 0, 0, 0}, {0, 3, 0, 0, 0}, {0, 4, 0, 0, 0},
  {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}
};

unsigned char operatormap[6][4][10] = {
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  },
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  },
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  },
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  },
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  },
  {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  }
};

void menu_load() {
  // Tying tree
  MAKESIBLING(&item_lfo, &item_ch36);
  MAKESIBLING(&item_ch36, &item_ch);
    MAKECHILD(&item_ch, &item_ch_algo);
    MAKESIBLING(&item_ch_algo, &item_ch_feedback);
    MAKESIBLING(&item_ch_feedback, &item_ch_ams);
    MAKESIBLING(&item_ch_ams, &item_ch_fms);
    MAKESIBLING(&item_ch_fms, &item_ch_op);
      MAKECHILD(&item_ch_op, &item_ch_op_dt1);
      MAKESIBLING(&item_ch_op_dt1, &item_ch_op_mul);
      MAKESIBLING(&item_ch_op_mul, &item_ch_op_am);
      MAKESIBLING(&item_ch_op_am, &item_ch_op_tl);
      MAKESIBLING(&item_ch_op_tl, &item_ch_op_rs);
      MAKESIBLING(&item_ch_op_rs, &item_ch_op_ar);
      MAKESIBLING(&item_ch_op_ar, &item_ch_op_d1r);
      MAKESIBLING(&item_ch_op_d1r, &item_ch_op_d2r);
      MAKESIBLING(&item_ch_op_d2r, &item_ch_op_d1l);
      MAKESIBLING(&item_ch_op_d1l, &item_ch_op_rr);
}

/*void menu_savechannel() {
  chanmap[item_ch.value][0] = item_ch_algo.value;
  chanmap[item_ch.value][1] = item_ch_feedback.value;
  chanmap[item_ch.value][2] = item_ch_ams.value;
  chanmap[item_ch.value][3] = item_ch_fms.value;
  chanmap[item_ch.value][4] = item_ch_op.value;
}

void menu_saveoperator() {
  operatormap[item_ch.value][item_ch_op.value][0] = item_ch_op_dt1.value;
  operatormap[item_ch.value][item_ch_op.value][1] = item_ch_op_mul.value;
  operatormap[item_ch.value][item_ch_op.value][2] = item_ch_op_am.value;
  operatormap[item_ch.value][item_ch_op.value][3] = item_ch_op_tl.value;
  operatormap[item_ch.value][item_ch_op.value][4] = item_ch_op_rs.value;
  operatormap[item_ch.value][item_ch_op.value][5] = item_ch_op_ar.value;
  operatormap[item_ch.value][item_ch_op.value][6] = item_ch_op_d1r.value;
  operatormap[item_ch.value][item_ch_op.value][7] = item_ch_op_d2r.value;
  operatormap[item_ch.value][item_ch_op.value][8] = item_ch_op_d1l.value;
  operatormap[item_ch.value][item_ch_op.value][9] = item_ch_op_rr.value;

}*/

void menu_loadchannel() {
  item_ch_algo.value = chanmap[item_ch.value][0];
  item_ch_feedback.value = chanmap[item_ch.value][1];
  item_ch_ams.value = chanmap[item_ch.value][2];
  item_ch_fms.value = chanmap[item_ch.value][3];
  item_ch_op.value = chanmap[item_ch.value][4];
}

/*void menu_loadoperator() {
  item_ch_op_dt1.value = operatormap[item_ch.value][item_ch_op.value][0];
  item_ch_op_mul.value = operatormap[item_ch.value][item_ch_op.value][1];
  item_ch_op_am.value = operatormap[item_ch.value][item_ch_op.value][2];
  item_ch_op_tl.value = operatormap[item_ch.value][item_ch_op.value][3];
  item_ch_op_rs.value = operatormap[item_ch.value][item_ch_op.value][4];
  item_ch_op_ar.value = operatormap[item_ch.value][item_ch_op.value][5];
  item_ch_op_d1r.value = operatormap[item_ch.value][item_ch_op.value][6];
  item_ch_op_d2r.value = operatormap[item_ch.value][item_ch_op.value][7];
  item_ch_op_d1l.value = operatormap[item_ch.value][item_ch_op.value][8];
  item_ch_op_rr.value = operatormap[item_ch.value][item_ch_op.value][9];
}*/


#endif
