#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Ajuste das definições conforme a fiação do diagrama:
// No diagrama, temos:
//   LED azul (led_blue) em GP11,
//   LED vermelho (led_red) em GP12,
//   LED verde (led_green) em GP13.
const uint BLUE   = 11;    // LED azul em GP11
const uint RED    = 12;    // LED vermelho em GP12
const uint GREEN  = 13;    // LED verde em GP13
const uint BUTTON_PIN = 5;
bool is_running = false;

// Callback: Desliga o LED azul após 3 segundos.
int64_t desligar_azul(alarm_id_t id, void *user_data) {
    gpio_put(BLUE, false);
    printf("🔵 LED azul (GP11) desligado\n");
    return 0;
}

// Callback: Desliga o LED vermelho após 6 segundos.
int64_t desligar_vermelho(alarm_id_t id, void *user_data) {
    gpio_put(RED, false);
    printf("🔴 LED vermelho (GP12) desligado\n");
    return 0;
}

// Callback: Desliga o LED verde após 9 segundos.
int64_t desligar_verde(alarm_id_t id, void *user_data) {
    gpio_put(GREEN, false);
    printf("🟢 LED verde (GP13) desligado\n");
    is_running = false; // Finaliza a sequência
    return 0;
}

void init_led(uint8_t ledGPIO) {
    gpio_init(ledGPIO);
    gpio_set_dir(ledGPIO, GPIO_OUT);
    gpio_put(ledGPIO, false); // Garante que o LED inicie desligado
}

void init_button(uint8_t buttonGPIO) {
    gpio_init(buttonGPIO);
    gpio_set_dir(buttonGPIO, GPIO_IN);
    gpio_pull_up(buttonGPIO);
}

void desligar_leds() {
    // Agenda os desligamentos conforme a sequência desejada:
    // 3 s: Apaga o LED azul
    add_alarm_in_ms(3000, desligar_azul, NULL, false);
    // 6 s: Apaga o LED vermelho
    add_alarm_in_ms(6000, desligar_vermelho, NULL, false);
    // 9 s: Apaga o LED verde
    add_alarm_in_ms(9000, desligar_verde, NULL, false);
}

int main() {
    stdio_init_all();

    // Inicializa os LEDs conforme os pinos do diagrama
    init_led(BLUE);
    init_led(RED);
    init_led(GREEN);

    init_button(BUTTON_PIN);

    printf("Sistema iniciado. Aguardando o pressionamento do botão...\n");

    while (true) {
        // Verifica se o botão foi pressionado
        if (gpio_get(BUTTON_PIN) == 0 && !is_running) {
            sleep_ms(50); // Debounce

            // Verifica novamente após o debounce
            if (gpio_get(BUTTON_PIN) == 0 && !is_running) {
                is_running = true;
                // Liga os LEDs
                gpio_put(RED, true);
                gpio_put(GREEN, true);
                gpio_put(BLUE, true);
                printf("⚡ Botão pressionado! LEDs acesos: 🔵, 🔴, 🟢\n");

                desligar_leds();
            }
        }
        sleep_ms(10); // Reduz o uso da CPU
    }

    return 0; // Nunca alcançado
}
