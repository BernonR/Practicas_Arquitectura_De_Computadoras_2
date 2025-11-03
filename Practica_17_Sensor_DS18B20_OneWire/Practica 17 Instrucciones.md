# 🌡️ PRACTICA #17 – Comunicación 1-Wire con el sensor DS18B20

---

## 🎯 **Objetivo**
Implementar la comunicación digital **1-Wire** para la lectura de temperatura utilizando el sensor **DS18B20**, conociendo sus modos de conexión, librerías necesarias y comportamiento en modo **alimentación normal** y **modo parásito**.

---

## 🧰 **Materiales**
| Cantidad | Componente                      | Descripción |
|-----------|----------------------------------|--------------|
| 1 | Arduino UNO | Placa microcontroladora principal |
| 1 | Sensor DS18B20 (impermeable o TO-92) | Sensor digital de temperatura |
| 1 | Resistencia de 4.7 kΩ | Resistencia **pull-up** para el bus de datos |
| 1 | Protoboard | Base de conexiones |
| 3 | Cables Dupont | Conexiones de señal, alimentación y tierra |

---

## 🧠 **Fundamento Teórico**

El **DS18B20** es un sensor digital que mide la temperatura en el rango de **-55 °C a 125 °C**, con una resolución ajustable entre **9 y 12 bits**.  
Su precisión típica es de **±0.5 °C** entre -10 °C y 85 °C.

El sensor utiliza el protocolo **1-Wire**, lo cual significa que:
- Todos los dispositivos (sensores) se comunican por **una sola línea de datos (DQ)**.  
- Cada sensor tiene una **dirección única de 64 bits (8 bytes)**.  
- Permite conectar **múltiples sensores** al mismo pin de Arduino.  

---

## ⚙️ **Características Técnicas del DS18B20**

| Propiedad | Valor |
|------------|--------|
| Voltaje de operación | 3.0 V – 5.5 V |
| Rango de temperatura | -55 °C a +125 °C |
| Error típico | ±0.5 °C |
| Resolución | 9 a 12 bits (por defecto: 12) |
| Comunicación | 1-Wire digital |
| Identificación | Dirección única de 64 bits |
| Librerías necesarias | OneWire.h y DallasTemperature.h |

---

## 🧩 **Modos de Alimentación**

### 🔸 **1. Alimentación Normal (3 cables)**
El sensor usa sus tres pines:
- **VDD (rojo):** 5 V  
- **DQ (amarillo):** Datos conectados al pin digital **2**  
- **GND (negro):** Tierra común  

> Entre el pin **DQ y 5 V** debe colocarse una resistencia **pull-up de 4.7 kΩ** para mantener la línea en estado alto.

### 🔸 **2. Alimentación Parásita (2 cables)**
Solo se conectan los pines **DQ y GND**.  
El sensor obtiene energía del pin de datos cuando está en estado alto.  
Es útil cuando se requiere reducir cables o trabajar en zonas selladas.

> En este modo también se utiliza una resistencia **pull-up de 4.7 kΩ** entre **DQ y 5 V**.

---

## 🔌 **Conexiones Arduino – DS18B20**

| Pin DS18B20 | Conexión Arduino | Descripción |
|--------------|------------------|--------------|
| VDD | 5 V | Alimentación (solo en modo normal) |
| DQ | Pin digital 2 | Línea de datos 1-Wire |
| GND | GND | Tierra común |
| Resistencia | Entre DQ y 5 V | Pull-up de 4.7 kΩ |

---

## 🧠 **Librerías Necesarias**

Instalar desde el **Administrador de Librerías** del IDE de Arduino:

