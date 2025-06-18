#include "pico/stdlib.h"

#define red 2
#define green 3
#define blue 4
#define trig 14
#define echo 15

int main() {

    //iniciando leds
    gpio_init(red);
    gpio_set_dir(red, GPIO_OUT);
    gpio_init(green);
    gpio_set_dir(green, GPIO_OUT);
    gpio_init(blue);
    gpio_set_dir(blue, GPIO_OUT);
    
    //iniciando sensor HC-SR04
    gpio_init(trig);
    gpio_set_dir(trig, GPIO_OUT);
    gpio_init(echo);
    gpio_set_dir(echo, GPIO_IN);

    while (true) {
        gpio_put(blue, 1);
        sleep_ms(250);
        gpio_put(blue, 0);
        sleep_ms(250);
    }

}
