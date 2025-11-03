# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #5 – PWM: Control de brillo de LED con potenciómetro**.

---

## 💡 Diagrama Físico  
![Diagrama físico del circuito](https://github.com/BernonR/Practicas_Arquitectura_De_Computadoras_2/blob/main/Practica_05_PWM_Control_Brillo/diagrama.png)

> 💬 Asegúrate de subir la imagen del diagrama con el nombre **diagrama.png** en la misma carpeta para que se muestre correctamente.

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 💡 Conexión del LED y potenciómetro  
1. Coloca el **LED** en el protoboard.  
2. Conecta la **pata larga (ánodo)** del LED al **pin digital 9 (PWM)** del Arduino.  
3. Conecta la **pata corta (cátodo)** del LED a **GND (–)** mediante una **resistencia de 330 Ω**.  
4. Coloca el **potenciómetro de 5 kΩ** en el protoboard.  
5. Conecta un extremo del potenciómetro a **5V**, el otro a **GND**, y el pin central al **A0** del Arduino.  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente                    |
|--------------|--------------------------------|
| 9            | LED (salida PWM)              |
| A0           | Potenciómetro (entrada analógica) |

---

## ✅ Verificación  
- El LED debe **variar su brillo suavemente** al girar el potenciómetro.  
- Si el LED no enciende, revisa que esté conectado a un **pin PWM (9)** y que la **resistencia esté correctamente colocada**.  
- Abre el **Monitor Serial (9600 baudios)** para visualizar el valor analógico leído en tiempo real.  

---

## 🔎 Resultado esperado  
Al girar el potenciómetro, el **LED cambiará gradualmente su intensidad** gracias al uso del **PWM (Modulación por Ancho de Pulso)**, permitiendo un control analógico de brillo con señales digitales.
📘 Archivo: Practica 5 Instrucciones.md
markdown
Copy code
# 🔬 PRACTICA #5 – PWM: Control de Brillo de LED con Potenciómetro  

---

## 🎯 Objetivo  
Aprender el uso de **entradas analógicas** y la **función PWM (Pulse Width Modulation)** para controlar la intensidad de un LED de forma proporcional a la lectura de un **potenciómetro**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 LED  
- 1 resistencia de **330 Ω**  
- 1 resistencia de **5 kΩ**  
- 1 potenciómetro de **5 kΩ**  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica permite controlar el **brillo de un LED** mediante un **potenciómetro**, utilizando la **modulación por ancho de pulso (PWM)**.  
El Arduino lee un valor analógico (0 a 1023) del potenciómetro y lo convierte en una señal PWM (0 a 255) mediante la función `analogWrite()`.  
Esto permite que el brillo del LED cambie suavemente según la posición del potenciómetro.  

---

## 🧩 Instrucciones  
- **pinMode()** → Configura el modo de los pines (`INPUT` o `OUTPUT`).  
- **analogRead()** → Lee el valor del potenciómetro (0–1023).  
- **analogWrite()** → Genera una señal PWM en un pin (0–255).  
- **Serial.begin()** → Inicializa la comunicación serial.  
- **Serial.println()** → Envía valores al monitor serial.  
- **delay()** → Controla la suavidad del cambio de brillo.

---

## 💻 Código Original  

```cpp
// Declaración de variables de tipo entero
int ledPin = 9;   // Declaración del pin 9 como salida PWM (conectar LED)
int analogPin = 0; // Conectar un potenciómetro a la entrada analógica A0
int valor = 0;     // Variable entera para almacenar la lectura

void setup() {
  pinMode(ledPin, OUTPUT);    // Se establece el pin 9 como salida
  Serial.begin(9600);         // Inicia la comunicación serial a 9600 bits por segundo
}

void loop() {
  valor = analogRead(analogPin);  // Lee el valor del potenciómetro (0 a 1023)
  analogWrite(ledPin, valor / 4); // Convierte el valor a escala PWM (0 a 255)
  Serial.println(valor);          // Muestra el valor leído en el monitor serial
  delay(500);                     // Suaviza el cambio del brillo
}
💡 Explicación del código
analogRead(analogPin) obtiene el valor analógico del potenciómetro.

analogWrite(ledPin, valor / 4) convierte ese valor a una escala de 0–255 (PWM).

Serial.begin(9600) permite visualizar los valores en el Monitor Serial.

El delay(500) suaviza los cambios de brillo para que sean perceptibles.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #5 – PWM: Control de Brillo de LED con Potenciómetro
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Controla el brillo de un LED mediante la lectura analógica
   de un potenciómetro y la salida PWM en el pin 9.
----------------------------------------------------------- */

// ------------------------------
// 🔧 Declaración de variables
// ------------------------------
int ledPin = 9;     // Pin PWM donde está conectado el LED
int analogPin = A0; // Pin analógico conectado al potenciómetro
int valor = 0;      // Variable para almacenar la lectura del potenciómetro

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  pinMode(ledPin, OUTPUT);   // Configura el pin del LED como salida
  Serial.begin(9600);        // Inicializa la comunicación serial a 9600 baudios
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  valor = analogRead(analogPin);   // Lee el valor del potenciómetro (0 a 1023)

  // Calcula el valor proporcional para PWM (0–255)
  analogWrite(ledPin, valor / 4);  

  // Muestra en el monitor serial el valor leído
  Serial.println(valor);

  // Pequeña pausa para suavizar la transición del brillo
  delay(500);
}
🔎 Resultado Esperado
Al girar el potenciómetro, el LED cambiará progresivamente su intensidad gracias a la señal PWM.
En el Monitor Serial, se mostrarán los valores leídos (0–1023), reflejando la posición del potenciómetro en tiempo real.
