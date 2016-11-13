#include "menuitem.h"

unsigned char menuitem_range_detune(unsigned char value) {
  if (value >= 128) {
    return value <= 0xFD ? 0xFD : value;
  } else {
    return value >= 0x03 ? 0x03 : value;
  }
}

unsigned char menuitem_range_2(unsigned char value) {
  return value % 2;
}

unsigned char menuitem_range_4(unsigned char value) {
  return value % 4;
}

unsigned char menuitem_range_6(unsigned char value) {
  return value % 4;
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

unsigned char menuitem_range_lfo(unsigned char value) {
  return value % 9;
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

void menuitem_display_bool(unsigned char value, char* out) {
  strcpy(out, value ? "On" : "Off");
}

void menuitem_display_ams(unsigned char value, char* out) {
  switch (value) {
    case 0: strcpy(out, "0 dB"); break;
    case 1: strcpy(out, "1.4/dB"); break;
    case 2: strcpy(out, "5.9/dB"); break;
    case 3: strcpy(out, "11.8/dB"); break;
  }
}

void menuitem_display_fms(unsigned char value, char* out) {
  switch (value) {
    case 0: strcpy(out, "\x040\x25"); break;
    case 1: strcpy(out, "\x043.4\x25"); break;
    case 2: strcpy(out, "\x046.7\x25"); break;
    case 3: strcpy(out, "\x0410\x25"); break;
    case 4: strcpy(out, "\x0414\x25"); break;
    case 5: strcpy(out, "\x0420\x25"); break;
    case 6: strcpy(out, "\x0440\x25"); break;
    case 7: strcpy(out, "\x0480\x25"); break;
  }
}


void menuitem_display_rs(unsigned char value, char* out) {
  strcpy(out, "1/ ");
  out[2] = 0x30 + (8 >> value);
}

void menuitem_display_lfo(unsigned char value, char* out) {
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

void menuitem_display_algo(unsigned char value, char* out) {
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

void menuitem_display_byteplusone(unsigned char value, char* out) {
  ByteToStr(value+1, out);
}
