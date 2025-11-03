# 🔬 PRACTICA #9 – Medidor de Luz con LDR

---

## 🎯 Objetivo  
Aprender a utilizar una **LDR (resistencia dependiente de la luz)** para medir la intensidad lumínica del ambiente y visualizarla mediante una **barra de 10 LEDs** que actúa como medidor de nivel de luz.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 LDR  
- 1 resistencia de **10 kΩ**  
- 10 resistencias de **330 Ω**  
- 10 LEDs  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica convierte las lecturas analógicas del sensor **LDR** en una representación visual usando **10 LEDs**.  
A mayor iluminación, más LEDs se encienden; a menor luz, menos LEDs se iluminan.  
El valor leído por la LDR (de 0 a 1023) se compara con varios umbrales para determinar cuántos LEDs se deben encender.

---

## 🧩 Instrucciones  
- **pinMode()** → Configura los pines como `INPUT` o `OUTPUT`.  
- **analogRead()** → Lee la intensidad de luz desde el pin analógico.  
- **digitalWrite()** → Controla el encendido y apagado de los LEDs.  
- **Serial.begin()** → Inicializa la comunicación serial.  
- **Serial.println()** → Muestra el valor de luz en el monitor serial.

---

## 💻 Código Original  

```cpp
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;
const int ledPin6 = 7;
const int ledPin7 = 8;
const int ledPin8 = 9;
const int ledPin9 = 10;
const int ledPin10 = 11;
const int LDRPin = A0;

int val = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LDRPin);
  Serial.println(val);
  medidor();
}

void medidor() {
  if (val > 100) digitalWrite(ledPin1, HIGH); else digitalWrite(ledPin1, LOW);
  if (val > 200) digitalWrite(ledPin2, HIGH); else digitalWrite(ledPin2, LOW);
  if (val > 300) digitalWrite(ledPin3, HIGH); else digitalWrite(ledPin3, LOW);
  if (val > 400) digitalWrite(ledPin4, HIGH); else digitalWrite(ledPin4, LOW);
  if (val > 500) digitalWrite(ledPin5, HIGH); else digitalWrite(ledPin5, LOW);
  if (val > 600) digitalWrite(ledPin6, HIGH); else digitalWrite(ledPin6, LOW);
  if (val > 700) digitalWrite(ledPin7, HIGH); else digitalWrite(ledPin7, LOW);
  if (val > 800) digitalWrite(ledPin8, HIGH); else digitalWrite(ledPin8, LOW);
  if (val > 900) digitalWrite(ledPin9, HIGH); else digitalWrite(ledPin9, LOW);
  if (val > 950) digitalWrite(ledPin10, HIGH); else digitalWrite(ledPin10, LOW);
}
💡 Explicación del código
Se configuran 10 pines digitales como salidas para controlar los LEDs.

Se define el pin A0 para leer la LDR.

Cada lectura analógica se evalúa con umbrales de 100 en 100 unidades.

Cuanta más luz incide en la LDR, mayor será el valor leído y más LEDs se encenderán.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #9 – Medidor de Luz con LDR
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa mide la cantidad de luz ambiental mediante
   una LDR y muestra el resultado en un vúmetro de 10 LEDs.
----------------------------------------------------------- */

const int ledPins[10] = {2,3,4,5,6,7,8,9,10,11}; // LEDs del 1 al 10
const int LDRPin = A0;  // Entrada analógica para la LDR
int val = 0;            // Variable para guardar el valor de luz

void setup() {
  // Configuración de pines de salida para LEDs
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(LDRPin, INPUT); // Entrada analógica
  Serial.begin(9600);     // Comunicación serial a 9600 bps
}

void loop() {
  val = analogRead(LDRPin);   // Lee la intensidad de luz (0–1023)
  Serial.print("Nivel de luz: ");
  Serial.println(val);        // Muestra el valor leído en el monitor serial
  mostrarLuz(val);
  delay(100);
}

// ------------------------------
// 💡 Función: mostrarLuz()
// Enciende los LEDs según el nivel de luz detectado.
// ------------------------------
void mostrarLuz(int valor) {
  for (int i = 0; i < 10; i++) {
    if (valor > (i + 1) * 100) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
🔎 Resultado Esperado
El sistema mostrará en tiempo real la cantidad de luz ambiental:

En lugares oscuros → pocos LEDs encendidos.

En lugares iluminados → casi todos los LEDs encendidos.
Además, el Monitor Serial mostrará el valor numérico leído por el sensor.

⚙️ Nota adicional
Usa una resistencia de 10 kΩ en paralelo con la LDR para mejorar la sensibilidad.

Evita la luz directa del sol sobre la LDR para lecturas más estables.
