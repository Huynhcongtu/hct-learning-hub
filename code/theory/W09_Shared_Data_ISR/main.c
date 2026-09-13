#include "common.h"

volatile u16 tick=0;

void timer0_isr(void) ISR(1) {
    TH0=0xFC; TL0=0x66;
    ++tick;
}

static u16 tick_snapshot(void) {
    u8 old_ea=EA;
    u16 copy;

    EA=0;
    copy=tick;
    EA=old_ea;

    return copy;
}

void main(void) {
    u16 t;

    EA=0;
    TMOD=(TMOD&0xF0)|1;
    TH0=0xFC; TL0=0x66;
    ET0=1; EA=1; TR0=1;

    for (;;) {
        t=tick_snapshot();
        P1=(u8)t;
        P2=(u8)(t>>8);
    }
}
