#include "../inc/renderer.h"
#include "../inc/lcd.h"

void renderer_init() {
  // Initialize lcd
  lcd_init();
  // add custom chars
  for(i=0; i < (sizeof(chrtable) / (8 * sizeof(uint8_t))); i++) {
    lcd_setchar(i, chrtable[i]);
  }
}

void renderer_draw() {
  // If dirty, render
  if (!dirty) {
    return;
  }
    
  // Clear screen
  lcd_clear();
  // Compute depth
#ifdef DISPLAY_DEPTH
    depth = menu_depth();
#elif
    depth = 0;
#endif
    
  // Draw items on screen
  i = 0, rendered = menu_current();
  while (rendered && i < 2) {
    // Draw text
    lcd_put(1+i, depth + 1 + ((!i?1:0) * (!depth)), rendered->text);
    // Draw value
    if (rendered->display) {
      // Value to str
      rendered->display(rendered->value, valuestr);
      // Draw
      lcd_put(1+i, 17 - strlen(valuestr), valuestr);
    }
    // Render depth
#ifdef DISPLAY_DEPTH
    j = 1;
    while (j++ <= depth) {
      lcd_putc(1+i, j, 0x02);
    }
#endif
    
    // Render next
    rendered = rendered->nextSibling;
    i++;
  }
  
  // Draw arrow
  lcd_putc(1, !depth + depth, 0);

  // Undirty
  dirty = 0;
}

void renderer_dirty() {
  dirty = 1;
}

uint8_t renderer_isdirty() {
  return dirty;
}