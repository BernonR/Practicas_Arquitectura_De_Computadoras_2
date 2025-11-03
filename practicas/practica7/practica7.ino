#include <OneWire.h>          // Biblioteca para comunicación OneWire
#include <DallasTemperature.h> // Biblioteca para el sensor de temperatura DS18B20

OneWire ourWire(2);            // Configura el pin 2 para OneWire
DallasTemperature sensors(&ourWire); // Inicializa el sensor con la referencia OneWire

void setup() {
  delay(1000);                 // Espera 1 segundo para inicialización
  Serial.begin(9600);          // Inicia comunicación serial a 9600 baudios
  sensors.begin();             // Inicia el sensor de temperatura
}

void loop() {
  sensors.requestTemperatures();           // Solicita lectura de temperatura
  float temp = sensors.getTempCByIndex(0); // Lee temperatura en Celsius del primer dispositivo
  
  Serial.print("Temperatura = ");          // Imprime texto en monitor serial
  Serial.print(temp);                      // Imprime valor de temperatura
  Serial.println(" C ");                   // Imprime unidad y nueva línea
  delay(100);                              // Espera 100ms antes de repetir
}