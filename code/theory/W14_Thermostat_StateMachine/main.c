#include "common.h"

typedef enum {
    FAN_OFF=0,
    FAN_ON=1,
    SENSOR_FAULT=2
} fan_state_t;

static fan_state_t update_state(fan_state_t state, u8 adc_ok, u8 temp) {
    if(!adc_ok) return SENSOR_FAULT;

    if(state==FAN_ON) {
        if(temp<=38u) return FAN_OFF;
        return FAN_ON;
    }

    if(temp>=42u) return FAN_ON;
    return FAN_OFF;
}

void main(void) {
    fan_state_t state=FAN_OFF;

    state=update_state(state,1,35);
    state=update_state(state,1,42);
    state=update_state(state,1,40);
    state=update_state(state,1,38);

    P1=(u8)state;
    for (;;) { }
}
