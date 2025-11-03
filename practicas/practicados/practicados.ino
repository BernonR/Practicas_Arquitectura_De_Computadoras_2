// C++ code
// Encendido de LED en secuencia

int tiempo = 70;
int n;

void setup()
{
  for (n = 0; n <= 9; n++)
  {
    pinMode(n, OUTPUT);
  }
}

void loop()
{
  for (n = 0; n <= 9; n++)
  {
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }
}
