#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean estadoLED = LOW;

void setup() {
  irrecv.enableIRIn(); // Inicializa recepción IR
  pinMode(13, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    estadoLED = !estadoLED;
    digitalWrite(13, estadoLED ? HIGH : LOW);
    irrecv.resume(); // Listo para nueva lectura
  }
  delay(300);
}
