#ifndef QNU_DELAY_H
#define QNU_DELAY_H
/* Blocking delay. Owns Timer 0. 11.0592 MHz, classic 12T only.
 * Approximate 1 ms + software overhead. Never call with T0 ISR active. */
static void delay_ms(u16 n) {
    TMOD = (TMOD & 0xF0) | 0x01;
    while (n--) {
        TR0=0; TH0=0xFC; TL0=0x66; TF0=0; TR0=1;
        while (!TF0) { }
        TR0=0; TF0=0;
    }
}
#endif
