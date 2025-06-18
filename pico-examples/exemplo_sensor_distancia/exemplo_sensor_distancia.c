#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define red 2
#define green 3
#define blue 4
#define trig 14
#define echo 15

// Função para configurar PWM no pino TRIG
void configurar_pwm_trig() {
    gpio_set_function(trig, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(trig);

    pwm_set_wrap(slice_num, 12499);      // Frequência de ~8kHz (calculado para clock padrão de 125MHz)
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);  // Mantém nível baixo até disparar
    pwm_set_enabled(slice_num, true);
}

// Gera um pulso PWM de 10 microssegundos no TRIG
void gerar_pulso_trig_pwm() {
    uint slice_num = pwm_gpio_to_slice_num(trig);

    // Seta o pulso HIGH
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 6250);  // Duty cycle de 50%
    sleep_us(10);  // Mantém por 10us

    // Seta LOW novamente
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
}

// Função para medir distância
float medir_distancia() {
    uint32_t inicio, fim;
    uint64_t duracao;

    gerar_pulso_trig_pwm();  // Dispara o pulso PWM de trigger


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
    
    // Configura TRIG com PWM e ECHO como entrada
    configurar_pwm_trig();
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
    return 0;
}
