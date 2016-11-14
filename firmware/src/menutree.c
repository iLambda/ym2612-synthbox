#include "../inc/menutree.h"

ym2612menuitem_t item_lfo = { "LFO", 0, 9, menuitem_display_lfo, 0, 0, 0, 0, 0, 0 };
ym2612menuitem_t item_ch36 = { "CH36", 0, 2, menuitem_display_bool, 0, 0, 0, 0, 0, 0 };
ym2612menuitem_t item_ch = { "CHANNEL", 0, 6, menuitem_display_byteplusone, 0, 0, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_algo = { "ALGO", 0, 8, menuitem_display_algo, 0, 0, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_feedback = { "FEEDBACK", 0, 8, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_ams = { "AMS", 0, 4, menuitem_display_ams, 0, 0, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_fms = { "FMS", 0, 8, menuitem_display_fms, 0, 0, 0, 0, 0, 0 };
  ym2612menuitem_t item_ch_op = { "OPERATOR", 0, 4, menuitem_display_byteplusone, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_dt1 = { "DT1", 0, 7, menuitem_display_detune, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_mul = { "MUL", 0, 16, menuitem_display_mul, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_am = { "AM", 0, 2, menuitem_display_bool, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_tl = { "TL", 0, 128, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_rs = { "RS", 0, 4, menuitem_display_rs, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_ar = { "AR", 0, 32, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d1r = { "D1R", 0, 32, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d2r = { "D2R", 0, 32, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_d1l = { "D1L", 0, 16, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };
    ym2612menuitem_t item_ch_op_rr = { "RR", 0, 16, menuitem_display_byte, 0, 0, 0, 0, 0, 0 };


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
      
  // Setting callbacks
  item_ch.gonefwd = menu_loadchannel;
  item_ch.frombwd = menu_savechannel;
  item_ch_op.gonefwd = menu_loadoperator;
  item_ch_op.frombwd = menu_saveoperator;
}


void menu_savechannel() {
    ym2612menuitem_t* current = item_ch.child;
    uint8_t k = 0;
    // while there is a field to save
    while (current){
        // save it
        eeprom_write((uint16_t)(0x01 + (k)), ((item_ch_algo.value & 0x07) << 4) | (item_ch_feedback.value & 0x07));
        eeprom_write((uint16_t)(0x01 + (k + 1)), ((item_ch_ams.value & 0x07) << 4) | (item_ch_fms.value & 0x07));
        // iterate
        k += 2;
        current = current->child;
    }
}

void menu_loadchannel() { 
    
}

void menu_saveoperator() { 
    ym2612menuitem_t* current = item_ch_op.child;
    uint8_t k = 0;
    // while there is a field to save
    while (current && k < 10){
        // save it
        eeprom_write(0x10 + ((item_ch.value * 40) + (item_ch_op.value * 10) + k), current->value);
        // iterate
        k += 1;
        current = current->child;
    }
}

void menu_loadoperator() { 

}
