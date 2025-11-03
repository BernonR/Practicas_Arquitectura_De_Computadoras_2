int ValordelSensor;
int ValorMinimoSensor = 1023;
int ValorMaximoSensor = 0;
const int PinLed = 13;

void setup() {
  pinMode(PinLed, OUTPUT);
  digitalWrite(PinLed, HIGH);

  // Calibracion del sensor durante 5 segundos
  while (millis() < 5000) {
    ValordelSensor = analogRead(A0);
    if (ValordelSensor > ValorMaximoSensor) {
      ValorMaximoSensor = ValordelSensor;
    }
    if (ValordelSensor < ValorMinimoSensor) {
      ValorMinimoSensor = ValordelSensor;
    }
  }

  digitalWrite(PinLed, LOW); // Fin de calibracion
}

void loop() {
  ValordelSensor = analogRead(A0);
  int tono = map(ValordelSensor, ValorMinimoSensor, ValorMaximoSensor, 50, 4000);
  tone(8, tono, 20);
  delay(10);
}
