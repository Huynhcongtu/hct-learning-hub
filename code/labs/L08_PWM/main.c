#include "common.h"
PIN(PWM_N,P1,0); PIN(KEY,P3,2);
volatile u8 duty_steps=10;
volatile u8 sample_due=0;
void timer0_isr(void) ISR(1) {
    static u8 phase=0,div=0;
    PWM_N=(phase<duty_steps)?0:1;  /* invert through 74HCT14 */
    if(++phase==20)phase=0;
    if(++div==50) { div=0; sample_due=1; }
}
void main(void) {
    u8 stable=1,candidate=1,count=0,sample;
    EA=0; PWM_N=1; KEY=1;
    TMOD=(TMOD&0xF0)|2; TH0=0xA4; TL0=0xA4;
    TF0=0; ET0=1; EA=1; TR0=1;
    for (;;) {
        if(sample_due) {
            sample_due=0; sample=KEY;
            if(sample!=candidate) { candidate=sample; count=0; }
            else if(count<4) {
                if(++count==4 && stable!=candidate) {
                    stable=candidate;
                    if(!stable) { if(duty_steps<20)++duty_steps; else duty_steps=0; }
                }
            }
        }
    }
}
