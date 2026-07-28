#include "lcd.h"
#include "font.h"

extern uint8_t lcd_buffer[1024];

void lcd_draw_char(uint8_t x, uint8_t page, char ch)
{
    const uint8_t *font = font_get(ch);

    if (font == NULL)
        return;

    int index = page * 128 + x;

    for (int i = 0; i < 6; i++)
    {
        if ((index + i) < 1024)
            lcd_buffer[index + i] = font[i];
    }
}
