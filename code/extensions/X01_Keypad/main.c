#include "common.h"
#include "delay.h"
#include "uart.h"

u8 ROM keymap[16]={
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
};

/* Returns 0xFF when no valid single key is detected.
 * Rows=P1.0..P1.3, columns=P1.4..P1.7, columns pulled up. */
static u8 keypad_scan_once(void) {
    u8 row,cols,col;

    for(row=0;row<4u;row++) {
        P1=0xFFu;
        P1 &= (u8)~(1u<<row);
        NOP(); NOP();

        cols=(u8)((P1>>4)&0x0Fu);
        if(cols!=0x0Fu) {
            for(col=0;col<4u;col++) {
                if((cols & (1u<<col))==0u)
                    return keymap[row*4u+col];
            }
        }
    }

    return 0xFFu;
}

void main(void) {
    u8 stable=0xFFu,candidate=0xFFu,sample,count=0;

    EA=0;
    P1=0xFFu;
    uart_init();
    uart_puts("KEYPAD READY\r\n");

    for(;;) {
        sample=keypad_scan_once();

        if(sample!=candidate) {
            candidate=sample;
            count=0;
        } else if(count<4u) {
            ++count;
            if(count==4u && stable!=candidate) {
                stable=candidate;
                if(stable!=0xFFu) {
                    uart_puts("KEY=");
                    uart_putc(stable);
                    uart_puts("\r\n");
                }
            }
        }

        delay_ms(5);
    }
}
