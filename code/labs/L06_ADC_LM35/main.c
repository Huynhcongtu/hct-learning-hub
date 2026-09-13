#include "common.h"
#include "delay.h"
#include "lcd.h"
PIN(ADC_RD,P3,6); PIN(ADC_WR,P3,7); PIN(ADC_INTR,P3,2);
static u8 adc_read(u8 *value) {
    u16 guard=50000u;
    P1=0xFF; ADC_RD=1; ADC_WR=0; NOP(); NOP(); ADC_WR=1;
    while(ADC_INTR && --guard) { }
    if(ADC_INTR) return 0;
    ADC_RD=0; NOP(); NOP(); *value=P1; ADC_RD=1;
    return 1;
}
void main(void) {
    u8 raw;
    EA=0; P1=0xFF; ADC_RD=1; ADC_WR=1; ADC_INTR=1;
    lcd_init(); lcd_cmd(0x80); lcd_puts("LM35 VFS=2.56V");
    for (;;) {
        if(adc_read(&raw)) {
            lcd_cmd(0xC0); lcd_puts("TEMP="); lcd_u8_3(raw);
            lcd_puts(" C      ");
        } else {
            lcd_cmd(0xC0); lcd_puts("ADC TIMEOUT     ");
        }
        delay_ms(200);
    }
}
