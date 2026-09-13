# BUỔI 10 — Nguồn, bus & LED 7 đoạn

**Đọc trước:** Giáo trình trang **21, 34–35, 52–53**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Thiết kế LED theo cực tính và giới hạn dòng.
- Tạo bảng mã 7 đoạn.
- Giải thích multiplexing và ghosting.
- Nhận biết xung đột tài nguyên/chân khi mở rộng hệ thống.

=== "PRE · Đọc trước"

    1. Đọc trang **21, 34–35, 52–53**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### LED 7 đoạn
    Bảy segment a–g tạo chữ số. Mã hiển thị phụ thuộc common-anode/common-cathode và ánh xạ bit.

    ### Multiplex
    Bốn digit dùng chung bus segment. Trình tự an toàn:

    ```text
    tắt tất cả digit
    → đổi segment
    → bật digit mới
    ```

    Làm ngược dễ gây **ghosting**.

    ### Tài nguyên
    Không chỉ kiểm tra “trùng chân”; còn phải kiểm tra trùng Timer, bus, ISR và giới hạn dòng.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Từ sơ đồ common-anode, xây bảng mã 0–9 và giải thích mẫu cho 0, 1, 8.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Vì sao phải tắt digit cũ trước khi đổi segment?
    2. Duty mỗi digit ảnh hưởng độ sáng thế nào?
    3. Không trùng pin có chắc không trùng tài nguyên?

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
