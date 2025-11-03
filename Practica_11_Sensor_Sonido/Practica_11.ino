int MIC_D = 12;
int MIC_A = 0;
int LED = 2;
int VALOR;
bool SONIDO;

void setup() {
  Serial.begin(9600);
  pinMode(MIC_D, INPUT);
  pinMode(MIC_A, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  VALOR = analogRead(MIC_A);
  Serial.println(VALOR);
  delay(500);

  SONIDO = digitalRead(MIC_D);

  if (SONIDO == HIGH) {
    Serial.println("SE DETECTO SONIDO");
    digitalWrite(LED, HIGH);
    delay(100);
  } else {
    digitalWrite(LED, LOW);
    delay(100);
  }
}
