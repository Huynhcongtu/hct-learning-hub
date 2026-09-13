#include "common.h"
#include "uart.h"
PIN(IR_IN,P3,2); PIN(LED,P1,0);
/* Counts in machine cycles, 11.0592 MHz/12. Standard NEC only.
 * Polling decoder for a dedicated lab. Repeat/extended frames rejected. */
static u16 measure(u8 level) {
    u16 t;
    TR0=0; TH0=0; TL0=0; TF0=0; TR0=1;
    while(IR_IN==level && !TF0) { }
    TR0=0;
    if(TF0) return 0;
    t=((u16)TH0<<8)|TL0; return t;
}
static u8 receive_nec(u8 *cmd) {
    u8 b[4]={0,0,0,0},i; u16 t;
    if(IR_IN) { if(measure(1)==0) return 0; }
    t=measure(0); if(t<7000u || t>9500u)return 0;
    t=measure(1); if(t<3200u || t>5000u)return 0;
    for(i=0;i<32;i++) {
        t=measure(0); if(t<350u || t>750u)return 0;
        t=measure(1);
        if(t>1100u && t<2000u) b[i>>3]|=(1u<<(i&7));
        else if(t<350u || t>750u)return 0;
    }
    t=measure(0); if(t<350u || t>750u)return 0;
    if((u8)(b[0]^b[1])!=0xFF || (u8)(b[2]^b[3])!=0xFF)return 0;
    *cmd=b[2]; return 1;
}
void main(void) {
    u8 cmd; EA=0; IR_IN=1; LED=1; uart_init();
    TMOD=(TMOD&0xF0)|1;
    uart_puts("NEC READY\r\n");
    for (;;) if(receive_nec(&cmd)) {
        uart_puts("CMD="); uart_hex(cmd); uart_puts("\r\n");
        if(cmd==0x45)LED=0; else if(cmd==0x46)LED=1;
    }
}
