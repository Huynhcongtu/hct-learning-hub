# BUỔI 04 — Assembly, C & quy trình build

**Đọc trước:** Giáo trình trang **14–20**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Đọc được MOV, MOVC, MOVX và các thao tác bit cơ bản.
- Theo vết vòng lặp, rẽ nhánh, gọi hàm.
- Chọn kiểu dữ liệu C theo miền giá trị.
- Hiểu volatile, module, array/pointer và quy trình source → HEX.

=== "PRE · Đọc trước"

    1. Đọc trang **14–20**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Assembly cần đọc được
    Tập trung vào di chuyển dữ liệu, thao tác bit, số học, so sánh, nhảy và gọi hàm. Mục tiêu là **đọc và giải thích luồng**, không chỉ ghi nhớ mnemonic.

    ### C cho 8051
    - Chọn kiểu theo miền giá trị.
    - Cẩn thận phép toán trung gian.
    - `volatile` cần cho dữ liệu có thể thay đổi ngoài luồng bình thường, nhưng không tự tạo tính nguyên tử.
    - Tách driver khỏi application.

    ### Build
    Một bản source tạo ra chương trình qua compiler/linker rồi sinh HEX. Build log, map file và HEX đều là minh chứng kỹ thuật.

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Cho một đoạn C51 có array, con trỏ và biến volatile; xác định dữ liệu nào nên ở CODE/RAM và rủi ro.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Vì sao volatile không thay cho critical section?
    2. Tại sao bảng hằng lớn nên cân nhắc đặt trong CODE?
    3. HEX có thay thế được source khi chấm bài không?

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
