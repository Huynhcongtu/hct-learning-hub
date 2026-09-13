#include "common.h"
#include "delay.h"
#include "lcd.h"
void main(void) {
    u8 n=0; EA=0; lcd_init(); lcd_cmd(0x80); lcd_puts("QNU 8051 LAB");
    for (;;) {
        lcd_cmd(0xC0); lcd_puts("COUNT="); lcd_u8_3(n++);
        lcd_puts("       "); delay_ms(500);
    }
}
