#ifndef YM2612_SYNTHBOX_MENUTREE_H
#define YM2612_SYNTHBOX_MENUTREE_H

#include <xc.h>

#include <stdint.h>
#include <stdlib.h>

#include <EEP.h>

#include "../inc/menuitem.h"

#define MAKESIBLING(b, s) (b)->nextSibling = s; (s)->prevSibling = b;
#define MAKECHILD(p, c) (p)->child = c; (c)->parent = p;

extern ym2612menuitem_t item_lfo;
extern ym2612menuitem_t item_ch36;
extern ym2612menuitem_t item_ch;
  extern ym2612menuitem_t item_ch_algo;
  extern ym2612menuitem_t item_ch_feedback;
  extern ym2612menuitem_t item_ch_ams;
  extern ym2612menuitem_t item_ch_fms;
  extern ym2612menuitem_t item_ch_op;
    extern ym2612menuitem_t item_ch_op_dt1;
    extern ym2612menuitem_t item_ch_op_mul;
    extern ym2612menuitem_t item_ch_op_am;
    extern ym2612menuitem_t item_ch_op_tl;
    extern ym2612menuitem_t item_ch_op_rs;
    extern ym2612menuitem_t item_ch_op_ar;
    extern ym2612menuitem_t item_ch_op_d1r;
    extern ym2612menuitem_t item_ch_op_d2r;
    extern ym2612menuitem_t item_ch_op_d1l;
    extern ym2612menuitem_t item_ch_op_rr;

void menu_load();
void menu_savechannel();
void menu_loadchannel();
void menu_loadoperator();
void menu_saveoperator();

#endif
