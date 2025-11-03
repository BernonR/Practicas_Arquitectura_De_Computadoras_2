/*
  PRACTICA #18 - COMUNICACION SPI ENTRE ARDUINOS
  Autor: Bernon Romero
  Descripción:
  Ejemplo unificado de comunicación SPI Maestro/Esclavo Full Duplex.
  Cambia la constante MODO_MAESTRO a false para ejecutar como Esclavo.
*/

#include <SPI.h>
#define MODO_MAESTRO true

#if MODO_MAESTRO
// --------------------------- MAESTRO ---------------------------
char mensaje[] = "BR";
byte recibido;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  Serial.println("== MODO MAESTRO SPI INICIADO ==");
}

void loop() {
  digitalWrite(10, LOW);
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  for (byte i = 0; i < sizeof(mensaje); i++) {
    recibido = SPI.transfer(mensaje[i]);
    Serial.print("Envio: ");
    Serial.print(mensaje[i]);
    Serial.print(" | Recibio: ");
    Serial.println((char)recibido);
    delay(500);
  }
  SPI.endTransaction();
  digitalWrite(10, HIGH);
  delay(1000);
}

#else
// --------------------------- ESCLAVO ---------------------------
volatile byte recibido;
byte respuesta;

void setup() {
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  Serial.println("== MODO ESCLAVO SPI INICIADO ==");
}

ISR(SPI_STC_vect) {
  recibido = SPDR;
  respuesta = recibido + 1;
  SPDR = respuesta;
}

void loop() {
  Serial.print("Recibido: ");
  Serial.print((char)recibido);
  Serial.print(" -> Enviado: ");
  Serial.println((char)respuesta);
  delay(1000);
}
#endif
