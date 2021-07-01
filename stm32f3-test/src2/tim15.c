#include "common.h"
#include "tim15.h"
#include "led.h"

// Configure general purpose timer 15 (APB2)
void TIM15_init(void) {
    // Enable TIM15 clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;
    // Set priority for TIM15 interrupt
    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0x03);
    // Enable TIM15 interrupt
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
    // Turn off TIM15 counter
    TIM15->CR1 &= ~(TIM_CR1_CEN);
    // Reset TIM15 peripheral
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST;
    RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST);
    // Set TIM15 prescaler
    TIM15->PSC = core_clock_hz / 1000;
    // Set reload value for 1ms
    TIM15->ARR = 1000;
    // Send update event to reset TIM15 and apply settings
    TIM15->EGR |= TIM_EGR_UG;
    // Enable TIM15 update interrupt
    TIM15->DIER |= TIM_DIER_UIE;
    // Enable TIM15
    TIM15->CR1 |= TIM_CR1_CEN;
}

// Write handler for TIM1_BRK_TIM15_IRQn interrupt
void TIM1_BRK_TIM15_IRQHandler(void) {
    if (TIM15->SR & TIM_SR_UIF) {
        // Clear interrupt status flag
        TIM15->SR &=~(TIM_SR_UIF);
        // Toggle led 
        led_toggle(LD3);
    }
}