#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Temperatura:"); 
  lcd.setCursor (0,1);
}
void loop() { 
  lcd.print("20 ");
  lcd.print("C");
  lcd.setCursor (0,1);
  delay(500);
}
