#include "common.h"

/* Constants are derived for 11.0592 MHz, classic 12T. */
#define T0_1MS_H 0xFCu
#define T0_1MS_L 0x66u
#define UART_9600_TH1 0xFDu

void main(void) {
    P1 = T0_1MS_H;
    P2 = T0_1MS_L;
    P3 = UART_9600_TH1;

    /* Exercise: derive constants again if Fosc changes. */
    for (;;) { }
}
