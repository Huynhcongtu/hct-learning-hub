#include "common.h"
#include "delay.h"
PIN(LED,P1,0);
void main(void) {
    EA=0; LED=1;
    for (;;) { LED=0; delay_ms(500); LED=1; delay_ms(500); }
}
