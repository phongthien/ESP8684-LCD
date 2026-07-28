#include <Arduino.h>
#include <U8g2lib.h>

#define LCD_CS   10
#define LCD_RST   5
#define LCD_CLK   6
#define LCD_MOSI  7
#define LCD_BL    4

U8G2_ST7565_ERC12864_F_4W_SW_SPI lcd(
  U8G2_R0,
  LCD_CLK,
  LCD_MOSI,
  LCD_CS,
  LCD_RST
);

void setup() {
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);

  lcd.begin();

  lcd.clearBuffer();
  lcd.setFont(u8g2_font_ncenB14_tr);
  lcd.drawStr(15, 30, "Hello");
  lcd.drawStr(8, 55, "ESP8684");
  lcd.sendBuffer();
}

void loop() {
  digitalWrite(LCD_BL, HIGH);
  delay(500);
  digitalWrite(LCD_BL, LOW);
  delay(500);
}
