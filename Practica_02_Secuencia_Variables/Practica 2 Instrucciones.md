# 🔹 Práctica #2 – Secuencia de LEDs con Variables

## 🎯 Objetivo
Aprender el uso de las **salidas digitales** en Arduino y la implementación de **variables** para optimizar el código, reduciendo líneas repetidas mediante el uso de bucles y valores almacenados.

---

## 🧰 Listado de Componentes
- 🔌 Cables de conexión  
- 🧠 Arduino UNO  
- 💡 10 LEDs  
- ⚙️ 10 resistencias de **330 Ω**  
- 🧱 Protoboard  

---

## 📝 Descripción
En esta práctica se programa el **encendido y apagado secuencial de 10 LEDs**, pero ahora utilizando **variables y bucles for()** para **ahorrar código** y hacerlo más flexible.  
El tiempo de encendido se controla mediante una variable (`tiempo`), lo que permite modificar fácilmente la velocidad de la secuencia.

---

## ⚙️ Instrucciones Principales

| Instrucción | Descripción |
|--------------|-------------|
| `pinMode(pin, OUTPUT)` | Configura el pin como salida digital. |
| `digitalWrite(pin, valor)` | Envía señal al pin (HIGH = encendido / LOW = apagado). |
| `delay(tiempo)` | Pausa el programa el tiempo indicado (en milisegundos). |
| `for()` | Crea un bucle que repite las instrucciones un número determinado de veces. |

---

## 💻 Código Original (Comentado)

```cpp
/* -----------------------------------------------------------
   PRACTICA #2 – Secuencia de LEDs con Variables
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Pines utilizados: 0 al 9
   Librerías necesarias: (Ninguna)
----------------------------------------------------------- */

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

💡 Explicación del Código

Se define una variable tiempo que controla el retardo entre encendidos.

La variable n se usa dentro del bucle for() para recorrer los pines del 0 al 9.

En cada iteración, el LED correspondiente se enciende y luego se apaga.

Este proceso se repite indefinidamente en el loop().

🔌 Guía de Conexiones

Conecta el pin 5V del Arduino a la línea positiva (+) del protoboard.

Conecta el pin GND del Arduino a la línea negativa (–).

Coloca 10 LEDs en el protoboard, uno por fila.

Conecta la pata larga (ánodo) de cada LED a una resistencia de 330 Ω.

Conecta el otro extremo de cada resistencia a los pines 0 al 9 del Arduino UNO.

Conecta la pata corta (cátodo) de cada LED a la línea GND (–).

⚙️ Pines Utilizados
Pin Arduino	LED
0	LED 1
1	LED 2
2	LED 3
3	LED 4
4	LED 5
5	LED 6
6	LED 7
7	LED 8
8	LED 9
9	LED 10
✅ Verificación

Todos los LEDs deben tener una resistencia individual.

El ánodo (pata larga) va al pin digital (a través de la resistencia).

El cátodo (pata corta) va a la línea GND (–).

Verifica las conexiones antes de subir el código.

🔎 Resultado Esperado

Los 10 LEDs se encienden uno tras otro en secuencia rápida, creando un efecto de barrido luminoso.
El uso de variables permite modificar fácilmente la velocidad o cantidad de LEDs sin reescribir todo el código.
