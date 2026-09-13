#include "common.h"

volatile u16 ticks=0;
volatile u8 task_10ms=0;
volatile u8 task_100ms=0;

void timer0_isr(void) ISR(1) {
    TH0=0xFC; TL0=0x66;
    ++ticks;

    if((ticks % 10u)==0u) task_10ms=1;
    if((ticks % 100u)==0u) task_100ms=1;
}

void main(void) {
    EA=0;
    TMOD=(TMOD&0xF0)|1;
    TH0=0xFC; TL0=0x66;
    TF0=0; ET0=1; EA=1; TR0=1;

    for (;;) {
        if(task_10ms) {
            task_10ms=0;
            P1 ^= 0x01u;
        }
        if(task_100ms) {
            task_100ms=0;
            P2 ^= 0x01u;
        }
    }
}
