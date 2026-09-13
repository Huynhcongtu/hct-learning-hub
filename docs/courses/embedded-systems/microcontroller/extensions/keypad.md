# Mở rộng — Keypad 4×4

## Kết nối
- R0–R3 → P1.0–P1.3.
- C0–C3 → P1.4–P1.7.
- Cột kéo lên 10 kΩ.
- P3.1 TXD → RX terminal 9600 8N1.
- GND chung.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/extensions/ext-keypad-4x4.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/extensions/ext-keypad-4x4.png" alt="Ánh xạ keypad 4x4" loading="lazy">
  </a>
  <figcaption>Ánh xạ hàng/cột của bài mở rộng keypad 4×4.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig16-keypad-4x4-scan.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig16-keypad-4x4-scan.png" alt="Nguyên lý quét keypad" loading="lazy">
  </a>
  <figcaption>Cách quét bàn phím bốn hàng bốn cột.</figcaption>
</figure>

## Quy trình
1. Xác định hàng/cột bằng sơ đồ hoặc continuity test.
2. Dựng ma trận, đánh dấu 16 phím.
3. Project dùng `main.c`, `common.h`, `delay.h`, `uart.h`.
4. Nhấn từng phím và kiểm tra terminal.
5. Giữ phím 3 s → không tự lặp.
6. Thử hai phím → ghi giới hạn ghosting.
7. Đổi bảng ký tự mà giữ nguyên driver.

## Sản phẩm
Bảng ký tự đúng/sai, ảnh đấu dây, UART log và giải thích `0xFF` biểu diễn không có phím hợp lệ.


## Code minh họa bổ sung

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/extensions/X01_Keypad){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/extensions/X01_Keypad/main.c){ .md-button }

</div>

```c
#include "common.h"
#include "delay.h"
#include "uart.h"

u8 ROM keymap[16]={
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
};

/* Returns 0xFF when no valid single key is detected.
 * Rows=P1.0..P1.3, columns=P1.4..P1.7, columns pulled up. */
static u8 keypad_scan_once(void) {
    u8 row,cols,col;

    for(row=0;row<4u;row++) {
        P1=0xFFu;
        P1 &= (u8)~(1u<<row);
        NOP(); NOP();

        cols=(u8)((P1>>4)&0x0Fu);
        if(cols!=0x0Fu) {
            for(col=0;col<4u;col++) {
                if((cols & (1u<<col))==0u)
                    return keymap[row*4u+col];
            }
        }
    }

    return 0xFFu;
}

void main(void) {
    u8 stable=0xFFu,candidate=0xFFu,sample,count=0;

    EA=0;
    P1=0xFFu;
    uart_init();
    uart_puts("KEYPAD READY\r\n");

    for(;;) {
        sample=keypad_scan_once();

        if(sample!=candidate) {
            candidate=sample;
            count=0;
        } else if(count<4u) {
            ++count;
            if(count==4u && stable!=candidate) {
                stable=candidate;
                if(stable!=0xFFu) {
                    uart_puts("KEY=");
                    uart_putc(stable);
                    uart_puts("\r\n");
                }
            }
        }

        delay_ms(5);
    }
}
```

!!! info
    Đây là **SUPPLEMENTAL implementation** được viết theo yêu cầu của bài mở rộng/project trong học liệu.
    Tài liệu nguồn không cung cấp nguyên văn chương trình đầy đủ này.

