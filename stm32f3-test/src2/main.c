#include "main.h"

#define BUTTON_PRESSED (GPIOA->IDR &= (1 << 0))
#define LED_ON GPIOE->ODR |= (1 << 9)
#define LED_OFF GPIOE->ODR &= ~(1 << 9)

int main(void){

    // Enable clock for GPIOE & GPIOA
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // Initialise GPIOE pins
    // Set PE9 (LD3) to output mode
    GPIOE->MODER |= (1 << 18);
    GPIOE->MODER &= ~(1 << 19);
    // Set PA0 (B1) to input mode
    GPIOA->MODER &= ~(1 << 0);
    GPIOA->MODER &= ~(1 << 1);
    // Set PE9 to output push-pull
    GPIOE->OTYPER &= ~(1 << 9);
    // Set PA0 to pull-up
    GPIOE->PUPDR &= ~(1 << 18);
    GPIOE->PUPDR |= (1 << 19);

    while(1){
        if (BUTTON_PRESSED) {
            LED_ON;
        } else {
            LED_OFF;
        }
    }
}