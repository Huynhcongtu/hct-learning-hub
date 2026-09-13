#include "common.h"
#include "delay.h"

PIN(LED,P1,0);
PIN(KEY,P3,2);

void main(void) {
    u8 stable=1, candidate=1, sample, count=0;

    EA=0; LED=1; KEY=1;

    for (;;) {
        sample=KEY;

        if(sample!=candidate) {
            candidate=sample;
            count=0;
        } else if(count<4) {
            ++count;
            if(count==4 && stable!=candidate) {
                stable=candidate;
                if(stable==0) LED=!LED;
            }
        }

        delay_ms(5);
    }
}
