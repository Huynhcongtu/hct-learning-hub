#include "common.h"

u8 ROM seg_ca[10]={
    0xC0,0xF9,0xA4,0xB0,0x99,
    0x92,0x82,0xF8,0x80,0x90
};

void main(void) {
    u8 digit=0;

    P1=0xFF;
    for (;;) {
        P2=seg_ca[digit];
        digit++;
        if(digit==10u) digit=0;
    }
}
