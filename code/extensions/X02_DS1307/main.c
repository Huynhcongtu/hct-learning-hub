#include "common.h"
#include "uart.h"

PIN(SDA,P1,0);
PIN(SCL,P1,1);

#define DS1307_ADDR 0x68u
#define SET_TIME 0

static void i2c_delay(void) {
    NOP(); NOP(); NOP(); NOP();
}

static u8 scl_high(void) {
    u16 guard=5000u;
    SCL=1;
    while(!SCL && --guard) { }
    return SCL ? 1u : 0u;
}

static void i2c_start(void) {
    SDA=1; SCL=1; i2c_delay();
    SDA=0; i2c_delay();
    SCL=0;
}

static void i2c_stop(void) {
    SDA=0; i2c_delay();
    scl_high(); i2c_delay();
    SDA=1; i2c_delay();
}

static u8 i2c_write(u8 x) {
    u8 i,ack;

    for(i=0;i<8u;i++) {
        SDA=(x & 0x80u) ? 1 : 0;
        i2c_delay();
        if(!scl_high()) return 0;
        i2c_delay();
        SCL=0;
        x<<=1;
    }

    SDA=1;
    i2c_delay();
    if(!scl_high()) return 0;
    ack=(SDA==0);
    SCL=0;
    return ack;
}

static u8 i2c_read(u8 ack) {
    u8 i,x=0;

    SDA=1;
    for(i=0;i<8u;i++) {
        x<<=1;
        if(!scl_high()) return 0;
        if(SDA) x|=1u;
        SCL=0;
    }

    SDA=ack ? 0 : 1;
    i2c_delay();
    scl_high();
    SCL=0;
    SDA=1;

    return x;
}

static u8 ds1307_write_reg(u8 reg,u8 value) {
    i2c_start();
    if(!i2c_write((u8)(DS1307_ADDR<<1))) { i2c_stop(); return 0; }
    if(!i2c_write(reg))                  { i2c_stop(); return 0; }
    if(!i2c_write(value))                { i2c_stop(); return 0; }
    i2c_stop();
    return 1;
}

static u8 ds1307_read_hms(u8 *hh,u8 *mm,u8 *ss) {
    i2c_start();
    if(!i2c_write((u8)(DS1307_ADDR<<1))) { i2c_stop(); return 0; }
    if(!i2c_write(0x00u))                { i2c_stop(); return 0; }

    i2c_start();
    if(!i2c_write((u8)((DS1307_ADDR<<1)|1u))) { i2c_stop(); return 0; }

    *ss=i2c_read(1);
    *mm=i2c_read(1);
    *hh=i2c_read(0);
    i2c_stop();

    if((*ss & 0x80u)!=0u) return 0; /* CH must be 0 */
    if((*hh & 0x40u)!=0u) return 0; /* sample expects 24-hour mode */

    return 1;
}

void main(void) {
    u8 hh,mm,ss;

    EA=0;
    SDA=1; SCL=1;
    uart_init();
    uart_puts("DS1307 READY\r\n");

#if SET_TIME
    ds1307_write_reg(0x00u,0x00u);
    ds1307_write_reg(0x01u,0x00u);
    ds1307_write_reg(0x02u,0x12u);
#endif

    for(;;) {
        if(ds1307_read_hms(&hh,&mm,&ss)) {
            uart_hex(hh); uart_putc(':');
            uart_hex(mm); uart_putc(':');
            uart_hex(ss); uart_puts("\r\n");
        } else {
            uart_puts("RTC ERROR\r\n");
        }

        /* Deliberately simple teaching loop; not a calibrated 1 s scheduler. */
        {
            u16 wait=60000u;
            while(--wait) { NOP(); }
        }
    }
}
