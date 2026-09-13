# BUỔI 14 — Tích hợp dự án & kiểm thử

**Đọc trước:** Giáo trình trang **54–60**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Viết yêu cầu có thể kiểm thử.
- Phân bổ pin, Timer, ISR và bus trước khi tích hợp.
- Thiết kế test plan song song với chức năng.
- Dùng hysteresis, watchdog và startup state hợp lý.

=== "PRE · Đọc trước"

    1. Đọc trang **54–60**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Hồ sơ thiết kế tối thiểu
    - Bản yêu cầu: dải, đơn vị, timing, lỗi, startup.
    - Sơ đồ phần cứng: nguồn, chân, cực tính, điểm đo.
    - Kiến trúc phần mềm: module, state, scheduler, ownership.
    - Kế hoạch test: input, expected, measured.
    - Hồ sơ bàn giao: source, HEX, schematic, config, log.

    ### Thermostat mẫu
    LM35 + ADC0804 + LCD + đầu ra mô phỏng quạt. Ví dụ dùng **42 °C bật / 38 °C tắt** để tránh chatter.

    ### Watchdog
    Watchdog chỉ có ý nghĩa khi phần mềm khỏe vẫn phục vụ nó; lỗi phần cứng có thể gây vòng reset lặp.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig27-measurement-debug-flow.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig27-measurement-debug-flow.png" alt="Quy trình khoanh vùng lỗi" loading="lazy">
      </a>
      <figcaption>Hình 27. Trình tự khoanh vùng lỗi dựa trên phép đo.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig28-temperature-hysteresis.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig28-temperature-hysteresis.png" alt="Hysteresis nhiệt độ" loading="lazy">
      </a>
      <figcaption>Hình 28. Hai ngưỡng khác nhau ngăn đầu ra đổi liên tục quanh một mức nhiệt.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Lập resource allocation table cho ADC + LCD + UART + tải; tìm xung đột pin và Timer.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Hysteresis giải quyết vấn đề gì?
    2. Watchdog có thay timeout ngoại vi không?
    3. Tại sao test plan nên viết trước khi hệ hoàn thành?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W14_Thermostat_StateMachine){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W14_Thermostat_StateMachine/main.c){ .md-button }

</div>

```c
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
```

!!! info
    Code ở mục này là **SUPPLEMENTAL**: ví dụ bổ sung theo nội dung buổi học,
    không phải đoạn mã nguyên văn của giáo trình.

## Checklist

- [ ] Đọc phần được giao
- [ ] Làm phép tính / self-check
- [ ] Có ít nhất một câu hỏi
- [ ] Hoàn thành hoạt động
- [ ] Lưu bằng chứng
