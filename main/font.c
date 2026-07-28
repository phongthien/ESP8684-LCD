#include "font.h"

static const uint8_t font_space[6] = {
    0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t font_H[6] = {
    0x7F,
    0x08,
    0x08,
    0x08,
    0x7F,
    0x00
};

static const uint8_t font_e[6] = {
    0x38,
    0x54,
    0x54,
    0x58,
    0x00,
    0x00
};

static const uint8_t font_l[6] = {
    0x41,
    0x7F,
    0x40,
    0x00,
    0x00,
    0x00
};

static const uint8_t font_o[6] = {
    0x38,
    0x44,
    0x44,
    0x38,
    0x00,
    0x00
};

const uint8_t* font_get(char c)
{
    switch(c)
    {
        case 'H':
            return font_H;

        case 'e':
            return font_e;

        case 'l':
            return font_l;

        case 'o':
            return font_o;

        case ' ':
            return font_space;

        default:
            return font_space;
    }
}
