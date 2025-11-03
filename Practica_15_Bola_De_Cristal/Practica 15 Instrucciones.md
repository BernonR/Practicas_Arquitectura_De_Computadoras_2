# 🔮 PRACTICA #15 – Bola de Cristal

---

## 🎯 Objetivo  
Aprender el uso de **pantallas LCD 16x2**, la instrucción **switch/case** y la función **random()** para generar respuestas aleatorias mediante un **sensor de inclinación**.

---

## 🧰 Materiales  
- Arduino UNO  
- Pantalla LCD 16x2  
- Sensor de inclinación  
- 1 Resistencia de 10 kΩ (pull-down)  
- 1 Resistencia de 220 Ω (para retroiluminación LCD)  
- 1 Potenciómetro de 10 kΩ (ajuste de contraste)  
- Cables de conexión  
- Protoboard  

---

## 🧠 Descripción  
Este proyecto simula una **bola de cristal mágica** que responde a tus preguntas con frases aleatorias mostradas en una **pantalla LCD**.  
Cuando el sensor de inclinación detecta movimiento, Arduino genera una respuesta aleatoria entre 8 posibles opciones y la muestra en la pantalla.  

La librería **LiquidCrystal** se usa para controlar la pantalla LCD con solo 6 pines de Arduino.  
La estructura **switch/case** permite mostrar diferentes respuestas según el número generado con **random(8)**.

---

## 🧩 Instrucciones  
- **LiquidCrystal.h** → Controla la pantalla LCD 16x2.  
- **lcd.begin()** → Inicializa la pantalla y define su tamaño.  
- **lcd.print()** → Muestra texto en pantalla.  
- **lcd.clear()** → Borra el contenido actual de la pantalla.  
- **digitalRead()** → Lee el estado del sensor de inclinación.  
- **switch/case** → Selecciona una respuesta aleatoria para mostrar.  
- **random()** → Genera un número aleatorio (0–7).  

---

## 💻 Código Original  

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PindelSensor = 6;
int EstadodelSensor = 0;
int EstadoPrevioSensor = 0;
int Contestar;

void setup() {
  lcd.begin(16, 2);
  pinMode(PindelSensor, INPUT);

  lcd.print("Preguntame");
  lcd.setCursor(0, 1);
  lcd.print("Bola de Cristal");
}

void loop() {
  EstadodelSensor = digitalRead(PindelSensor);

  if (EstadodelSensor != EstadoPrevioSensor) {
    if (EstadodelSensor == LOW) {
      Contestar = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("La bola dice:");
      lcd.setCursor(0, 1);

      switch (Contestar) {
        case 0: lcd.print("Si"); break;
        case 1: lcd.print("Es probable"); break;
        case 2: lcd.print("Ciertamente"); break;
        case 3: lcd.print("Buenas perspectivas"); break;
        case 4: lcd.print("No es seguro"); break;
        case 5: lcd.print("Pregunta de nuevo"); break;
        case 6: lcd.print("Ni idea"); break;
        case 7: lcd.print("No"); break;
      }
    }
  }
  EstadoPrevioSensor = EstadodelSensor;
}
💡 Explicación del Código
Inicialización:
Se configura la pantalla LCD y el sensor de inclinación (pin 6) como entrada digital.

Pantalla de bienvenida:
Al encender el Arduino, se muestra “Pregúntame” y “Bola de Cristal”.

Lectura del sensor:
Detecta un cambio de estado en el sensor de inclinación.

Generación de respuesta aleatoria:
Si se detecta movimiento, se genera un número aleatorio entre 0 y 7 con random(8).

Ejecución con switch/case:
Dependiendo del número generado, se muestra una frase diferente en la LCD.

Actualización de estado:
El valor anterior del sensor se guarda para detectar el próximo cambio.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #15 – Bola de Cristal
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: LiquidCrystal.h
   Descripción:
   Este programa muestra respuestas aleatorias en una pantalla LCD
   simulando una "bola de cristal". Usa un sensor de inclinación
   para generar las respuestas al detectar movimiento.
----------------------------------------------------------- */

#include <LiquidCrystal.h> // Librería para LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, EN, D4, D5, D6, D7

const int PinSensor = 6;   // Sensor de inclinación
int EstadoSensor = 0;      // Estado actual del sensor
int EstadoPrevio = 0;      // Estado anterior del sensor
int Respuesta = 0;         // Número aleatorio para respuesta

void setup() {
  lcd.begin(16, 2);             // Inicializa la pantalla 16x2
  pinMode(PinSensor, INPUT);    // Configura sensor como entrada

  // Mensaje de bienvenida
  lcd.print("Preguntame");
  lcd.setCursor(0, 1);
  lcd.print("Bola de Cristal");
}

void loop() {
  EstadoSensor = digitalRead(PinSensor); // Lee el estado actual

  // Detecta cambio de estado en el sensor
  if (EstadoSensor != EstadoPrevio) {
    if (EstadoSensor == LOW) {
      Respuesta = random(8); // Genera número aleatorio (0–7)

      lcd.clear();            // Limpia pantalla
      lcd.setCursor(0, 0);
      lcd.print("La bola dice:");
      lcd.setCursor(0, 1);

      // Muestra respuesta según número aleatorio
      switch (Respuesta) {
        case 0: lcd.print("Si"); break;
        case 1: lcd.print("Es probable"); break;
        case 2: lcd.print("Ciertamente"); break;
        case 3: lcd.print("Buenas perspectivas"); break;
        case 4: lcd.print("No es seguro"); break;
        case 5: lcd.print("Pregunta otra vez"); break;
        case 6: lcd.print("Ni idea"); break;
        case 7: lcd.print("No"); break;
      }
    }
  }

  EstadoPrevio = EstadoSensor; // Actualiza estado
}
