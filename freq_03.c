#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int state = 0; // Variável para rastrear o estado atual

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs primeiro
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Liga o LED apropriado com base no estado atual
    if (state == 0) {
        gpio_put(LED_PIN_RED, 1);
        state = 1;
    } else if (state == 1) {
        gpio_put(LED_PIN_YELLOW, 1);
        state = 2;
    } else if (state == 2) {
        gpio_put(LED_PIN_GREEN, 1);
        state = 0;
    }

    // Retorna true para manter o temporizador repetindo
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Declaração de uma estrutura de temporizador de repetição
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução
    while (true) {
        sleep_ms(1000); // Pequeno atraso para reduzir o uso da CPU
        printf("1 segundo\n");
    }

    return 0;
}
