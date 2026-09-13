#include "common.h"
u8 ROM seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
volatile u16 tick=0;
volatile u8 digits[4]={0,0,0,0};
void timer0_isr(void) ISR(1) {
    static u8 pos=0;
    TH0=0xFC; TL0=0x66;
    P1 |= 0x0F;                 /* all PNP digit selectors off */
    P2=seg[digits[pos]];
    P1=(P1 & 0xF0) | (0x0F ^ (1u<<pos));
    pos=(pos+1)&3; ++tick;
}
static u16 now(void) {
    u8 e=EA; u16 t; EA=0; t=tick; EA=e; return t;
}
static void show(u16 n) {
    u8 d[4],e;
    d[0]=n/1000; d[1]=(n/100)%10; d[2]=(n/10)%10; d[3]=n%10;
    e=EA; EA=0;
    digits[0]=d[0]; digits[1]=d[1]; digits[2]=d[2]; digits[3]=d[3];
    EA=e;
}
void main(void) {
    u16 last=0,n=0,t;
    EA=0; P1=0xFF; P2=0xFF; TMOD=(TMOD&0xF0)|1;
    TH0=0xFC; TL0=0x66; TF0=0; ET0=1; EA=1; TR0=1;
    for (;;) {
        t=now();
        if((u16)(t-last)>=500u) {
            last=t; if(++n==10000u)n=0; show(n);
        }
    }
}
