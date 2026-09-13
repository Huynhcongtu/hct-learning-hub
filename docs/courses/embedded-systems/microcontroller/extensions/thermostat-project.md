# Project — Bộ giám sát nhiệt độ có hysteresis

## Thành phần
LM35 + ADC0804 + LCD + LED active-low mô phỏng quạt + UART monitor.

## Chức năng
- đọc ADC;
- hiển thị nhiệt độ;
- hysteresis;
- telemetry UART;
- ADC timeout → báo lỗi và đưa tải về trạng thái an toàn.

## Ca thử tham chiếu
Dùng chuỗi Vin:

1. `0.35 V`
2. `0.42 V`
3. `0.40 V`
4. `0.38 V`

Kỳ vọng:

```text
OFF → ON → giữ ON → OFF
```

Ngưỡng mẫu của học liệu: **42 °C bật / 38 °C tắt**.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/extensions/project-thermostat-hysteresis.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/extensions/project-thermostat-hysteresis.png" alt="Ca thử thermostat" loading="lazy">
  </a>
  <figcaption>Ca thử hai ngưỡng của dự án tích hợp.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig28-temperature-hysteresis.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig28-temperature-hysteresis.png" alt="Hysteresis" loading="lazy">
  </a>
  <figcaption>Hai ngưỡng khác nhau ngăn đầu ra đổi liên tục quanh một mức nhiệt.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" alt="Chuỗi đo nhiệt độ" loading="lazy">
  </a>
  <figcaption>Chuỗi đo nhiệt độ với LM35, ADC0804 và LCD.</figcaption>
</figure>

## Quy trình
1. Lab 06 phải đạt trước.
2. Lập bảng pin/Timer.
3. Kiểm tra LCD không ghi đè chân tải.
4. Thêm output và UART.
5. Test từng khối.
6. Test hysteresis.
7. Cố ý mất clock ADC → timeout, không treo.
8. Phân biệt RAW ADC trên UART và nhiệt độ trên LCD.
9. Đo response time.

## Bản nâng cao
Thiết kế không chặn với system tick, UART RX ISR, ring buffer, timeout và lịch cập nhật LCD.

## Hồ sơ bàn giao
Specification, resource table, schematic, source+HEX, Proteus, test matrix, measurements, video ngắn, một quyết định thiết kế và một giới hạn còn tồn tại.


## Code minh họa bổ sung

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/extensions/P01_Thermostat){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/extensions/P01_Thermostat/main.c){ .md-button }

</div>

```c
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
```

!!! info
    Đây là **SUPPLEMENTAL implementation** được viết theo yêu cầu của bài mở rộng/project trong học liệu.
    Tài liệu nguồn không cung cấp nguyên văn chương trình đầy đủ này.

