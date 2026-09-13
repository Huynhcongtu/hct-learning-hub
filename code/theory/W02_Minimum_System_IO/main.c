#include "common.h"

PIN(LED, P1, 0);

void main(void) {
    EA = 0;
    LED = 1; /* active-low LED: OFF */

    for (;;) {
        /* Hardware exercise:
         * verify VCC, GND, EA, RST and clock before debugging code. */
        LED = 0;
        NOP(); NOP(); NOP();
        LED = 1;
        NOP(); NOP(); NOP();
    }
}
