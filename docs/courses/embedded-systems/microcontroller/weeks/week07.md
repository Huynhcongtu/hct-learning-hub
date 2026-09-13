# TUẦN 07 — ADC

**Analog-to-Digital Conversion**

<div class="week-meta">
<div><small>Mục tiêu tuần</small><strong>Lấy mẫu tín hiệu analog</strong></div>
<div><small>Minh chứng</small><strong>ADC concept</strong></div>
<div><small>Lab focus</small><strong>Analog sensor</strong></div>
</div>

## Learning Outcomes

Sau tuần này, sinh viên có thể:

- Giải thích khái niệm cốt lõi của **ADC**.
- Đọc sơ đồ / dữ liệu liên quan và xác định tham số quan trọng.
- Triển khai một ví dụ tối thiểu có thể kiểm chứng.
- Ghi lại kết quả và giải thích sai khác giữa kỳ vọng và thực tế.

=== "PRE · Chuẩn bị"

    ## Before class

    - Đọc khái niệm chính.
    - Ghi lại thuật ngữ kỹ thuật.
    - Xem sơ đồ khối / timing diagram.
    - Đọc đúng phần datasheet cần thiết.

    !!! question "Self-check"
        Viết **01 câu hỏi** mà bạn muốn được giải đáp trên lớp.

=== "LEC · Bài giảng"

    1. Mô hình và nguyên lý.
    2. Tham số cấu hình.
    3. Trình tự khởi tạo.
    4. Ví dụ code tối thiểu.
    5. Lỗi thường gặp.
    6. Cách kiểm chứng output.

=== "SIM · Mô phỏng"

    **Mục tiêu:** quan sát hành vi trước khi chạy phần cứng.

    Ghi nhận:

    - input,
    - expected output,
    - observed output,
    - nhận xét.

=== "LAB · Thực hành"

    ## LAB 07

    **Nhiệm vụ:** Analog sensor

    1. Kiểm tra wiring / pin mapping.
    2. Mở starter project.
    3. Cấu hình peripheral.
    4. Build.
    5. Flash firmware.
    6. Quan sát output.
    7. Thay đổi một tham số và giải thích kết quả.

    ```c
    int main(void)
    {
        // TODO: init hardware

        while (1)
        {
            // TODO: application loop
        }
    }
    ```

=== "QUIZ · Tự kiểm tra"

    [Mở Quiz tuần 07](https://forms.google.com/){ .md-button .md-button--primary }

    Gợi ý: câu hỏi khái niệm, timing, chẩn đoán lỗi và dự đoán output.

=== "ASG · Bài tập"

    Nộp một **engineering note** ngắn gồm:

    - Mục tiêu.
    - Sơ đồ / cấu hình.
    - Code quan trọng.
    - Minh chứng output.
    - Một lỗi đã gặp và cách xử lý.
    - Kết luận.

## Checklist

- [ ] PRE
- [ ] LEC
- [ ] SIM
- [ ] LAB
- [ ] QUIZ
- [ ] ASG
