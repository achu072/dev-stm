#include "main.h"
#include "common.h"
#include "gpio.h"
#include "exti.h"
#include "led.h"
#include "clk.h"

int main(void){
    CLK_init();
    GPIO_PORT_A_clk_init();
    GPIO_PORT_E_clk_init();
    GPIO_init();
    EXTI_init();

    while(1){
        switch(select) {
            case 0:
                led_on(LD3);
                break;
            case 1:
                led_on(LD4);
                break;
            case 2:
                led_on(LD5);
                break;
            case 3:
                led_on(LD6);
                break;
            case 4:
                led_on(LD7);
                break;
            case 5:
                led_on(LD8);
                break;
            case 6:
                led_on(LD9);
                break;
            case 7:
                led_on(LD10);
                break;
            default:
                break;
        }
    }
}
