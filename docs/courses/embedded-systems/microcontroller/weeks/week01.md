# BUỔI 01 — Hệ thống nhúng, hệ đếm & CPU

**Đọc trước:** Giáo trình trang **4–7**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Phân biệt hệ thống nhúng với máy tính đa dụng.
- Mô tả chuỗi Sensor → CPU/Memory → Actuator.
- Chuyển đổi binary/hexadecimal và hiểu cùng mẫu bit có nhiều cách diễn giải.
- Giải thích vai trò ALU, PC, thanh ghi, stack và không gian CODE/DATA.

=== "PRE · Đọc trước"

    1. Đọc trang **4–7**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### 1. Hệ thống nhúng và yêu cầu thời gian
    Vi điều khiển đọc tín hiệu vào, xử lý theo quy tắc và tạo tín hiệu ra. Một kết quả tính đúng nhưng xuất quá muộn vẫn có thể là **sai hệ thống**.

    ### 2. Hệ đếm
    Một byte có 8 bit. Hexadecimal gom 4 bit thành một chữ số, rất phù hợp khi đọc thanh ghi.

    Ví dụ:
    - `173 = 1010 1101₂ = 0xAD`.
    - `0x31` có thể là số 49, ASCII `'1'` hoặc tám tín hiệu độc lập.

    ### 3. Signed data
    Bù hai 8 bit biểu diễn từ −128 đến 127. Mẫu `0xFB` có thể là 251 không dấu hoặc −5 có dấu.

    ### 4. CPU
    8051 có A, B, DPTR, PSW, PC; chương trình nằm trong CODE, biến thay đổi nằm trong DATA/RAM.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Phân tích bộ đếm người ra/vào: input, output, thời gian đáp ứng, trạng thái lỗi.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Vì sao LED sáng đúng nhưng chậm 3 s có thể vẫn là kết quả sai?
    2. Khác nhau giữa `7`, `'7'` và chuỗi ký tự `"7"`?
    3. PC khác biến đếm của người lập trình như thế nào?

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
