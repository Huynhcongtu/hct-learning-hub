#include "common.h"

/* Data-only example for display-oriented lessons. */
u8 ROM glyph_Q[8]={
    0x3C,0x42,0x81,0x81,
    0x91,0xA1,0x42,0xBC
};

u8 ROM keypad_map[16]={
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
};

void main(void) {
    u8 i=0;

    for (;;) {
        P1=(u8)~glyph_Q[i];
        P2=keypad_map[i & 15u];
        i=(i+1u)&7u;
    }
}
