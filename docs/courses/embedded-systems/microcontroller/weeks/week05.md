# BUỔI 05 — C, GPIO & chống dội

**Đọc trước:** Giáo trình trang **17–23**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Khai báo chân theo chức năng và giữ nguyên bit không liên quan.
- Giải thích quasi-bidirectional của port 8051.
- Phân biệt input active-low với output active-low.
- Thiết kế debounce theo trạng thái ổn định và sự kiện.

=== "PRE · Đọc trước"

    1. Đọc trang **17–23**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### GPIO
    8051 dùng cơ chế port khác MCU hiện đại. Để đọc một chân port quasi-bidirectional, phần mềm thường phải “thả” chân bằng cách ghi 1 trước.

    ### Bit operations
    Dùng mask để tránh phá các chân khác:
    - `x & mask` đọc.
    - `x | mask` đặt bit.
    - `x & ~mask` xóa bit.

    ### Chống dội
    Không đảo LED ở mọi vòng lặp khi nút đang giữ. Cần tách:
    - trạng thái mẫu,
    - candidate,
    - stable state,
    - sự kiện nhấn mới.

    Một cấu hình thực hành dùng 4 mẫu × 5 ms ≈ 20 ms để xác nhận ổn định.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Thiết kế máy trạng thái nút nhấn sao cho giữ nút 3 s chỉ tạo một sự kiện.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Vì sao `P1 && 0x08` không kiểm tra riêng P1.3?
    2. Giữ nút có nên tạo nhiều lần toggle?
    3. Cửa sổ debounce có phải luôn đúng 20 ms?

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
