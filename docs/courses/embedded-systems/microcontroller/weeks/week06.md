# BUỔI 06 — Timer & UART

**Đọc trước:** Giáo trình trang **24–27, 31–33**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Phân biệt timer và counter.
- Cấu hình TMOD/TCON có thứ tự an toàn.
- Giải thích Timer mode 1/mode 2.
- Mô tả UART mode 1, SBUF, RI, TI và 8N1.

=== "PRE · Đọc trước"

    1. Đọc trang **24–27, 31–33**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Timer
    Timer tăng theo nhịp nội; counter tăng theo xung ngoài. Cấu hình nên dừng timer, đặt mode, nạp giá trị, xóa cờ rồi mới chạy.

    ### Mode 1
    16 bit, phù hợp khoảng thời gian dài hơn.

    ### Mode 2
    8 bit auto-reload, phù hợp tick định kỳ và nguồn baud.

    ### UART
    Mode 1 thường dùng khung 8N1. TXD/RXD là mức logic UART, **không nối trực tiếp RS-232 điện áp cao**.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Vẽ timeline một chu kỳ Timer và một frame UART 8N1, chỉ ra điểm cần đo.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Khác nhau giữa Timer mode 1 và mode 2?
    2. RI/TI được dùng cho việc gì?
    3. Vì sao UART logic 5 V không phải RS-232?

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