1. **OneWire**  
   - Implementa el protocolo 1-Wire.  
   - Más información: [http://www.pjrc.com/teensy/td_libs_OneWire.html](http://www.pjrc.com/teensy/td_libs_OneWire.html)

2. **DallasTemperature**  
   - Simplifica la lectura del DS18B20.  
   - Más información: [http://www.milesburton.com/Dallas_Temperature_Control_Library](http://www.milesburton.com/Dallas_Temperature_Control_Library)

---

## 💻 **Ejemplo 1 – Lectura de un solo sensor (alimentación normal)**

```cpp
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire(2); // Pin 2 como bus 1-Wire
DallasTemperature sensors(&ourWire);

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors.begin(); // Inicializa el sensor
}

void loop() {
  sensors.requestTemperatures(); // Envía comando de lectura
  float temp = sensors.getTempCByIndex(0); // Obtiene temperatura
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.println(" °C");
  delay(1000);
}
🔹 Salida esperada en el Monitor Serial:

ini
Copy code
Temperatura = 26.50 °C
Temperatura = 26.56 °C
Temperatura = 26.62 °C
💻 Ejemplo 2 – Dos sensores conectados a pines diferentes
cpp
Copy code
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire wire1(2);
OneWire wire2(3);
DallasTemperature sensor1(&wire1);
DallasTemperature sensor2(&wire2);

void setup() {
  Serial.begin(9600);
  sensor1.begin();
  sensor2.begin();
}

void loop() {
  sensor1.requestTemperatures();
  sensor2.requestTemperatures();

  float t1 = sensor1.getTempCByIndex(0);
  float t2 = sensor2.getTempCByIndex(0);

  Serial.print("Temp 1: ");
  Serial.print(t1);
  Serial.print(" °C | Temp 2: ");
  Serial.print(t2);
  Serial.println(" °C");
  delay(1000);
}
💻 Ejemplo 3 – Varios sensores en un mismo bus (1-Wire compartido)
Antes de usar varios sensores en la misma línea, obtén la dirección única de cada uno con este código:

cpp
Copy code
#include <DallasTemperature.h>

const int pinDQ = 9;
OneWire oneWire(pinDQ);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();

  Serial.println("Buscando sensores DS18B20...");
  int total = sensors.getDeviceCount();
  Serial.print("Sensores encontrados: ");
  Serial.println(total);

  if (total == 1) {
    DeviceAddress address;
    sensors.getAddress(address, 0);
    Serial.print("Direccion del sensor: ");
    for (uint8_t i = 0; i < 8; i++) {
      if (address[i] < 16) Serial.print("0");
      Serial.print(address[i], HEX);
    }
  }
}

void loop() {}
💻 Programa Final (Modo Normal + Parásito)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #17 – Comunicación 1-Wire con sensor DS18B20
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: OneWire.h, DallasTemperature.h
   Descripción:
   Este programa permite medir la temperatura con uno o varios
   sensores DS18B20 mediante el protocolo 1-Wire, usando tanto
   el modo normal (3 cables) como el modo parásito (2 cables).
----------------------------------------------------------- */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  Serial.println("=== SENSOR DS18B20 LISTO ===");
  Serial.println("Modo: Alimentacion Normal o Parásito");
  Serial.println("------------------------------------");
}

void loop() {
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);
  Serial.print("Temperatura actual: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  delay(1000);
}

/* -----------------------------------------------------------
   MODO PARÁSITO (Referencia)
   En este modo no se conecta el pin VDD del sensor.
   Solo se usa DQ (pin 2) y GND, con una resistencia
   de 4.7 kΩ entre DQ y 5V.
   El mismo código funciona sin modificaciones,
   ya que la librería DallasTemperature gestiona
   el protocolo 1-Wire automáticamente.
----------------------------------------------------------- */
🔎 Resultado Esperado
El monitor serial mostrará la temperatura actual cada segundo.

En caso de múltiples sensores, se podrán leer en la misma línea del bus One-Wire.

Se puede alternar entre modo normal o modo parásito sin cambiar el código.

⚙️ Notas Finales
Cada sensor tiene una dirección única (ID de 64 bits).

La resistencia pull-up de 4.7 kΩ es obligatoria.

La resolución puede configurarse con:

cpp
Copy code
sensors.setResolution(sensorAddress, 9);  // o 10, 11, 12 bits
A menor resolución, la lectura será más rápida.

El protocolo 1-Wire permite hasta 100 sensores en una sola línea si se usan cables adecuados.

📊 Conclusión
El DS18B20 es un sensor digital versátil que utiliza el protocolo 1-Wire para transmitir datos con gran precisión y estabilidad.
El uso combinado de las librerías OneWire y DallasTemperature simplifica su implementación, permitiendo monitorear una o varias temperaturas con facilidad en proyectos de monitoreo ambiental, domótica o automatización industrial.
