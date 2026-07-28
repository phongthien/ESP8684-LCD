#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#include "lcd.h"

#define LED_PIN GPIO_NUM_4

void app_main(void)
{
    gpio_config_t io = {
        .pin_bit_mask = (1ULL << LED_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&io);

    // Khởi tạo LCD
    lcd_init();

    // Xóa màn hình
    lcd_clear();

    // Hiển thị chữ Hello
    lcd_draw_string(20, 3, "Hello");

    // Cập nhật LCD
    lcd_update();

    while (1)
    {
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
