#include <stdio.h>
#include "pico/stdlib.h"

#define red 2
#define green 3
#define blue 4
#define trig 14
#define echo 15

// Função para medir distância
float medir_distancia() {
    uint32_t inicio, fim;
    uint64_t duracao;

    // Gera um pulso no TRIG
    gpio_put(trig, 1);
    sleep_us(10);
    gpio_put(trig, 0);

    // Aguarda o pino ECHO ir para HIGH (inicio do pulso)
    while (gpio_get(echo) == 0) {
        inicio = time_us_32();
    }

    // Aguarda o pino ECHO voltar para LOW (fim do pulso)
    while (gpio_get(echo) == 1) {
        fim = time_us_32();
    }

    // Calcula a duração do pulso em microsegundos
    duracao = inicio - fim;

    // Calcula a distância (som = 343 m/s → 0.0343 cm/us)
    float distancia = (duracao * 0.0343) / 2;

    return distancia;
}

int main() {

    stdio_init_all();

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
        float distancia;
        gpio_put(blue, 1);
        sleep_ms(250);
        gpio_put(blue, 0);
        sleep_ms(250);

        distancia = medir_distancia();

        printf("Distancia: %.2f cm\n", distancia);
        sleep_ms(500);
    }

}
