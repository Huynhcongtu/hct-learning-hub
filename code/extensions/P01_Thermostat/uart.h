#ifndef QNU_UART_H
#define QNU_UART_H
static void uart_init(void) {
    TMOD=(TMOD & 0x0F)|0x20; PCON &= 0x7F;
    SCON=0x50; TH1=0xFD; TL1=0xFD; RI=0; TI=0; TR1=1;
}
/* Finite software-loop timeout. Iteration bound, not calibrated time. */
static u8 uart_putc(u8 c) {
    u16 guard=60000u; TI=0; SBUF=c;
    while (!TI && --guard) { }
    if (!TI) return 0; TI=0; return 1;
}
static void uart_puts(char *s) { while (*s) { if(!uart_putc(*s++)) break; } }
static void uart_hex(u8 x) {
    u8 h=x>>4,l=x&15;
    uart_putc(h<10?'0'+h:'A'+h-10);
    uart_putc(l<10?'0'+l:'A'+l-10);
}
#endif
