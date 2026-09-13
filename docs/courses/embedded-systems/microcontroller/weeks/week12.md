# BUỔI 12 — Motor, I²C & DS1307

**Đọc trước:** Giáo trình trang **46–51, 57**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Điều khiển tải cảm qua driver, diode và nguồn phù hợp.
- Giải thích open-drain của I²C.
- Phân biệt địa chỉ 7 bit và byte address+R/W.
- Đọc/ghi DS1307 và hiểu BCD.

=== "PRE · Đọc trước"

    1. Đọc trang **46–51, 57**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Tải cảm
    GPIO không trực tiếp cấp dòng cho motor. Cần driver, diode flyback, mass có kiểm soát và trạng thái **tắt khi reset**.

    ### I²C
    SDA/SCL dùng open-drain và điện trở kéo lên. Thiết bị trả ACK/NACK sau byte.

    ### DS1307
    - Địa chỉ 7 bit: `0x68`.
    - SDA/SCL cần pull-up.
    - Dữ liệu thời gian dùng BCD.
    - Bit CH liên quan chạy/dừng oscillator.
    - Pin dự phòng giữ thời gian khi mất nguồn logic nếu cấu hình đúng.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig22-reset-safe-power-stage.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig22-reset-safe-power-stage.png" alt="Tầng công suất an toàn khi reset" loading="lazy">
      </a>
      <figcaption>Hình 22. Tầng công suất có trạng thái tắt khi MCU reset.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig25-i2c-pullups.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig25-i2c-pullups.png" alt="Hai đường I2C có điện trở kéo lên" loading="lazy">
      </a>
      <figcaption>Hình 25. Hai đường I²C có điện trở kéo lên riêng.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Giải thích vì sao byte write có thể là D0H trong khi địa chỉ 7 bit là 68H.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Tại sao không được điều khiển SDA/SCL push-pull tùy ý?
    2. BCD 0x59 khác số nhị phân 0x59 ở cách diễn giải nào?
    3. Đầu ra motor nên ở trạng thái nào khi reset?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W12_I2C_OpenDrain){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W12_I2C_OpenDrain/main.c){ .md-button }

</div>

```c
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
