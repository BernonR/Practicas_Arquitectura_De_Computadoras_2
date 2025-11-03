int tiempo = 100;
int n;
const int pulsador = 12;
int estado = 0;

void setup()
{
    pinMode(12, INPUT);
    for(n = 1; n <= 10; n++)
    {
        pinMode(n, OUTPUT);
    }
}

void secuencia()
{
    for(n = 1; n <= 10; n++)
    {
        digitalWrite(n, HIGH);
        delay(tiempo);
        digitalWrite(n, LOW);
        delay(tiempo);
    }

    for(n = 10; n >= 1; n--)
    {
        digitalWrite(n, HIGH);
        delay(tiempo);
        digitalWrite(n, LOW);
        delay(tiempo);
    }
}

void loop()
{
    estado = digitalRead(pulsador);
    if(estado == HIGH)
    {
        secuencia();
    }
}
