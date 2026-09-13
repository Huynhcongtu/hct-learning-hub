#include "common.h"
#include "delay.h"
PIN(MODE_KEY,P3,2);
u8 ROM levels[5]={0,64,128,192,255};
void main(void) {
    u8 i=0,d=0; EA=0; P1=0; MODE_KEY=1;
    for (;;) {
        if(MODE_KEY) { P1=levels[i]; delay_ms(1000); if(++i==5)i=0; }
        else { P1=d++; delay_ms(1); }
    }
}
