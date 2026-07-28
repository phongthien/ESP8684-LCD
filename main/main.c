#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "LED";
#define LED_GPIO GPIO_NUM_4

void app_main(void)
{
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        ESP_LOGI(TAG, "LED ON");
        gpio_set_level(GPIO_NUM_4, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
    
        ESP_LOGI(TAG, "LED OFF");
        gpio_set_level(GPIO_NUM_4, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
