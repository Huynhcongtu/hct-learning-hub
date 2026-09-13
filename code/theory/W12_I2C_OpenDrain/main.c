#include "common.h"

PIN(SDA,P1,0);
PIN(SCL,P1,1);

static void i2c_delay(void) {
    NOP(); NOP(); NOP(); NOP();
}

static void i2c_start(void) {
    SDA=1; SCL=1; i2c_delay();
    SDA=0; i2c_delay();
    SCL=0;
}

static void i2c_stop(void) {
    SDA=0; SCL=1; i2c_delay();
    SDA=1; i2c_delay();
}

void main(void) {
    SDA=1; SCL=1;

    for (;;) {
        i2c_start();
        i2c_stop();
    }
}
