# 🔹 Práctica #1 – Secuencia de LEDs

## 🎯 Objetivo
Aprender el uso de las **salidas digitales en Arduino**, mediante el **encendido y apagado secuencial de LEDs**, controlando el tiempo de activación mediante la función `delay()`.

---

## 🧰 Listado de componentes
- 🔌 Cables de conexión  
- 🧠 Arduino UNO  
- 💡 10 LEDs  
- ⚙️ 1 resistencia de **330 Ω**

---

## 📝 Descripción
Esta práctica consiste en programar una **secuencia de encendido y apagado de LEDs** conectados a una placa Arduino UNO.  
El tiempo de encendido puede variar utilizando la función `delay()`, generando un patrón de iluminación repetitivo y controlado.

---

## ⚙️ Instrucciones principales

### 🔸 `pinMode()`
Se utiliza en la sección `setup()` para configurar el modo de trabajo de un pin, que puede ser:
- `INPUT` → Entrada de señal.  
- `OUTPUT` → Salida de señal.  

Los pines configurados como entrada se comportan eléctricamente como **alta impedancia**, mientras que los pines de salida permiten **enviar voltaje** a los componentes conectados (por ejemplo, LEDs).

---

### 🔸 `digitalWrite()`
Permite **escribir un valor lógico digital** en un pin configurado como salida:
- `digitalWrite(pin, HIGH)` → Envía 5V al pin (enciende LED).  
- `digitalWrite(pin, LOW)` → Envía 0V al pin (apaga LED).

---

### 🔸 `delay()`
Detiene temporalmente la ejecución del programa por el número de **milisegundos** especificado:
- `delay(200)` → Pausa de 200 ms antes de continuar con la siguiente instrucción.

---

## 💻 Código original (comentado)

```cpp
/* -----------------------------------------------------------
   PRACTICA #1 – Secuencia de LEDs
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Pines utilizados: 5, 6, 7, 8
   Librerías necesarias: (Ninguna)
----------------------------------------------------------- */

void setup() {
  // Configuración de los pines como salidas digitales
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // LED en pin 5
  digitalWrite(5, HIGH);   // Enciende LED 1
  delay(200);              // Espera 200 ms
  digitalWrite(5, LOW);    // Apaga LED 1
  delay(200);              // Pausa antes del siguiente LED

  // LED en pin 6
  digitalWrite(6, HIGH);
  delay(200);
  digitalWrite(6, LOW);
  delay(200);

  // LED en pin 7
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(7, LOW);
  delay(200);

  // LED en pin 8
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(8, LOW);
  delay(200);
}
⚡ Código versión mejorada (efecto ida y vuelta)
/* -----------------------------------------------------------
   PRACTICA #1 – Secuencia de LEDs (Versión mejorada)
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Pines utilizados: 5, 6, 7, 8
   Librerías necesarias: (Ninguna)
----------------------------------------------------------- */

int leds[] = {5, 6, 7, 8};  // Arreglo de pines conectados a LEDs
int total = 4;              // Número de LEDs
int tiempo = 200;           // Tiempo entre cada cambio (ms)

void setup() {
  // Configura todos los pines como salida
  for (int i = 0; i < total; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Secuencia izquierda → derecha
  for (int i = 0; i < total; i++) {
    digitalWrite(leds[i], HIGH);
    delay(tiempo);
    digitalWrite(leds[i], LOW);
  }

  // Secuencia derecha → izquierda
  for (int i = total - 2; i > 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(tiempo);
    digitalWrite(leds[i], LOW);
  }
}
