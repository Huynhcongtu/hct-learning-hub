#include "common.h"

typedef struct {
    u8 input;
    u8 output;
} sample_t;

static u8 transform(u8 x) {
    return (u8)((x ^ 0x0Fu) | 0x80u);
}

void main(void) {
    sample_t s;
    s.input = 0x35u;
    s.output = transform(s.input);

    P1 = s.input;
    P2 = s.output;

    for (;;) { }
}
