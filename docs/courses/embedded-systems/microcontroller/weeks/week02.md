# BUỔI 02 — Sơ đồ chân, mạch tối thiểu & bộ nhớ

**Đọc trước:** Giáo trình trang **8–10**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Đọc sơ đồ chân AT89S52 PDIP40.
- Giải thích nguồn, clock, reset và EA.
- Phân biệt dung lượng Flash thực với không gian CODE.
- Phân biệt truy cập trực tiếp SFR và truy cập gián tiếp RAM cao.

=== "PRE · Đọc trước"

    1. Đọc trang **8–10**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### AT89S52 tham chiếu
    AT89S52 tương thích tập lệnh 8051, có 8 KiB Flash, 256 byte RAM và Timer 2. Bài cốt lõi ưu tiên Timer 0/1 và GPIO để dễ chuyển đổi.

    ### Mạch tối thiểu
    - VCC 40, GND 20.
    - EA 31 lên VCC khi chạy Flash nội.
    - XTAL1/XTAL2 dùng 11.0592 MHz.
    - RST tích cực cao.
    - Tụ 100 nF đặt gần VCC/GND.

    ### Bộ nhớ
    Không gian CODE có thể địa chỉ hóa 64 KiB nhưng Flash vật lý của AT89S52 chỉ 8 KiB.
    Trong vùng 80H–FFH, truy cập trực tiếp chọn SFR; truy cập gián tiếp có thể chọn RAM cao trên S52.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** VCC = 5 V nhưng LED không chạy và RST ≈ 5 V liên tục. Xác định thứ tự kiểm tra.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. P3.0/P3.1 còn là GPIO độc lập khi UART đang hoạt động không?
    2. Vì sao 64 KiB CODE không có nghĩa chip có sẵn 64 KiB Flash?
    3. Tại sao phải kiểm tra EA trước khi sửa code?

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
