// Declaración de variables de tipo entero

int ledPin = 9;    // Declaracion del pin 9 como salida PMM (conectar led)
int analogPin = 0;   // conectar un potenciometro a la entrada analogica A0
int valor = 0;    // variable entera para almacenar el valor de lectura e incializada en 0

void setup()
{
    pinMode(ledPin, OUTPUT);   // se establece el pin9 como salida
    Serial.begin(9600);  //iniciamos la comunicacion serial, velocidad de 9600 bits por segundo
}

void loop()
{
    valor = analogRead(analogPin);   // Lee el valor del potenciometro en el pin A0 que van de 0 a 1023
    analogWrite(ledPin, valor/4);  // analogWrite los valores van de 0 a 255, PMM tiene una resolución de 256
    // El led interpreta la intensidad como el valor de PMM
    Serial.println(valor);    // Muestra el valor entero que se encuentra en la entrada anlogica A0
    delay(500);    // Modificar el tiempo, suavismo la respuesta del cambio del PMM
}