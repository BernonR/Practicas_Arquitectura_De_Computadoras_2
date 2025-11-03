# 🔬 PRACTICA #8 – Sensor de Temperatura Analógico (LM35)

---

## 🎯 Objetivo  
Interpretar la señal **analógica** proveniente del sensor **LM35** para convertirla en valores de temperatura expresados en **grados centígrados**, utilizando cálculos matemáticos en Arduino.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- Sensor de temperatura **LM35**  
- Cables de conexión  

---

## 🧠 Descripción  
El **LM35** es un sensor analógico que entrega una señal de salida proporcional a la temperatura (10 mV/°C).  
Arduino interpreta esta señal mediante su **convertidor analógico-digital (ADC)** de 10 bits, obteniendo valores entre **0 y 1023**.  
La fórmula matemática convierte ese valor en grados Celsius, basándose en una referencia de 5V.

---

## 📐 Fórmula de conversión  
\[
\text{TEMPERATURA} = \left( \frac{5.0 \times \text{LECTURA} \times 100.0}{1024.0} \right)
\]

---

## 🧩 Instrucciones  
- **analogRead()** → Lee un valor analógico (0–1023) desde el pin A0.  
- **Serial.begin()** → Inicia la comunicación serial a 9600 baudios.  
- **Serial.println()** → Muestra la temperatura en el monitor serial.  
- **delay()** → Pausa el programa durante 1 segundo entre lecturas.  

---

## 💻 Código Original  

```cpp
int SENSOR;
float TEMPERATURA;

void setup() {
  Serial.begin(9600);
}

void loop() {
  SENSOR = analogRead(A0);
  TEMPERATURA = ((5.0 * SENSOR * 100.0) / 1024.0);

  Serial.println(TEMPERATURA, 1);
  delay(1000);
}
💡 Explicación del código
SENSOR almacena el valor leído del pin analógico A0.

TEMPERATURA almacena el valor calculado en °C.

Se usa la fórmula de conversión para transformar la lectura ADC (0–1023) en temperatura.

El resultado se muestra cada segundo en el Monitor Serial.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #8 – Sensor de Temperatura Analógico (LM35)
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa mide la temperatura ambiente usando el sensor
   analógico LM35 y muestra el valor en °C en el Monitor Serial.
----------------------------------------------------------- */

// ------------------------------
// 🔧 Declaración de variables
// ------------------------------
int SENSOR;            // Valor leído del pin analógico A0
float TEMPERATURA;     // Valor convertido en grados centígrados

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  // No se requiere pinMode para entradas analógicas
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  SENSOR = analogRead(A0);  // Lee el valor analógico del sensor
  TEMPERATURA = (5.0 * SENSOR * 100.0) / 1024.0;  // Convierte a °C

  // Muestra el valor en el monitor serial con un decimal
  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA, 1);
  Serial.println(" °C");

  delay(1000);  // Espera 1 segundo antes de la siguiente lectura
}
🔎 Resultado Esperado
El Monitor Serial mostrará la temperatura ambiente cada segundo, por ejemplo:

makefile
Copy code
Temperatura: 26.7 °C
Temperatura: 27.0 °C
Temperatura: 27.3 °C
⚙️ Nota adicional
No requiere librerías adicionales.

Si las lecturas son inestables, revisa las conexiones y el contacto del pin central (A0).
