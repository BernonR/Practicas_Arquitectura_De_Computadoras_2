# 🔬 PRACTICA #13 – Indicador del Estado de Ánimo (Servo + Potenciómetro)

---

## 🎯 Objetivo  
Aprender a controlar la posición de un **servomotor** mediante un **potenciómetro**, aplicando el uso de la **función map()** y la **librería Servo** de Arduino para transformar valores analógicos en movimiento mecánico.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 servomotor (SG90 o similar)  
- 1 potenciómetro de 10 kΩ  
- 2 condensadores de **100 µF**  
- Cables de conexión  
- Cartón o puntero (para el indicador)

---

## 🧠 Descripción  
El proyecto permite construir un **medidor mecánico de emociones** usando un **servo** controlado por un **potenciómetro**.  
Al girar el potenciómetro, el valor leído (0–1023) se convierte en un ángulo (0–179°) usando la función `map()`.  
El servo se mueve proporcionalmente a esta escala, mostrando el “estado de ánimo” mediante el movimiento de una flecha o brazo.

Los **condensadores de 100 µF** actúan como **filtros de desacoplo**, evitando caídas de tensión cuando el servo consume corriente.

---

## 🧩 Instrucciones  
- **Servo.h** → Librería que permite controlar el servomotor.  
- **map()** → Convierte el rango de lectura del potenciómetro (0–1023) en grados (0–179).  
- **analogRead()** → Lee el valor analógico del potenciómetro.  
- **write()** → Mueve el servo al ángulo deseado.  
- **Serial.print()** → Muestra valores en el monitor serial.  
- **delay()** → Estabiliza la actualización de posición.  

---

## 💻 Código Original  

```cpp
#include <Servo.h>

Servo MiServo;

int const PinPot = A0;
int ValorPot;
int Angulo;

void setup() {
  MiServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  ValorPot = analogRead(PinPot);
  Serial.print("Posicion del potenciometro: ");
  Serial.print(ValorPot);

  Angulo = map(ValorPot, 0, 1023, 0, 179);
  Serial.print(" , Angulo: ");
  Serial.println(Angulo);

  MiServo.write(Angulo);
  delay(100);
}
💡 Explicación del código
Se utiliza la librería Servo.h para generar los pulsos PWM que controlan la posición del motor.

La lectura del potenciómetro (analogRead) entrega valores de 0 a 1023.

La función map() convierte estos valores en grados de 0 a 179.

El servo se mueve al ángulo calculado con MiServo.write(Angulo).

Los valores se imprimen en el monitor serial para observar la relación entre el giro del potenciómetro y la posición del servo.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #13 – Indicador del Estado de Ánimo
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Servo.h
   Descripción:
   Este programa controla un servomotor mediante un potenciómetro.
   El valor leído (0–1023) se convierte en un ángulo (0–179°)
   usando map(), moviendo una flecha que actúa como indicador.
----------------------------------------------------------- */

#include <Servo.h>          // Librería para controlar servomotores

Servo MiServo;              // Objeto del tipo Servo

const int PinPot = A0;      // Pin del potenciómetro
int ValorPot = 0;           // Valor leído del potenciómetro
int Angulo = 0;             // Ángulo de giro del servo

void setup() {
  MiServo.attach(9);        // Pin de control del servo
  Serial.begin(9600);       // Comunicación serial para monitoreo
}

void loop() {
  // Lectura del potenciómetro
  ValorPot = analogRead(PinPot);

  // Escalado del valor a grados (0–179)
  Angulo = map(ValorPot, 0, 1023, 0, 179);

  // Mostrar valores en el monitor serial
  Serial.print("Posicion del potenciometro: ");
  Serial.print(ValorPot);
  Serial.print(" , Angulo: ");
  Serial.println(Angulo);

  // Movimiento del servomotor
  MiServo.write(Angulo);

  delay(100); // Pequeña pausa para estabilidad
}
🔎 Resultado Esperado
Al girar el potenciómetro, el servomotor rotará entre 0° y 180°.

En el Monitor Serial, se mostrará algo como:

yaml
Copy code
Posicion del potenciometro: 150 , Angulo: 26
Posicion del potenciometro: 880 , Angulo: 154
Puedes añadir una flecha de cartón sobre el brazo del servo para crear un medidor con etiquetas:

“No entrar 😠”

“Por favor llamar 🙂”

“Puede pasar 😄”

⚙️ Nota adicional
Si el servo vibra, añade un condensador de 100 µF entre 5V y GND cerca de su alimentación.

También puedes conectar sensores distintos (temperatura, luz o humedad) para controlar la posición del servo con otras variables.

Este montaje ilustra la función map(), útil para convertir rangos de entrada analógica en escalas físicas o mecánicas.
