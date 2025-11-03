// Programa para controlar un LED con un botón y contar las veces que se presiona

// Definimos los pines que usaremos y las variables
int led = 2;           // Pin donde está conectado el LED
int boton = 13;         // Pin donde está conectado el botón
int valor = 0;          // Para guardar el estado actual del botón
int contador = 0;       // Cuenta cuántas veces se ha presionado el botón
int estadoAnteriorBoton = 0;  // Guarda el estado anterior del botón

void setup()
{
    Serial.begin(9600);         // Iniciamos la comunicación con la computadora
    pinMode(led, OUTPUT);       // Decimos que el pin del LED es de salida
    pinMode(boton, INPUT);      // Decimos que el pin del botón es de entrada
}

void loop()
{
    valor = digitalRead(boton);     // Leemos si el botón está presionado o no
    digitalWrite(led, valor);       // Encendemos o apagamos el LED según el botón
    
    // Detectamos cuando el botón cambia de estado
    if(valor != estadoAnteriorBoton)
    {
        // Solo contamos cuando se presiona el botón (no cuando se suelta)
        if(valor == HIGH)
        {
            contador++;             // Aumentamos el contador en 1
            Serial.println(contador); // Enviamos el conteo a la computadora
        }
    }
    estadoAnteriorBoton = valor;    // Guardamos el estado actual para la próxima vez
    delay(10);                      // Pequeña pausa para que funcione estable
}
