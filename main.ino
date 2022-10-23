#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Vo;
float R1 = 97000; // resistencia fija del divisor de tension
float logR2, R2, TEMPERATURA;
float c1 = 0.6767648808e-03, c2 = 2.230548473e-04, c3 = 0.7158393331e-07; // coeficientes de S-H

float tempShow = 0;

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
}

void loop()
{
  Vo = analogRead(A0);                                                  // lectura de A0
  R2 = R1 * (1023.0 / (float)Vo - 1.0);                                 // conversion de tension a resistencia
  logR2 = log(R2);                                                      // logaritmo de R2 necesario para ecuacion
  TEMPERATURA = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // ecuacion S-H
  TEMPERATURA = TEMPERATURA - 273.15;                                   // Kelvin a Centigrados (Celsius)

  if (tempShow == 0)
  {
    tempShow = TEMPERATURA;
  }

  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.println(" C");

  if (((tempShow + 0.5) <= TEMPERATURA) || ((tempShow - 0.5) >= TEMPERATURA))
  {
    tempShow = TEMPERATURA;
    lcd.print(TEMPERATURA);
    lcd.print("C");
    lcd.setCursor(0, 1);
  }

  delay(500);
}