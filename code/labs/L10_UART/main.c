#include "common.h"
#include "uart.h"
PIN(LED,P1,0);
void main(void) {
    u8 c; EA=0; LED=1; uart_init();
    uart_puts("QNU UART 9600 8N1\r\n");
    for (;;) if(RI) {
        c=SBUF; RI=0;
        if(c=='1') { LED=0; uart_puts("ACK ON\r\n"); }
        else if(c=='0') { LED=1; uart_puts("ACK OFF\r\n"); }
        else if(c=='?') uart_puts(LED?"STATE=0\r\n":"STATE=1\r\n");
        else if(c!='\r' && c!='\n')uart_puts("ERR\r\n");
    }
}
