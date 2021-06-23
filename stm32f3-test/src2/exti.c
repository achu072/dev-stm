#include "exti.h"
#include "led.h"

// Initialise EXTI periferal on PE9
void EXTI_init(void) {
    // Enable SYSCFG clock
    RCC->APB2ENR |= (1 << 0);
    // Connect EXTI line to PE9
    SYSCFG->EXTICR[3] |= (1 << 6);
    SYSCFG->EXTICR[3] &= ~((1 << 5) | (1 << 4));
    // Enable interrupt on line PE9
    EXTI->IMR |= (1 << 9);
    // Disable trigger on rising edge
    EXTI->RTSR &= ~(1 << 9);
    // Enable trigger on falling edge
    EXTI -> FTSR |= (1 << 9);
    // Set priority for interrupt
    NVIC_SetPriority(EXTI9_5_IRQn, 0x03);
    // Enable interrupt
    NVIC_EnableIRQ(EXTI9_5_IRQn);
}

// Write handler for EXTI_9_5_IRQn interrupt
void EXTI_5_9_IRQn_handler(void) {
    if (EXTI->PR & (1 << 9)) {
            // Clear interrupt status flag
            EXTI->PR |= (1 << 9);
            led_toggle;
    }
}