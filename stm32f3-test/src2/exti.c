#include "exti.h"
#include "common.h"
#include "led.h"

volatile uint8_t select = 0;

// Initialise EXTI periferal on PE9
void EXTI_init(void) {
    // Enable SYSCFG clock
    RCC->APB2ENR |= (1 << 0);
    // Connect EXTI line to PA0
    SYSCFG->EXTICR[1] &= ~((1 << 2) | (1 << 1) | (1 << 0));
    // Enable interrupt on line PA0
    EXTI->IMR |= (1 << 0);
    // Enable trigger on rising edge
    EXTI->RTSR |= (1 << 0);
    // Disable trigger on falling edge
    EXTI -> FTSR &= ~(1 << 0);
    // Set priority for interrupt
    NVIC_SetPriority(EXTI0_IRQn, 0x03);
    // Enable interrupt
    NVIC_EnableIRQ(EXTI0_IRQn);
}

// Write handler for EXTI_9_5_IRQn interrupt
void EXTI0_IRQHandler(void) {
    if (EXTI->PR & (1 << 0)) {
        // Clear interrupt status flag
            
        if (select == 7) {
            select = 0;
        } else {
            select++;
        }

        EXTI->PR |= (1 << 0);
    }
}