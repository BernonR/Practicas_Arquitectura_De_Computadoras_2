// Medidor_de_luz

const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;
const int ledPin6 = 7;
const int ledPin7 = 8;
const int ledPin8 = 9;
const int ledPin9 = 10;
const int ledPin10 = 11;
const int LDRPin = 0;
int val = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LDRPin);
  Serial.println(val);
  medidor();
}

void medidor() {
  if (val > 100) {
    digitalWrite(ledPin1, HIGH);
  }
  else {
    digitalWrite(ledPin1, LOW);
  }

  if (val > 200) {
    digitalWrite(ledPin2, HIGH);
  }
  else {
    digitalWrite(ledPin2, LOW);
  }

  if (val > 300) {
    digitalWrite(ledPin3, HIGH);
  }
  else {
    digitalWrite(ledPin3, LOW);
  }

  if (val > 400) {
    digitalWrite(ledPin4, HIGH);
  }
  else {
    digitalWrite(ledPin4, LOW);
  }

  if (val > 500) {
    digitalWrite(ledPin5, HIGH);
  }
  else {
    digitalWrite(ledPin5, LOW);
  }

  if (val > 600) {
    digitalWrite(ledPin6, HIGH);
  }
  else {
    digitalWrite(ledPin6, LOW);
  }

  if (val > 700) {
    digitalWrite(ledPin7, HIGH);
  }
  else {
    digitalWrite(ledPin7, LOW);
  }

  if (val > 800) {
    digitalWrite(ledPin8, HIGH);
  }
  else {
    digitalWrite(ledPin8, LOW);
  }

  if (val > 900) {
    digitalWrite(ledPin9, HIGH);
  }
  else {
    digitalWrite(ledPin9, LOW);
  }

  if (val > 1000) {
    digitalWrite(ledPin10, HIGH);
  }
  else {
    digitalWrite(ledPin10, LOW);
  }
}
