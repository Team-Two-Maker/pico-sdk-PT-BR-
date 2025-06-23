#include <stdio.h>
#include "pico/stdlib.h"

#define vermelho 11

#define btn 10


int main() {
  stdio_init_all();

  gpio_init(vermelho);
  gpio_set_dir(vermelho, GPIO_OUT);

  gpio_init(btn);
  gpio_set_dir(btn, GPIO_IN);
  gpio_pull_down(btn);


  while (true) {
    if(gpio_get(btn)){
        gpio_put(vermelho, 1);
        sleep_ms(500);
        gpio_put(vermelho, 0);
        sleep_ms(500);
    }
  }
}