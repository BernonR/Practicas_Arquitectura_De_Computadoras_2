# 🔬 PRACTICA #4 – Control de Brillo de LED con Potenciómetro  

---

## 🎯 Objetivo  
Aprender el uso de **entradas analógicas** en Arduino y cómo estas pueden modificar el comportamiento de una salida digital, ajustando el brillo de un LED mediante un **potenciómetro**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 LED  
- 1 resistencia de **330 Ω**  
- 1 potenciómetro de **10 kΩ**  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica consiste en ajustar el **brillo de un LED** utilizando un **potenciómetro**, que actúa como un divisor de voltaje.  
El valor leído del potenciómetro se almacena en una variable y se usa para controlar el **tiempo (delay)** de encendido y apagado del LED, provocando una variación perceptible en su intensidad luminosa.

---

## 🧩 Instrucciones  
- **pinMode()** → Configura los pines como `INPUT` o `OUTPUT`.  
- **digitalWrite()** → Cambia el estado de un pin digital entre `HIGH` (encendido) y `LOW` (apagado).  
- **delay()** → Detiene temporalmente el programa según el tiempo en milisegundos.  
- **analogRead()** → Lee valores analógicos de los pines A0–A5 (de 0 a 1023).

---

## 💻 Código Original  

```cpp
int potPin = 0;  // Pin del potenciómetro
int ledPin = 1;  // Pin del LED
int value = 0;   // Variable para almacenar el valor leído

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura el pin del LED como salida
}

void loop() {
  value = analogRead(potPin); // Lee el valor del potenciómetro (0 a 1023)
  digitalWrite(ledPin, HIGH); // Enciende el LED
  delay(value);               // Espera un tiempo proporcional al valor leído
  digitalWrite(ledPin, LOW);  // Apaga el LED
  delay(value);               // Espera el mismo tiempo antes de repetir
}
💡 Explicación del código
analogRead(potPin) lee un valor entre 0 y 1023, dependiendo de la posición del potenciómetro.

El valor leído modifica el tiempo del delay(), controlando la velocidad de parpadeo del LED.

Cuanto mayor sea el valor del potenciómetro, más lento parpadea el LED, simulando un cambio de brillo.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #4 – Control de Brillo de LED con Potenciómetro
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa varía el brillo de un LED en función del valor
   leído en un potenciómetro de 10 kΩ conectado al pin A0.
----------------------------------------------------------- */

// ------------------------------
// 🔧 Declaración de variables
// ------------------------------
int potPin = A0;   // Pin analógico donde se conecta el potenciómetro
int ledPin = 1;    // Pin digital del LED
int value = 0;     // Variable para almacenar la lectura analógica

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  pinMode(ledPin, OUTPUT);  // Configura el pin del LED como salida
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  value = analogRead(potPin); // Lee el valor del potenciómetro (0–1023)

  // Enciende el LED
  digitalWrite(ledPin, HIGH);
  delay(value);               // Espera según el valor leído

  // Apaga el LED
  digitalWrite(ledPin, LOW);
  delay(value);               // Espera el mismo tiempo antes de repetir
}
🔎 Resultado Esperado
El LED parpadea a diferentes velocidades dependiendo de la posición del potenciómetro.
Cuando el potenciómetro está al mínimo, el LED parpadea rápidamente; cuando está al máximo, lo hace lentamente, simulando un control de brillo gradual.
