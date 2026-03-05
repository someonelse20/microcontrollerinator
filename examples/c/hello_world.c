#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  setup_default_uart();
  while (1) {
    printf("Hello World From Pi Pico USB CDC\n");
    // sleep_ms(100);
  }
}
