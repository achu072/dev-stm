#include "common.h"
#include "led.h"

void led_on(uint8_t led) {
    switch(led) {
        case LD3:
            GPIOE->ODR |= (1 << 9);
            break;
        case LD4:
            GPIOE->ODR |= (1 << 8);
            break;
        case LD5:
            GPIOE->ODR |= (1 << 10);
            break;
        case LD6:
            GPIOE->ODR |= (1 << 15);
            break;
        case LD7:
            GPIOE->ODR |= (1 << 11);
            break;
        case LD8:
            GPIOE->ODR |= (1 << 14);
            break;
        case LD9:
            GPIOE->ODR |= (1 << 12);
            break;
        case LD10:
            GPIOE->ODR |= (1 << 13);
            break;
        default:
            break;
    }
    
}

void led_off(uint8_t led) {
    switch(led) {
        case LD3:
            GPIOE->ODR &= ~(1 << 9);
            break;
        case LD4:
            GPIOE->ODR &= ~(1 << 8);
            break;
        case LD5:
            GPIOE->ODR &= ~(1 << 10);
            break;
        case LD6:
            GPIOE->ODR &= ~(1 << 15);
            break;
        case LD7:
            GPIOE->ODR &= ~(1 << 11);
            break;
        case LD8:
            GPIOE->ODR &= ~(1 << 14);
            break;
        case LD9:
            GPIOE->ODR &= ~(1 << 12);
            break;
        case LD10:
            GPIOE->ODR &= ~(1 << 13);
            break;
        default:
            break;
    }
}

void led_toggle(uint8_t led) {
    switch(led) {
        case LD3:
            GPIOE->ODR ^= (1 << 9);
            break;
        case LD4:
            GPIOE->ODR ^= (1 << 8);
            break;
        case LD5:
            GPIOE->ODR ^= (1 << 10);
            break;
        case LD6:
            GPIOE->ODR ^= (1 << 15);
            break;
        case LD7:
            GPIOE->ODR ^= (1 << 11);
            break;
        case LD8:
            GPIOE->ODR ^= (1 << 14);
            break;
        case LD9:
            GPIOE->ODR ^= (1 << 12);
            break;
        case LD10:
            GPIOE->ODR ^= (1 << 13);
            break;
        default:
            break;
    }
}