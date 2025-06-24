#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Define os pinos usados pelo sensor ultrassônico
#define PINO_TRIG 28
#define PINO_ECHO 27

// Envia um pulso de disparo de 10 microssegundos para iniciar a medição
void enviar_pulso_ultrassonico()
{
    gpio_put(PINO_TRIG, 1);
    sleep_us(10);
    gpio_put(PINO_TRIG, 0);
}

// Mede a duração do pulso recebido no pino ECHO, que representa o tempo de ida e volta do som
uint32_t medir_tempo_echo()
{
    while (gpio_get(PINO_ECHO) == 0)
        ;
    absolute_time_t inicio = get_absolute_time();

    while (gpio_get(PINO_ECHO) == 1)
        ;
    absolute_time_t fim = get_absolute_time();

    return absolute_time_diff_us(inicio, fim);
}

// Calcula a distância em centímetros com base na duração do pulso
float medir_distancia_cm()
{
    enviar_pulso_ultrassonico();
    uint32_t duracao_us = medir_tempo_echo();
    float distancia = (duracao_us * 0.0343f) / 2.0f;
    return distancia;
}

int main()
{
    stdio_init_all();

    // Configura os pinos do sensor
    gpio_init(PINO_TRIG);
    gpio_set_dir(PINO_TRIG, GPIO_OUT);
    gpio_put(PINO_TRIG, 0);

    gpio_init(PINO_ECHO);
    gpio_set_dir(PINO_ECHO, GPIO_IN);

    sleep_ms(1000); // Tempo para estabilização do sensor

    // Loop contínuo para leitura e exibição da distância
    while (true)
    {
        float distancia_cm = medir_distancia_cm();
        printf("Distância: %.2f cm\n", distancia_cm);
        sleep_ms(500);
    }

    return 0;
}
