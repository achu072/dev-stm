#ifndef __LED_H
#define __LED_H

#define LD3 3
#define LD4 4
#define LD5 5
#define LD6 6
#define LD7 7
#define LD8 8
#define LD9 9
#define LD10 10

void led_on(uint8_t led);
void led_off(uint8_t led);
void led_toggle(uint8_t led);

#endif /* __LED_H */