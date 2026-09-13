# Toolchain, Proteus & KIT

## 1. Cấu hình thống nhất

| Thành phần | Giá trị |
|---|---|
| MCU | AT89S52 PDIP40 |
| VCC | 5 V |
| Clock | 11.0592 MHz |
| Core | 12T |
| Compiler | Keil C51 |
| Simulator | Proteus |
| Measurement | Multimeter + oscilloscope / logic analyzer |

<figure class="hct-figure">
  <a href="../../../../assets/images/microcontroller/theory/fig04-at89s52-pinout.png" target="_blank" rel="noopener">
    <img src="../../../../assets/images/microcontroller/theory/fig04-at89s52-pinout.png" alt="Pinout AT89S52" loading="lazy">
  </a>
  <figcaption>Sơ đồ chân AT89S52 PDIP40 — dùng để đối chiếu với KIT thực.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../assets/images/microcontroller/theory/fig05-at89s52-minimum-system.png" target="_blank" rel="noopener">
    <img src="../../../../assets/images/microcontroller/theory/fig05-at89s52-minimum-system.png" alt="Mạch tối thiểu AT89S52" loading="lazy">
  </a>
  <figcaption>Kết nối tối thiểu: nguồn, clock, reset và EA.</figcaption>
</figure>

## 2. Tạo project bằng Keil C51

1. Tạo đường dẫn ngắn, ví dụ `C:\QNU_8051\L01`.
2. Chép `main.c` và các header của đúng bài vào cùng thư mục.
3. **Project → New µVision Project**.
4. Chọn đúng AT89S52.
5. Chỉ thêm `main.c` của bài hiện tại vào target.
6. Trong **Options for Target** đặt `Xtal = 11.0592 MHz`.
7. Dùng mô hình bộ nhớ `small` cho các bài nhỏ nếu đúng cấu hình được cấp.
8. Trong **Output**, bật **Create HEX File**.
9. Build/Rebuild và sửa **lỗi đầu tiên** trước.
10. Kiểm tra thời gian sửa đổi của HEX để tránh chạy nhầm file cũ.

!!! danger "HEX cũ"
    Build thất bại nhưng file HEX cũ vẫn có thể còn trên đĩa.
    Không dùng HEX cũ để kết luận mã mới hoạt động.

<figure class="hct-figure">
  <a href="../../../../assets/images/microcontroller/theory/fig07-build-sim-program-flow.png" target="_blank" rel="noopener">
    <img src="../../../../assets/images/microcontroller/theory/fig07-build-sim-program-flow.png" alt="Build simulation programming flow" loading="lazy">
  </a>
  <figcaption>Chuỗi source → build → HEX → simulation → programming → hardware verification.</figcaption>
</figure>

## 3. Proteus

1. Tạo schematic project tương ứng từng Lab.
2. Chọn AT89S52 hoặc mô hình tương thích đúng chức năng.
3. Dựng đầy đủ nguồn, clock, reset và ngoại vi.
4. Gán **Program File** tới HEX mới.
5. Đặt **Clock Frequency = 11.0592 MHz**.
6. Gắn oscilloscope/logic analyzer đúng điểm đo.
7. Chạy cùng một ca trước và sau khi sửa để so sánh.
8. Ảnh waveform phải có **nhãn tín hiệu + đơn vị + thang thời gian**.

## 4. Trước khi cấp nguồn KIT

- Đúng chip và đúng chiều.
- Đúng VCC/GND.
- Không chạm nguồn.
- Reset không bị giữ ở trạng thái tác động.
- Clock đúng.
- LED có điện trở.
- Tải công suất đi qua driver.
- Ngắt nguồn trước khi thay dây.

## 5. Quy trình nạp AT89S52

1. Tắt nguồn.
2. Xác nhận bộ nạp hỗ trợ **đúng AT89S52**.
3. Đối chiếu MOSI P1.5, MISO P1.6, SCK P1.7, RST, VCC, GND.
4. Đọc signature/nhận dạng thiết bị.
5. Chọn HEX mới.
6. Erase → Program → Verify.
7. Đưa reset về trạng thái chạy.
8. Chạy lại bộ ca thử.

!!! info "AT89C51"
    Không áp dụng quy trình ISP nối tiếp của AT89S52 cho AT89C51.
    Nếu dùng AT89C51 phải dùng bộ nạp đúng loại và kiểm tra khác biệt RAM/ROM/Timer.
