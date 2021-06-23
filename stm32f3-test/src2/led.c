#include "common.h"
#include "led.h"

void led_on(void) {
    GPIOE->ODR |= (1 << 9);
}

void led_off(void) {
    GPIOE->ODR &= ~(1 << 9);
}

void led_toggle(void) {
    GPIOE->ODR ^= (1 << 9);
}