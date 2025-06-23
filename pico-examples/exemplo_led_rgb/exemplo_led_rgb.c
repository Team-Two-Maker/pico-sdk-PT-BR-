#include <stdio.h>
#include "pico/stdlib.h"

#define vermelho 11
#define verde 12
#define azul 13


int main() {
  stdio_init_all();

  gpio_init(vermelho);
  gpio_set_dir(vermelho, GPIO_OUT);
  
  gpio_init(verde);
  gpio_set_dir(verde, GPIO_OUT);  
  
  gpio_init(azul);
  gpio_set_dir(azul, GPIO_OUT);


  while (true) {
    gpio_put(vermelho, 1);
    sleep_ms(500);
    gpio_put(verde, 1);
    sleep_ms(500);
    gpio_put(azul, 1);
    sleep_ms(500);
    gpio_put(vermelho, 0);
    sleep_ms(500);
    gpio_put(verde, 0);
    sleep_ms(500);
    gpio_put(azul, 0);
  }
}