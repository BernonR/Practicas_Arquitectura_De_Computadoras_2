# 🔬 PRACTICA #10 – Sensor de Temperatura y Humedad DHT11

---

## 🎯 Objetivo  
Aprender a utilizar el **sensor DHT11** para obtener lecturas reales de **temperatura** y **humedad relativa**, mostrando los resultados en el **Monitor Serial**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- Sensor DHT11  
- Resistencia de **10 kΩ**  
- Cables de conexión  

---

## 🧠 Descripción  
El sensor **DHT11** combina un termistor y un sensor capacitivo de humedad en un solo módulo.  
Se comunica digitalmente con Arduino, permitiendo leer los valores de **temperatura en °C/°F** y **humedad relativa (%)**, así como calcular el **índice de calor**.  
Para esta práctica se requiere la instalación de la librería **DHT.h**.

---

## 📦 Librerías necesarias  
- **DHT sensor library** de Adafruit  
- **Adafruit Unified Sensor**  

Instálalas desde el **Administrador de Librerías** del Arduino IDE:
Herramientas → Administrar bibliotecas → Buscar: "DHT sensor library"

pgsql
Copy code

---

## 🧩 Instrucciones  
- **dht.readTemperature()** → Lee la temperatura en grados centígrados o Fahrenheit.  
- **dht.readHumidity()** → Obtiene el porcentaje de humedad relativa.  
- **Serial.begin()** → Inicializa la comunicación serial a 9600 baudios.  
- **Serial.println()** → Muestra los valores en el monitor serial.  
- **delay()** → Establece el intervalo de actualización (5 segundos).

---

## 💻 Código Original  

```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C ");
  Serial.print(f);
  Serial.print(" °F\t");

  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.println(" °C");
}
💡 Explicación del código
Se inicializa el sensor DHT11 en el pin 2.

Se leen los valores de humedad y temperatura cada 5 segundos.

Se valida si hay errores en la lectura con isnan().

Se calcula el índice de calor (sensación térmica).

Se imprimen los valores en el Monitor Serial.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #10 – Sensor de Temperatura y Humedad DHT11
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: DHT.h
   Descripción:
   Este programa obtiene valores de temperatura y humedad
   del ambiente utilizando el sensor DHT11, y los muestra en
   el Monitor Serial junto al índice de calor.
----------------------------------------------------------- */

#include <DHT.h>            // Librería del sensor DHT

#define DHTPIN 2            // Pin de conexión del sensor
#define DHTTYPE DHT11       // Tipo de sensor utilizado
DHT dht(DHTPIN, DHTTYPE);   // Creación del objeto sensor

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  Serial.begin(9600);       // Comunicación serial
  dht.begin();              // Inicializa el sensor DHT
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  delay(5000);              // Espera 5 segundos entre lecturas

  // Lectura de datos
  float humedad = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  // Validación de lecturas
  if (isnan(humedad) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Error obteniendo los datos del sensor");
    return;
  }

  // Cálculo del índice de calor
  float indiceCalor = dht.computeHeatIndex(tempC, humedad, false);

  // Impresión de resultados
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\t");

  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.print(" °C ");
  Serial.print(tempF);
  Serial.print(" °F\t");

  Serial.print("Índice de calor: ");
  Serial.print(indiceCalor);
  Serial.println(" °C");
}
🔎 Resultado Esperado
El Monitor Serial mostrará algo similar a:

yaml
Copy code
Humedad: 55.00 %   Temperatura: 27.00 °C  80.60 °F   Índice de calor: 28.30 °C
Humedad: 56.00 %   Temperatura: 27.10 °C  80.78 °F   Índice de calor: 28.45 °C
⚙️ Nota adicional
El sensor DHT11 tiene una precisión de ±5% para humedad y ±2°C para temperatura.

Evita colocarlo cerca de fuentes de calor o humedad directa para obtener lecturas estables.
