#include "common.h"
#include "uart.h"

PIN(HEARTBEAT,P1,0);

void main(void) {
    EA=0;
    HEARTBEAT=1;

    uart_init();
    uart_puts("TIMER/UART READY\r\n");

    /* Timer 0 mode 1, 1 ms nominal reload at 11.0592 MHz / 12T. */
    TMOD=(TMOD & 0xF0)|0x01;
    TH0=0xFC; TL0=0x66; TF0=0; TR0=1;

    for (;;) {
        if(TF0) {
            TR0=0; TF0=0;
            TH0=0xFC; TL0=0x66;
            HEARTBEAT=!HEARTBEAT;
            TR0=1;
        }
    }
}
