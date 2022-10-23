int Vo;
float R1 = 97000;   // resistencia fija del divisor de tension
float logR2, R2, TEMPERATURA;
float c1 = 0.6767648808e-03, c2 = 2.230548473e-04, c3 = 0.7158393331e-07;   // coeficientes de S-H


void setup()
{
    Serial.begin(9600); // inicializa comunicacion serie a 9600 bps
}

void loop()
{
    Vo = analogRead(A0);                                                  // lectura de A0
    R2 = R1 * (1023.0 / (float)Vo - 1.0);                                 // conversion de tension a resistencia
    logR2 = log(R2);                                                      // logaritmo de R2 necesario para ecuacion
    TEMPERATURA = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // ecuacion S-H
    TEMPERATURA = TEMPERATURA - 273.15;                                   // Kelvin a Centigrados (Celsius)

    Serial.print("Temperatura: "); // imprime valor en monitor serie
    Serial.print(TEMPERATURA);
    Serial.println(" C");
    delay(500); // demora de medio segundo entre lecturas
}