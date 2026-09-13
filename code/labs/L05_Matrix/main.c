#include "common.h"
/* Logical bit 1 = illuminated. P2 rows through PNP, P1 cathode columns. */
u8 ROM glyph[8]={0x3C,0x42,0x81,0x81,0x91,0xA1,0x42,0xBC};
void timer0_isr(void) ISR(1) {
    static u8 row=0;
    TH0=0xFC; TL0=0x66;
    P2=0xFF; P1=(u8)~glyph[row];
    P2=(u8)~(1u<<row); row=(row+1)&7;
}
void main(void) {
    EA=0; P1=0xFF; P2=0xFF;
    TMOD=(TMOD&0xF0)|1; TH0=0xFC; TL0=0x66;
    TF0=0; ET0=1; EA=1; TR0=1;
    for (;;) { }
}
