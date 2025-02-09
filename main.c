#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22 // Pino GPIO do servomotor
#define WRAP_VALUE 25000 // Período de 20ms (50Hz)

#define position_180 2400 // ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus.
#define position_90 1470 // ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus.
#define position_0 500 // ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus.

#define delay_05s 5 // Aguarda 5 segundos na posição.
#define delay_10s 10 // Aguarda 10 segundos na posição.

// Função para configurar o PWM corretamente
void set_pwm_position(uint gpio, uint16_t pulse_width)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint16_t level = (pulse_width * WRAP_VALUE) / 20000; // Cálculo correto do duty cycle
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

int main()
{
    stdio_init_all();

    // Configuração do GPIO para PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_wrap(slice_num, WRAP_VALUE);
    pwm_set_clkdiv(slice_num, 100.0f); // Ajuste do clock para precisão de 50Hz
    pwm_set_enabled(slice_num, true);

    // Passo 1: Posicionar o servo em 180 graus e aguardar 5s
    set_pwm_position(PWM_PIN, position_180);
    sleep_ms(5000);

    // Passo 2: Posicionar o servo em 90 graus e aguardar 5s
    set_pwm_position(PWM_PIN, position_90);
    sleep_ms(5000);

    // Passo 3: Posicionar o servo em 0 graus e aguardar 5s
    set_pwm_position(PWM_PIN, position_0);
    sleep_ms(5000);

    // Movimento contínuo entre 0 e 180 graus
    while (true)
    {
        // Movimento de 0° para 180°
        for (uint16_t pulse = position_0; pulse <= position_180; pulse += delay_05s)
        {
            set_pwm_position(PWM_PIN, pulse);
            sleep_ms(delay_10s);
        }
        // Movimento de 180° para 0°
        for (uint16_t pulse = position_180; pulse >= position_0; pulse -= delay_05s)
        {
            set_pwm_position(PWM_PIN, pulse);
            sleep_ms(delay_10s);
        }
    }
}
