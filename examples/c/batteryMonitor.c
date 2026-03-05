/*
 * THIS PROGRAM IS UNTESTED AND MAY NOT WORK.
 * Modified ADC example from pico sdk.
 * Monitors voltage of connected battery.
 */
#include "hardware/adc.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  setup_default_uart();
  stdio_init_all();
  printf("ADC Example, measuring battery voltage\n");

  adc_init();

  // Make sure GPIO is high-impedance, no pullups etc
  adc_gpio_init(29);
  // Select ADC input 3 (GPIO29)
  adc_select_input(3);

  while (1) {
    // 12-bit conversion, assume max value == ADC_VREF == 3.3 V, multiply
    // by 1.3125 to get actual voltage of battery.
    const float conversion_factor = (3.3f / (1 << 12)) * 1.3125;
    uint16_t result = adc_read();
    printf("Raw value: 0x%03x, Battery voltage: %f V\n", result,
           result * conversion_factor);
    sleep_ms(500);
  }
}
