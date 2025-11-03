int tiempo = 70;  // Tiempo de espera entre LEDs
int n;            // Variable auxiliar para recorrer los pines

void setup() {
  // Configura los pines 0 al 9 como salidas digitales
  for (n = 0; n <= 9; n++) {
    pinMode(n, OUTPUT);
  }
}

void loop() {
  // Encendido secuencial de los LEDs
  for (n = 0; n <= 9; n++) {
    digitalWrite(n, HIGH); // Enciende el LED actual
    delay(tiempo);         // Espera
    digitalWrite(n, LOW);  // Apaga el LED
    delay(tiempo);         // Pausa antes del siguiente
  }
}
