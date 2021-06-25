#include "gpio.h"
#include "common.h"

// Enable clock for GPIOA
void GPIO_PORT_A_clk_init(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
}

// Enable clock for GPIOE
void GPIO_PORT_E_clk_init(void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
}

// Initialise GPIOE pins
void GPIO_init(void) {
    // Set user button to input mode B1->PA0 (provided button with pull-down)
    GPIOA->MODER &= ~(1 << 0);
    GPIOA->MODER &= ~(1 << 1);
    // Set to no pull-up/pull-down mode
    GPIOE->PUPDR &= ~(1 << 0);
    GPIOE->PUPDR &= ~(1 << 1);

    // Set led 3 to output mode LD3 -> PE9
    GPIOE->MODER |= (1 << 18);
    GPIOE->MODER &= ~(1 << 19);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 9);

    // Set led 4 to output mode LD4 -> PE8
    GPIOE->MODER |= (1 << 16);
    GPIOE->MODER &= ~(1 << 17);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 8);

    // Set led 5 to output mode LD5 -> PE10
    GPIOE->MODER |= (1 << 20);
    GPIOE->MODER &= ~(1 << 21);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 10);

    // Set led 6 to output mode LD6 -> PE15
    GPIOE->MODER |= (1 << 30);
    GPIOE->MODER &= ~(1 << 31);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 15);

    // Set led 7 to output mode LD7 -> PE11
    GPIOE->MODER |= (1 << 22);
    GPIOE->MODER &= ~(1 << 23);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 11);

    // Set led 8 to output mode LD8 -> PE14
    GPIOE->MODER |= (1 << 28);
    GPIOE->MODER &= ~(1 << 29);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 14);

    // Set led 9 to output mode LD9 -> PE12
    GPIOE->MODER |= (1 << 24);
    GPIOE->MODER &= ~(1 << 25);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 12);

    // Set led 10 to output mode LD10 -> PE13
    GPIOE->MODER |= (1 << 26);
    GPIOE->MODER &= ~(1 << 27);
    // Set to output push-pull mode
    GPIOE->OTYPER &= ~(1 << 13);
}