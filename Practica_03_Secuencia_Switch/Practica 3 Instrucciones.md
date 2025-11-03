# 🔬 PRACTICA #3 – Secuencias de LEDs con Switch  

---

## 🎯 Objetivo  
Aprender el uso combinado de **entradas y salidas digitales** en Arduino mediante una secuencia de LEDs controlada por un **switch**, utilizando estructuras **if** y **for**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 10 LEDs  
- 10 resistencias de **330 Ω**  
- 1 resistencia de **5 kΩ** (pull-down)  
- 1 **switch o pulsador**  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica consiste en controlar el encendido de una **secuencia de 10 LEDs** mediante un **interruptor (switch)**.  
El circuito usa un **pin digital configurado como entrada** para leer el estado del switch, y cuando se presiona, activa una secuencia de luces hacia adelante y hacia atrás.

---

## 🧩 Instrucciones  
- **pinMode()** → Define el modo de trabajo de un pin: `INPUT` o `OUTPUT`.  
- **digitalWrite()** → Envía valores lógicos `HIGH` o `LOW` a un pin configurado como salida.  
- **delay()** → Pausa la ejecución del programa por un tiempo en milisegundos.  
- **digitalRead()** → Lee el valor de un pin digital, devolviendo `HIGH` o `LOW`.

---

## 💻 Código Original  

```cpp
int tiempo = 100;
int n;
const int pulsador = 12;
int estado = 0;

void setup() {
  pinMode(12, INPUT);
  for (n = 1; n <= 10; n++) {
    pinMode(n, OUTPUT);
  }
}

void secuencia() {
  for (n = 1; n <= 10; n++) {
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }

  for (n = 10; n >= 1; n--) {
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }
}

void loop() {
  estado = digitalRead(pulsador);
  if (digitalRead(estado == HIGH)) {
    secuencia();
  }
}

💡 Explicación del código

Se define una variable pulsador en el pin 12.

Cuando el switch se presiona (estado == HIGH), se ejecuta la función secuencia().

Los LEDs se encienden uno por uno hacia adelante y luego hacia atrás.

El delay de 100 ms controla la velocidad de la animación.

🧮 Código Mejorado (opcional)

Versión con mejor organización y comentarios:

🧮 Código Mejorado (opcional)

Versión con mejor organización y comentarios:

/* -----------------------------------------------------------
   PRACTICA #3 – Secuencia de LEDs con Switch
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
----------------------------------------------------------- */

int tiempo = 100;
const int pulsador = 12;
int estado = 0;

void setup() {
  pinMode(pulsador, INPUT);
  for (int n = 1; n <= 10; n++) {
    pinMode(n, OUTPUT);
  }
}

void secuencia() {
  for (int n = 1; n <= 10; n++) {
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }
  for (int n = 10; n >= 1; n--) {
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }
}

void loop() {
  estado = digitalRead(pulsador);
  if (estado == HIGH) {
    secuencia();
  }
}

🔎 Resultado Esperado

Al presionar el switch, los LEDs realizarán una animación de encendido secuencial hacia adelante y luego hacia atrás.
Cuando el switch no está presionado, todos los LEDs permanecerán apagados.
