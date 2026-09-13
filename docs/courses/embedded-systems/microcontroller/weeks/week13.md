# BUỔI 13 — ADC, DAC & thiết kế ngoại vi

**Đọc trước:** Giáo trình trang **40–45, 55–56**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Giải thích sampling, quantization và reference.
- Giao tiếp ADC0804 và xử lý timeout.
- Tính chuyển đổi LM35.
- Mô tả DAC0808 + tầng I/V và dạng sóng từ bảng mẫu.

=== "PRE · Đọc trước"

    1. Đọc trang **40–45, 55–56**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### ADC0804
    Chu kỳ: khởi động chuyển đổi → chờ INTR → đọc bus. Vòng chờ phải có timeout.

    Với `VREF/2 = 1.280 V`, toàn thang xấp xỉ 2.56 V. Ghép LM35 10 mV/°C tạo phép quy đổi thuận tiện trong bài.

    ### DAC0808
    DAC tạo dòng theo mã; op-amp I/V đổi dòng thành điện áp. Phải kiểm tra MSB/LSB, IREF, Rf, nguồn op-amp và dấu điện áp.

    ### Waveform
    Nếu bảng có N mẫu và cập nhật với tần số `fs`, tần số sóng xấp xỉ `fs/N`.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig18-adc-quantization.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig18-adc-quantization.png" alt="Lượng tử hóa ADC" loading="lazy">
      </a>
      <figcaption>Hình 18. Lượng tử hóa điện áp thành các mức số.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" alt="Chuỗi đo LM35 ADC0804 LCD" loading="lazy">
      </a>
      <figcaption>Hình 19. Chuỗi đo nhiệt độ với LM35, ADC0804 và LCD.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig20-dac0808-current-to-voltage.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig20-dac0808-current-to-voltage.png" alt="DAC0808 và tầng I/V" loading="lazy">
      </a>
      <figcaption>Hình 20. DAC0808 cần tầng chuyển dòng sang điện áp.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig21-pwm-duty-cycle.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig21-pwm-duty-cycle.png" alt="PWM với duty khác nhau" loading="lazy">
      </a>
      <figcaption>Hình 21. Cùng chu kỳ nhưng duty khác nhau tạo mức tác động trung bình khác nhau.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Tính mã ADC danh định ở 37 °C với full-scale 2.56 V; phân tích nguồn sai số.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. VREF/2 có phải full-scale không?
    2. Timeout ADC bảo vệ hệ thống khỏi lỗi gì?
    3. Mã DAC 255 có đạt đúng 100% full-scale lý tưởng không?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.

## Checklist

- [ ] Đọc phần được giao
- [ ] Làm phép tính / self-check
- [ ] Có ít nhất một câu hỏi
- [ ] Hoàn thành hoạt động
- [ ] Lưu bằng chứng
