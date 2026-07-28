#pragma once

#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_err.h"

#define LCD_HOST SPI2_HOST

#define PIN_NUM_MOSI   GPIO_NUM_7
#define PIN_NUM_MISO   GPIO_NUM_2
#define PIN_NUM_CLK    GPIO_NUM_6
#define PIN_NUM_CS     GPIO_NUM_10
#define PIN_NUM_RST    GPIO_NUM_5
#define PIN_NUM_DC     GPIO_NUM_NC      // Nếu LCD không có chân A0/DC
#define PIN_NUM_BL     GPIO_NUM_4

esp_err_t lcd_init(void);

void lcd_command(uint8_t cmd);
void lcd_data(uint8_t data);

void lcd_clear(void);

void lcd_set_pixel(uint8_t x,uint8_t y,bool color);

void lcd_update(void);

void lcd_draw_char(uint8_t x,uint8_t y,char c);

void lcd_draw_string(uint8_t x,uint8_t y,const char *str);
