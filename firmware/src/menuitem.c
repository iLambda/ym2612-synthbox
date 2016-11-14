#include "../inc/menuitem.h"

#include <string.h>

#pragma warning disable 520
#pragma warning disable 1498

void menuitem_display_detune(uint8_t value, uint8_t* out) {
  if(value != 3) {
    strcpy(out, "x1  \x03");
    out[2] = value > 3 ? '-' : '+';
    out[3] = 0x31 + (value & 0x03);
  } else {
    strcpy(out, "x1");
  }
}

void menuitem_display_mul(uint8_t value, uint8_t* out) {
  menuitem_display_byte(value, out);
  if (value == 0) {
    strcpy(out, "x\01");
  } else {
    out[value < 10 ? 1 : 0] = 'x';
  }
}

void menuitem_display_bool(uint8_t value, uint8_t* out) {
  strcpy(out, value ? "On" : "Off");
}

void menuitem_display_ams(uint8_t value, uint8_t* out) {
  switch (value) {
    case 0: strcpy(out, "0/dB"); break;
    case 1: strcpy(out, "1.4/dB"); break;
    case 2: strcpy(out, "5.9/dB"); break;
    case 3: strcpy(out, "11.8/dB"); break;
  }
}

void menuitem_display_fms(uint8_t value, uint8_t* out) {
  switch (value) {
    case 0: strcpy(out, "\x04""0\x25"); break;
    case 1: strcpy(out, "\x04""3.4\x25"); break;
    case 2: strcpy(out, "\x04""6.7\x25"); break;
    case 3: strcpy(out, "\x04""10\x25"); break;
    case 4: strcpy(out, "\x04""14\x25"); break;
    case 5: strcpy(out, "\x04""20\x25"); break;
    case 6: strcpy(out, "\x04""40\x25"); break;
    case 7: strcpy(out, "\x04""80\x25"); break;
  }
}


void menuitem_display_rs(uint8_t value, uint8_t* out) {
  strcpy(out, "1/ ");
  out[2] = 0x30 + (8 >> value);
}

void menuitem_display_lfo(uint8_t value, uint8_t* out) {
  switch (value) {
    case 0: strcpy(out, "Off"); break;
    case 1: strcpy(out, "3.98Hz"); break;
    case 2: strcpy(out, "5.56Hz"); break;
    case 3: strcpy(out, "6.02Hz"); break;
    case 4: strcpy(out, "6.37Hz"); break;
    case 5: strcpy(out, "6.88Hz"); break;
    case 6: strcpy(out, "9.63Hz"); break;
    case 7: strcpy(out, "48.10Hz"); break;
    case 8: strcpy(out, "72.20Hz"); break;
  }
}

void menuitem_display_algo(uint8_t value, uint8_t* out) {
  switch (value) {
    case 0: strcpy(out, "1>2>3>4"); break;
    case 1: strcpy(out, "12>3>4>"); break;
    case 2: strcpy(out, "1(2>3)>4"); break;
    case 3: strcpy(out, "(1>2)3>4"); break;
    case 4: strcpy(out, "(1>2)(3>4)"); break;
    case 5: strcpy(out, "1>234>"); break;
    case 6: strcpy(out, "(1>2)34>"); break;
    case 7: strcpy(out, "1234>"); break;
  }
}

void menuitem_display_byteplusone(uint8_t value, uint8_t* out) {
  itoa(out, value+1, 10);
}

void menuitem_display_byte(uint8_t value, uint8_t* out) {
  itoa(out, value, 10);
}

#pragma warning enable 520
#pragma warning enable 1498
