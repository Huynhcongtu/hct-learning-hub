#include "common.h"
#include "delay.h"
#include "lcd.h"
#include "uart.h"

PIN(ADC_RD,P3,6);
PIN(ADC_WR,P3,7);
PIN(ADC_INTR,P3,2);
PIN(FAN_LED,P2,0); /* active-low LED models the fan */

static u8 adc_read(u8 *value) {
    u16 guard=50000u;

    P1=0xFF;
    ADC_RD=1;
    ADC_WR=0; NOP(); NOP(); ADC_WR=1;

    while(ADC_INTR && --guard) { }

    if(ADC_INTR) return 0;

    ADC_RD=0; NOP(); NOP();
    *value=P1;
    ADC_RD=1;

    return 1;
}

void main(void) {
    u8 raw;
    u8 fan_on=0;
    u8 telemetry_div=0;

    EA=0;
    P1=0xFF;
    ADC_RD=1; ADC_WR=1; ADC_INTR=1;
    FAN_LED=1;

    uart_init();
    lcd_init();
    lcd_cmd(0x80);
    lcd_puts("QNU THERMOSTAT");

    for(;;) {
        if(adc_read(&raw)) {
            /* With VFS=2.56 V and LM35=10 mV/degC, raw ~= degC. */
            if(!fan_on && raw>=42u) fan_on=1;
            else if(fan_on && raw<=38u) fan_on=0;

            FAN_LED=fan_on ? 0 : 1;

            lcd_cmd(0xC0);
            lcd_puts("TEMP=");
            lcd_u8_3(raw);
            lcd_puts(fan_on ? " ON " : " OFF");

            if(++telemetry_div>=5u) {
                telemetry_div=0;
                uart_puts("RAW=");
                uart_hex(raw);
                uart_puts(fan_on ? " FAN=ON\r\n" : " FAN=OFF\r\n");
            }
        } else {
            FAN_LED=1;
            fan_on=0;
            lcd_cmd(0xC0);
            lcd_puts("ADC TIMEOUT ");
            uart_puts("ADC TIMEOUT\r\n");
        }

        delay_ms(200);
    }
}
