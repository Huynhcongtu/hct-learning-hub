#include "common.h"

typedef struct {
    u8 input;
    u8 expected;
} test_case_t;

test_case_t ROM cases[]={
    {35u,0u},
    {42u,1u},
    {40u,1u},
    {38u,0u}
};

void main(void) {
    u8 i;

    /* The table is deliberately platform-independent:
     * the same functional cases can be reused after porting to another MCU. */
    for(i=0;i<4u;i++) {
        P1=cases[i].input;
        P2=cases[i].expected;
    }

    for (;;) { }
}
