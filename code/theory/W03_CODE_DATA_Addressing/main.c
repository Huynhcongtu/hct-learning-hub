#include "common.h"

u8 ROM seven_seg[4] = {0xC0, 0xF9, 0xA4, 0xB0};

void main(void) {
    u8 index = 0;
    u8 value;

    for (;;) {
        value = seven_seg[index]; /* constant table: CODE on Keil C51 */
        P2 = value;
        index = (index + 1u) & 3u;
    }
}
