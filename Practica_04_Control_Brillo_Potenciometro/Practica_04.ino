int potPin = 0; // Pin del potenciómetro (analógico)
int ledPin = 1; // Pin del LED
int value = 0; // Variable para almacenar el valor leído del potenciómetro

void setup()
{
    pinMode(ledPin, OUTPUT); // Establece el pin del LED como salida
}

void loop()
{
    value = analogRead(potPin); // Lee el valor del potenciómetro (0-1023)
    digitalWrite(ledPin, HIGH); // Enciende el LED
    delay(value); // Espera un tiempo proporcional al valor del potenciómetro
    digitalWrite(ledPin, LOW); // Apaga el LED
    delay(value); // Espera nuevamente el mismo tiempo
}
