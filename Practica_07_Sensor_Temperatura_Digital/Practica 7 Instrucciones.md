# 🔬 PRACTICA #7 – Sensor de Temperatura Digital (DS18B20)

---

## 🎯 Objetivo  
Aprender a utilizar **sensores digitales** en Arduino mediante el uso de **librerías externas**, comprendiendo la comunicación **1-Wire** y la lectura de temperatura a través del sensor **DS18B20**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 sensor **DS18B20**  
- 1 resistencia de **4.7 kΩ**  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica consiste en conectar el **sensor de temperatura DS18B20** al Arduino UNO para leer y mostrar la temperatura ambiente en el **Monitor Serial**.  
Se emplean las librerías **OneWire.h** y **DallasTemperature.h**, que facilitan la comunicación con el sensor y el procesamiento de los datos.

---

## 🧩 Instrucciones  
- **#include \<OneWire.h\>** → Permite la comunicación 1-Wire con el sensor.  
- **#include \<DallasTemperature.h\>** → Librería que interpreta los datos del DS18B20.  
- **Serial.begin()** → Inicia la comunicación serial con el monitor (9600 baudios).  
- **sensors.begin()** → Inicializa el sensor DS18B20.  
- **requestTemperatures()** → Solicita la lectura de temperatura.  
- **getTempCByIndex(0)** → Obtiene el valor de temperatura del primer sensor conectado.  

---

## 💻 Código Original  

```cpp
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ourWire(2);
DallasTemperature sensors(&ourWire);

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.println(" °C");
  delay(1000);
}
💡 Explicación del código
Se incluyen las librerías necesarias para usar el sensor.

Se define el pin 2 como bus 1-Wire para comunicación con el DS18B20.

Se inicia la comunicación serial para mostrar los datos.

Cada segundo, el programa solicita la temperatura al sensor y la muestra en °C en el Monitor Serial.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #7 – Sensor de Temperatura Digital (DS18B20)
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: OneWire.h, DallasTemperature.h
   Descripción:
   Este programa mide la temperatura ambiente utilizando
   el sensor digital DS18B20 y muestra el resultado en la
   pantalla serial en grados Celsius.
----------------------------------------------------------- */

#include <OneWire.h>             // Librería para comunicación 1-Wire
#include <DallasTemperature.h>   // Librería para manejo del sensor DS18B20

// ------------------------------
// 🔧 Configuración del sensor
// ------------------------------
#define SENSOR_PIN 2             // Pin digital donde se conecta el pin DATA del sensor
OneWire oneWire(SENSOR_PIN);     // Inicializa la comunicación OneWire
DallasTemperature sensors(&oneWire);  // Asocia el bus 1-Wire con la librería Dallas

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  Serial.begin(9600);            // Inicia la comunicación serial
  sensors.begin();               // Inicializa el sensor de temperatura
  delay(1000);                   // Espera breve para estabilización
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  sensors.requestTemperatures(); // Solicita lectura de temperatura
  float temp = sensors.getTempCByIndex(0);  // Obtiene el valor en °C

  Serial.print("Temperatura actual: ");
  Serial.print(temp);
  Serial.println(" °C");         // Muestra en el monitor serial
  delay(1000);                   // Espera 1 segundo antes de repetir
}
🔎 Resultado Esperado
El Monitor Serial mostrará la temperatura ambiente medida por el sensor DS18B20, actualizándose cada segundo.
Por ejemplo:

kotlin
Copy code
Temperatura actual: 27.50 °C  
Temperatura actual: 27.56 °C  
Temperatura actual: 27.62 °C  
⚙️ Nota adicional
Asegúrate de haber instalado correctamente las librerías:

OneWire de Paul Stoffregen

DallasTemperature de Miles Burton
Puedes hacerlo desde el Administrador de Librerías de Arduino IDE (Ctrl + Shift + I → buscar por nombre).
