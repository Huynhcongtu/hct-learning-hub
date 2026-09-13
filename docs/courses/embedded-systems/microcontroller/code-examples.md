# Code Examples

<div class="hct-course-banner" markdown>

## Read → Predict → Run → Measure → Modify

Bộ source code được tổ chức để sinh viên không chỉ **copy code**, mà phải dự đoán hành vi,
chạy mô phỏng, đo kết quả và sửa một tham số có kiểm soát.

</div>

## Phân loại nguồn

!!! success "SOURCE"
    `code/labs/L01...L10` và các header trong `code/common/` được lấy từ chương trình tham chiếu
    và phụ lục mã của sổ tay thực hành.

!!! info "SUPPLEMENTAL"
    `code/theory/` và `code/extensions/` là code minh họa bổ sung được biên soạn theo nội dung/yêu cầu
    của học liệu. Chúng không được xem là mã nguyên văn từ tài liệu nguồn.

## 10 Lab reference projects

| Lab | Folder | Nội dung | GitHub | Raw |
|---:|---|---|---|---|
| 01 | L01_Blink | Blink LED active-low; kiểm chứng 500/500 ms và 200/800 ms. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L01_Blink) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L01_Blink/main.c) |
| 02 | L02_Button | Nút nhấn có chống dội; giữ nút chỉ phát một sự kiện. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L02_Button) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L02_Button/main.c) |
| 03 | L03_SevenSegment | Quét bốn LED 7 đoạn bằng Timer 0 ISR và bộ đếm 0000–9999. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L03_SevenSegment) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L03_SevenSegment/main.c) |
| 04 | L04_LCD | LCD 1602 chế độ 4 bit; hiển thị QNU 8051 LAB và COUNT. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L04_LCD) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L04_LCD/main.c) |
| 05 | L05_Matrix | Quét LED matrix 8×8 bằng Timer 0 ISR. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L05_Matrix) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L05_Matrix/main.c) |
| 06 | L06_ADC_LM35 | ADC0804 + LM35; timeout hữu hạn và hiển thị LCD. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L06_ADC_LM35) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L06_ADC_LM35/main.c) |
| 07 | L07_DAC0808 | DAC0808: 5 mức tham chiếu và ramp 256 mức. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L07_DAC0808) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L07_DAC0808/main.c) |
| 08 | L08_PWM | PWM 20 bước bằng Timer 0 mode 2; tải tắt khi reset. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L08_PWM) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L08_PWM/main.c) |
| 09 | L09_IR_NEC | NEC standard polling decoder; repeat/extended frame bị loại. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L09_IR_NEC) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L09_IR_NEC/main.c) |
| 10 | L10_UART | UART 9600 8N1 command interface với LED. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L10_UART) | [main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L10_UART/main.c) |

## 15 Theory examples

| Buổi | Ví dụ | GitHub |
|---:|---|---|
| 01 | Buổi 01 — Bit, dữ liệu và biểu diễn | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W01_Bit_Data_CPU) |
| 02 | Buổi 02 — Mạch tối thiểu và GPIO | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W02_Minimum_System_IO) |
| 03 | Buổi 03 — CODE/DATA và bảng hằng | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W03_CODE_DATA_Addressing) |
| 04 | Buổi 04 — C51, kiểu dữ liệu và build | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W04_C51_Build_Types) |
| 05 | Buổi 05 — GPIO và chống dội | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W05_GPIO_Debounce) |
| 06 | Buổi 06 — Timer và UART | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W06_Timer_UART_Init) |
| 07 | Buổi 07 — Hằng Timer và baud | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W07_Timer_Baud_Calculation) |
| 08 | Buổi 08 — ISR và scheduler | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W08_Interrupt_Scheduler) |
| 09 | Buổi 09 — Dữ liệu chia sẻ với ISR | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W09_Shared_Data_ISR) |
| 10 | Buổi 10 — Bảng mã LED 7 đoạn | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W10_SevenSegment_Table) |
| 11 | Buổi 11 — Dữ liệu LCD/keypad/matrix | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W11_LCD_Keypad_Matrix_Data) |
| 12 | Buổi 12 — I²C open-drain | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W12_I2C_OpenDrain) |
| 13 | Buổi 13 — ADC/DAC calculation | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W13_ADC_DAC_Math) |
| 14 | Buổi 14 — State machine hysteresis | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W14_Thermostat_StateMachine) |
| 15 | Buổi 15 — Ca kiểm thử có thể tái sử dụng | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W15_Portable_Test_Cases) |

## Extensions & Project

| Folder | Nội dung | GitHub |
|---|---|---|
| X01_Keypad | Keypad 4×4: single-key scan, debounce và UART log. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/extensions/X01_Keypad) |
| X02_DS1307 | DS1307: I²C bit-bang, ACK/NACK, BCD time và SET_TIME. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/extensions/X02_DS1307) |
| P01_Thermostat | Project thermostat: ADC0804 + LM35 + LCD + UART + hysteresis 42/38 °C. | [View](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/extensions/P01_Thermostat) |

## Common headers

[common.h](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/common/common.h) ·
[delay.h](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/common/delay.h) ·
[lcd.h](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/common/lcd.h) ·
[uart.h](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/common/uart.h)

## Quy tắc build

1. Mỗi folder là một target.
2. Chọn AT89S52.
3. Xtal = 11.0592 MHz.
4. Create HEX File.
5. Không định nghĩa `HOST_CHECK` khi chạy MCU.
6. Xác nhận HEX vừa được build trước khi nạp/mô phỏng.

## HOST_CHECK

Nếu máy có GCC, có thể kiểm tra **cú pháp**:

```powershell
python code/tools/verify_host.py
```

HOST_CHECK không mô phỏng timer, UART, GPIO hoặc đặc tính điện của 8051.
