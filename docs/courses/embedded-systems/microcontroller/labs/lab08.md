# LAB 08 — PWM & tải điện áp thấp

**Đọc trước:** Giáo trình trang **26 và 46–47**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Tạo PWM 20 bước bằng timer auto-reload, thay duty theo nút và bảo đảm tải tắt khi reset.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| P1.0 | Qua 74HCT14 tới Gate MOSFET |
| Gate | 100 Ω + pull-down 100 kΩ |
| Motor | 5 V + diode flyback |
| P3.2 | Nút pull-up 10 kΩ |
| Ground | Logic/tải chung có kiểm soát |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/labs/lab08-pwm-motor-driver.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/labs/lab08-pwm-motor-driver.png" alt="Sơ đồ Lab 08 PWM motor" loading="lazy">
  </a>
  <figcaption>Minh họa nguyên lý PWM và tầng công suất tải điện áp thấp.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig21-pwm-duty-cycle.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig21-pwm-duty-cycle.png" alt="Duty cycle PWM" loading="lazy">
  </a>
  <figcaption>Cùng chu kỳ nhưng duty khác nhau tạo mức tác động trung bình khác nhau.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig22-reset-safe-power-stage.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig22-reset-safe-power-stage.png" alt="Power stage reset-safe" loading="lazy">
  </a>
  <figcaption>Tầng công suất được thiết kế để tải tắt khi MCU reset.</figcaption>
</figure>

## Quy trình từng bước

1. Chưa nối motor; đo trước/sau inverter; reset→Gate thấp.
2. Đọc TH0=0xA4 và 20 phase; tự tính.
3. Đo duty 50%, chu kỳ ~1.997 ms theo cấu hình mẫu.
4. Thử 0/35/50/100%.
5. Ghi DC ở 0/100%.
6. Kiểm tra MOSFET/diode rồi mới nối motor.
7. Đo VCC khi motor start.
8. Nộp waveform + duty table + reset test.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 0% | Gate thấp |
| 35% | 7/20 |
| 50% | 10/20 |
| 100% | Gate cao |
| Reset | Gate thấp |
| Giữ nút | Không auto-repeat |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Motor chạy khi reset | Polarity/pull-down |
| Duty đọc ngược | Điểm đo trước/sau inverter |
| Reset lúc start | Nguồn/nhiễu/mass |

## Phân tích sau thực hành

1. Vì sao 20 bước có 21 giá trị kể cả 0/100?
2. Duty có bằng % tốc độ motor không?


## Code tham chiếu

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L08_PWM){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L08_PWM/main.c){ .md-button }

</div>

```c
#include "common.h"
PIN(PWM_N,P1,0); PIN(KEY,P3,2);
volatile u8 duty_steps=10;
volatile u8 sample_due=0;
void timer0_isr(void) ISR(1) {
    static u8 phase=0,div=0;
    PWM_N=(phase<duty_steps)?0:1;  /* invert through 74HCT14 */
    if(++phase==20)phase=0;
    if(++div==50) { div=0; sample_due=1; }
}
void main(void) {
    u8 stable=1,candidate=1,count=0,sample;
    EA=0; PWM_N=1; KEY=1;
    TMOD=(TMOD&0xF0)|2; TH0=0xA4; TL0=0xA4;
    TF0=0; ET0=1; EA=1; TR0=1;
    for (;;) {
        if(sample_due) {
            sample_due=0; sample=KEY;
            if(sample!=candidate) { candidate=sample; count=0; }
            else if(count<4) {
                if(++count==4 && stable!=candidate) {
                    stable=candidate;
                    if(!stable) { if(duty_steps<20)++duty_steps; else duty_steps=0; }
                }
            }
        }
    }
}
```

!!! note "Nguồn"
    Đây là chương trình tham chiếu **SOURCE** từ sổ tay thực hành.
    Các header cần thiết được đặt cùng thư mục project để đúng quy ước mỗi bài là một target riêng.

## Bằng chứng nộp

- source C + header;
- HEX vừa build;
- project/schematic Proteus;
- bảng ca thử có **số đo thực**;
- waveform/ảnh đo có đơn vị;
- ảnh KIT nếu đã thử;
- mô tả ít nhất một lỗi và cách xử lý.

!!! info
    Nếu mới hoàn thành mô phỏng, phải ghi rõ **“chưa thử KIT”**.
