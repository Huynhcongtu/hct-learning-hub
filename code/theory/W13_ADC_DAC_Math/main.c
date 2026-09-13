#include "common.h"

/* VFS = 2.56 V -> 10 mV/LSB.
 * LM35 = 10 mV/degC, so nominal raw code ~= temperature in degC. */
static u8 lm35_degC_from_raw(u8 raw) {
    return raw;
}

/* Idealized DAC0808 teaching estimate:
 * 255 is one LSB below an exact 256/256 full scale. */
static u16 dac_millivolt_ideal(u8 code) {
    return (u16)(((unsigned long)code * 4000ul) / 256ul);
}

void main(void) {
    u8 adc_raw=37u;
    u8 temp=lm35_degC_from_raw(adc_raw);
    u16 mv=dac_millivolt_ideal(128u);

    P1=temp;
    P2=(u8)(mv/100u);

    for (;;) { }
}
