#ifndef QNU_LCD_H
#define QNU_LCD_H
PIN(LCD_RS,P3,5);
PIN(LCD_E,P3,4);
/* RW=GND; D4..D7=P2.4..P2.7. Requires delay.h, owns T0. */
static void lcd_nibble(u8 x) {
    P2=(P2 & 0x0F) | ((x & 0x0F)<<4);
    NOP(); NOP(); LCD_E=1; NOP(); NOP(); LCD_E=0;
    NOP(); NOP();
}
static void lcd_byte(u8 x,u8 rs) {
    LCD_RS=rs; lcd_nibble(x>>4); lcd_nibble(x);
    delay_ms(1);  /* conservative, not high speed */
}
static void lcd_cmd(u8 x) {
    lcd_byte(x,0); if (x==1 || x==2) delay_ms(2);
}
static void lcd_init(void) {
    LCD_E=0; LCD_RS=0; delay_ms(40);
    lcd_nibble(3); delay_ms(5);
    lcd_nibble(3); delay_ms(1);
    lcd_nibble(3); delay_ms(1);
    lcd_nibble(2); delay_ms(1);
    lcd_cmd(0x28); lcd_cmd(0x0C); lcd_cmd(0x06); lcd_cmd(1);
}
static void lcd_puts(char *s) { while (*s) lcd_byte(*s++,1); }
static void lcd_u8_3(u8 x) {
    lcd_byte('0'+x/100,1);
    lcd_byte('0'+(x/10)%10,1);
    lcd_byte('0'+x%10,1);
}
#endif
