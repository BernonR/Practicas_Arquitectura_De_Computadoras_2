int SENSOR; // Variable entera, almacena valor leído de entrada analógica A0
float TEMPERATURA; // Variable que maneja puntos decimales, almacena el valor de temperatura en grados centígrados

void setup()
{
    Serial.begin(9600); // Inicialización de la comunicación serial a 9600 baudios
    // Las entradas analógicas no requieren inicialización (pinMode) en Arduino
}

void loop()
{
    SENSOR = analogRead(A0); // Lectura de entrada analógica A0, guardada en la variable
    TEMPERATURA = ((5.0 * SENSOR * 100.0) / 1024.0); // Fórmula para convertir valor leído en grados centígrados

    Serial.print("Temperatura: ");
    Serial.print(TEMPERATURA, 1); // Imprime con un decimal
    Serial.println(" °C"); // Añade unidad y salto de línea
    
    delay(1000); // Pausa de 1 segundo entre lecturas
}