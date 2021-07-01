#include "common.h"
#include "clk.h"

// Intitalise system clock 
void CLK_init(void) {
    // Set up wait states and instruction pre-fetch
    FLASH->ACR |= (FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_0);
    // Configure PLL
    // Reset PLL register
    RCC->CFGR &= ~(RCC_CFGR_PLLMULL | RCC_CFGR_PLLSRC);
    // Set PLL to (HSI/2) * 12 = (8/2) * 12 = 48MHz
    RCC->CFGR |= (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL12);
    // Turn on PLL
    RCC->CR |= RCC_CR_PLLON;
    // Wait untill PLL ready
    while (!(RCC->CR & RCC_CR_PLLRDY)) {
        ;
    }
    // Set PLL as system clock
    // Reset clock select register
    RCC->CFGR &= ~(RCC_CFGR_SW);
    //Select PLL as system clock
    RCC->CFGR |= (RCC_CFGR_SW_PLL);
    // Wait untill system clock ready
    while (!(RCC->CFGR & RCC_CFGR_SW_PLL)) {
        ;
    }
    //Set global clock variable
    core_clock_hz = 48000000;
}