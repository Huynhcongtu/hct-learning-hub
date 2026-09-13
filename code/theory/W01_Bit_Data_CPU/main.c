#include "common.h"

/* Supplemental example: bit masking and data interpretation. */
static u8 set_bit1_clear_bit6(u8 x) {
    x &= (u8)~0x40u;
    x |= 0x02u;
    return x;
}

void main(void) {
    u8 x = 0xCDu;
    u8 y = set_bit1_clear_bit6(x);

    /* Put values on ports so they can be inspected in simulator. */
    P1 = x;
    P2 = y;

    for (;;) { }
}
