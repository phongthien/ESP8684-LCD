#include "lcd.h"

#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static spi_device_handle_t lcd_spi;

static uint8_t framebuffer[128 * 64 / 8];

static void spi_send(bool dc,uint8_t data)
{
    spi_transaction_t t;

    memset(&t,0,sizeof(t));

    t.length = 8;

    t.tx_buffer = &data;

    spi_device_transmit(lcd_spi,&t);
}

void lcd_command(uint8_t cmd)
{
    spi_send(false,cmd);
}

void lcd_data(uint8_t data)
{
    spi_send(true,data);
}

esp_err_t lcd_init(void)
{
    gpio_config_t io =
    {
        .pin_bit_mask =
            (1ULL<<PIN_NUM_CS) |
            (1ULL<<PIN_NUM_RST) |
            (1ULL<<PIN_NUM_BL),

        .mode = GPIO_MODE_OUTPUT
    };

    gpio_config(&io);

    gpio_set_level(PIN_NUM_BL,1);

    spi_bus_config_t buscfg =
    {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1
    };

    ESP_ERROR_CHECK(
        spi_bus_initialize(
            LCD_HOST,
            &buscfg,
            SPI_DMA_CH_AUTO));

    spi_device_interface_config_t devcfg =
    {
        .clock_speed_hz = 1000000,
        .mode = 0,
        .spics_io_num = PIN_NUM_CS,
        .queue_size = 1
    };

    ESP_ERROR_CHECK(
        spi_bus_add_device(
            LCD_HOST,
            &devcfg,
            &lcd_spi));

    gpio_set_level(PIN_NUM_RST,0);

    vTaskDelay(pdMS_TO_TICKS(20));

    gpio_set_level(PIN_NUM_RST,1);

    vTaskDelay(pdMS_TO_TICKS(20));

    // ===== ST7565 Init =====

    lcd_command(0xAE);

    lcd_command(0xA2);

    lcd_command(0xA0);

    lcd_command(0xC8);

    lcd_command(0x22);

    lcd_command(0x2F);

    lcd_command(0x40);

    lcd_command(0xAF);

    memset(framebuffer,0,sizeof(framebuffer));

    return ESP_OK;
}

void lcd_clear(void)
{
    memset(framebuffer,0,sizeof(framebuffer));
}
