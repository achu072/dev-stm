#include "main.h"
#include "common.h"
#include "exti.h"

int main(void){

    // Enable clock for GPIOE & GPIOA
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // Initialise GPIOE pins
    // Set PE9 (led) to output mode
    GPIOE->MODER |= (1 << 18);
    GPIOE->MODER &= ~(1 << 19);
    // Set PA0 (button) to input mode
    GPIOA->MODER &= ~(1 << 0);
    GPIOA->MODER &= ~(1 << 1);
    // Set PE9 to output push-pull
    GPIOE->OTYPER &= ~(1 << 9);
    // Set PA0 to pull-up
    GPIOE->PUPDR &= ~(1 << 18);
    GPIOE->PUPDR |= (1 << 19);

    // Enable interrupt on PE9
    EXTI_init();

    while(1){
        ;
    }
}
