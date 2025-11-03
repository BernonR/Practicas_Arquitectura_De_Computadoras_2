# 🌡️ PRACTICA #17 – Comunicación 1-Wire con el sensor DS18B20

---

## 🎯 Objetivo  
Aprender a usar el **protocolo 1-Wire** para comunicarse con el sensor de temperatura **DS18B20**, mediante las librerías **OneWire** y **DallasTemperature**, realizando mediciones precisas y conectando múltiples sensores en un mismo bus.

---

## 🧰 Materiales
- Arduino UNO  
- Sensor de temperatura **DS18B20** (impermeable o TO-92)  
- 1 Resistencia **4.7 kΩ** (pull-up)  
- Protoboard  
- Cables de conexión  

---

## 🧠 Descripción  
El **DS18B20** es un sensor digital de temperatura que usa el protocolo **1-Wire**, el cual permite comunicación bidireccional con un solo pin de datos (DQ).  
Cada sensor tiene una **dirección única de 64 bits**, lo que permite conectar múltiples sensores en un mismo bus.  

Puede medir temperaturas entre **-55 °C y +125 °C**, con una resolución de **9 a 12 bits**, y una precisión de **±0.5 °C** entre -10 °C y 85 °C.

---

## ⚙️ Características Técnicas

| Propiedad | Valor |
|------------|--------|
| Voltaje de operación | 3 V a 5.5 V |
| Rango de temperatura | -55 °C a +125 °C |
| Error típico | ±0.5 °C |
| Resolución | 9, 10, 11 o 12 bits |
| Comunicación | 1-Wire |
| Dirección única | 64 bits |

---

## 📡 Modos de Alimentación

### 🔸 1. Alimentación normal (3 cables)
- Se conecta **VDD (5 V)**, **GND**, y **DQ** (datos).
- Requiere una **resistencia pull-up de 4.7 kΩ** entre DQ y 5V.

### 🔸 2. Alimentación parásita (2 cables)
- Solo se usan **DQ y GND**.
- El sensor toma la energía del pin de datos cuando está en estado alto.

---

## 🧩 Librerías Necesarias
Instalar desde el **Administrador de Librerías** de Arduino IDE:

- **OneWire**  
  👉 [http://www.pjrc.com/teensy/td_libs_OneWire.html](http://www.pjrc.com/teensy/td_libs_OneWire.html)

- **DallasTemperature**  
  👉 [http://www.milesburton.com/Dallas_Temperature_Control_Library](http://www.milesburton.com/Dallas_Temperature_Control_Library)

---

## 💻 Ejemplo 1 – Lectura de un solo sensor

```cpp
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire(2); // Pin 2 como bus OneWire
DallasTemperature sensors(&ourWire); // Objeto del sensor

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors.begin(); // Inicializa el sensor
}

void loop() {
  sensors.requestTemperatures(); // Solicita lectura
  float temp = sensors.getTempCByIndex(0); // Lee la temperatura en °C
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.println(" °C");
  delay(500);
}
💻 Ejemplo 2 – Dos sensores en pines distintos
cpp
Copy code
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire1(2);
OneWire ourWire2(3);
DallasTemperature sensors1(&ourWire1);
DallasTemperature sensors2(&ourWire2);

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors1.begin();
  sensors2.begin();
}

void loop() {
  sensors1.requestTemperatures();
  float t1 = sensors1.getTempCByIndex(0);
  sensors2.requestTemperatures();
  float t2 = sensors2.getTempCByIndex(0);

  Serial.print("Temp 1 = ");
  Serial.print(t1);
  Serial.print(" °C | ");
  Serial.print("Temp 2 = ");
  Serial.print(t2);
  Serial.println(" °C");
  delay(500);
}
💻 Ejemplo 3 – Varios sensores en un solo bus (1-Wire)
cpp
Copy code
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire(2);
DallasTemperature sensors(&ourWire);

// Direcciones únicas de cada sensor (obtenidas previamente)
DeviceAddress sensor1 = {0x28, 0xFF, 0xCA, 0x4A, 0x05, 0x16, 0x03, 0xBD};
DeviceAddress sensor2 = {0x28, 0xFF, 0x89, 0x3A, 0x01, 0x16, 0x04, 0xAF};
DeviceAddress sensor3 = {0x28, 0xFF, 0x23, 0x19, 0x01, 0x16, 0x04, 0xD9};

void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(sensor1, 12);
  sensors.setResolution(sensor2, 12);
  sensors.setResolution(sensor3, 12);
}

void loop() {
  sensors.requestTemperatures();

  Serial.print("T1: ");
  Serial.print(sensors.getTempC(sensor1));
  Serial.print(" °C | T2: ");
  Serial.print(sensors.getTempC(sensor2));
  Serial.print(" °C | T3: ");
  Serial.print(sensors.getTempC(sensor3));
  Serial.println(" °C");

  delay(1000);
}
💡 Explicación del Código
OneWire: Gestiona el bus de comunicación de un solo hilo.

DallasTemperature: Facilita la lectura de temperatura del DS18B20.

getTempCByIndex(0): Lee el primer sensor conectado al bus.

DeviceAddress: Almacena la dirección única de cada sensor.

setResolution(): Configura la resolución (9 a 12 bits).

🔎 Resultado Esperado
En el Monitor Serial se mostrará la temperatura actual de cada sensor en grados Celsius.

Si hay varios sensores, todos se leen desde el mismo pin de datos (protocolo 1-Wire).

⚙️ Nota adicional
A mayor resolución (12 bits), más lento será el muestreo.

En conexiones largas, usa cables trenzados y evita interferencias.

La resistencia pull-up de 4.7 kΩ es obligatoria para una comunicación estable.

arduino
Copy code

---

### 💻 Archivo final: `Practica_17.ino`

```cpp
/* -----------------------------------------------------------
   PRACTICA #17 – Comunicación 1-Wire con sensor DS18B20
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: OneWire.h, DallasTemperature.h
   Descripción:
   Este programa permite medir la temperatura utilizando uno
   o varios sensores DS18B20 mediante el protocolo 1-Wire.
   Se muestra la temperatura en grados Celsius por el monitor serial.
----------------------------------------------------------- */

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin de datos del bus One-Wire
#define ONE_WIRE_BUS 2

// Inicialización de las librerías
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin(); // Inicializa la comunicación con el sensor
  Serial.println("Sensor DS18B20 listo...");
}

void loop() {
  sensors.requestTemperatures();             // Solicita lectura
  float temperatura = sensors.getTempCByIndex(0); // Lee temperatura (primer sensor)
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  delay(1000);
}
