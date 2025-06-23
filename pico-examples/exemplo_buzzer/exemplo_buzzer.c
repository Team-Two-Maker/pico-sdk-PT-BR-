#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define buzzer 9

#define btn 10

#define NOTE_C5 523     // Frequência da nota C5 em Hz


void play_note(uint buzzer_pin, uint frequency) {
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
    uint clkdiv = 4; // Define um divisor de clock
    uint wrap = 125000000 / (clkdiv * frequency);
    pwm_set_wrap(slice_num, wrap);
    pwm_set_clkdiv(slice_num, clkdiv);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(buzzer_pin), wrap / 2);
    pwm_set_enabled(slice_num, true);
}

void stop_buzzer(uint buzzer_pin) {
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
    pwm_set_enabled(slice_num, false);
}

int main() {
  stdio_init_all();

  gpio_init(buzzer);
  gpio_set_dir(buzzer, GPIO_OUT);
  gpio_put(buzzer, 0);

  gpio_init(btn);
  gpio_set_dir(btn, GPIO_IN);
  gpio_pull_down(btn);


  while (true) {
    if(gpio_get(btn)){
        play_note(buzzer, NOTE_C5);
        sleep_ms(500);
        stop_buzzer(buzzer);
    }else{
        stop_buzzer(buzzer);
        sleep_ms(500);
    }
  }
}