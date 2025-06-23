#include <stdio.h>
#include "pico/stdlib.h"

#define vermelho 11
#define verde 12
#define azul 13

#define btn 2


int main() {
  stdio_init_all();

  gpio_init(vermelho);
  gpio_set_dir(vermelho, GPIO_OUT);
  
  gpio_init(verde);
  gpio_set_dir(verde, GPIO_OUT);  
  
  gpio_init(azul);
  gpio_set_dir(azul, GPIO_OUT);

  gpio_init(btn);
  gpio_set_dir(btn, GPIO_IN);
  gpio_pull_up(btn);


  while (true) {
    if(gpio_get(btn)){
        gpio_put(vermelho, 1);
        sleep_ms(500);
        gpio_put(vermelho, 0);
        sleep_ms(500);
    }
  }
}