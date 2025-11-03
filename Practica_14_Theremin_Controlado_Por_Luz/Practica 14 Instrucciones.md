# 🔬 PRACTICA #14 – Theremin controlado por luz

---

## 🎯 Objetivo  
Emular un **Theremin electrónico** utilizando una **fotoresistencia (LDR)** y un **zumbador piezoeléctrico**, aprendiendo a calibrar sensores analógicos y generar sonido mediante la función `tone()`.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 Fotoresistencia (LDR)  
- 1 Resistencia de **10 kΩ**  
- 1 Zumbador piezoeléctrico  
- Cables de conexión  

---

## 🧠 Descripción  
Este proyecto simula un **Theremin**, un instrumento que produce sonido sin contacto físico.  
El circuito detecta los cambios de luz en una **LDR** y los traduce en diferentes **frecuencias de sonido** que se reproducen en un **zumbador**.  

Durante los primeros 5 segundos, el Arduino calibra automáticamente los valores **máximos y mínimos de luz**, utilizando el LED del pin 13 como indicador.  
Después, la variación en la cantidad de luz modifica la frecuencia generada por `tone()`, creando un efecto sonoro similar al clásico Theremin de las películas de ciencia ficción.

---

## 🧩 Instrucciones  
- **analogRead()** → Lee el valor del sensor LDR (0–1023).  
- **map()** → Convierte el rango leído a una frecuencia audible (50–4000 Hz).  
- **tone()** → Genera la señal sonora en el pin de salida.  
- **millis()** → Permite medir el tiempo para realizar la calibración de 5 segundos.  
- **digitalWrite()** → Enciende o apaga el LED indicador.  

---

## 💻 Código Original  

```cpp
int ValordelSensor;
int ValorMinimoSensor = 1023;
int ValorMaximoSensor = 0;
const int PinLed = 13;

void setup() {
  pinMode(PinLed, OUTPUT);
  digitalWrite(PinLed, HIGH);

  // Calibracion del sensor durante 5 segundos
  while (millis() < 5000) {
    ValordelSensor = analogRead(A0);
    if (ValordelSensor > ValorMaximoSensor) {
      ValorMaximoSensor = ValordelSensor;
    }
    if (ValordelSensor < ValorMinimoSensor) {
      ValorMinimoSensor = ValordelSensor;
    }
  }

  digitalWrite(PinLed, LOW); // Fin de calibracion
}

void loop() {
  ValordelSensor = analogRead(A0);
  int tono = map(ValordelSensor, ValorMinimoSensor, ValorMaximoSensor, 50, 4000);
  tone(8, tono, 20);
  delay(10);
}
💡 Explicación del código
Se definen las variables necesarias para almacenar los valores mínimo y máximo del sensor.

Durante 5 segundos, el programa calibra el rango de la LDR con ayuda del LED del pin 13.

Una vez calibrado, el sensor empieza a leer continuamente el valor de luz.

Con la función map(), el valor analógico se convierte en frecuencia entre 50 y 4000 Hz.

tone(8, tono, 20) genera el sonido en el zumbador durante 20 ms.

delay(10) estabiliza el bucle antes de la siguiente lectura.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #14 – Theremin controlado por luz
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa genera un sonido dependiente de la cantidad de luz
   que detecta una LDR. Durante 5 segundos iniciales calibra el sensor
   para obtener los valores máximo y mínimo de luz, luego convierte
   esas lecturas en tonos audibles mediante la función tone().
----------------------------------------------------------- */

int ValorSensor = 0;          // Variable para leer el sensor LDR
int ValorMinimoSensor = 1023; // Valor mínimo inicial
int ValorMaximoSensor = 0;    // Valor máximo inicial
const int PinLed = 13;        // LED integrado para indicar calibración
const int PinZumbador = 8;    // Pin del zumbador piezoeléctrico
const int PinLDR = A0;        // Pin analógico del sensor LDR

void setup() {
  pinMode(PinLed, OUTPUT);
  digitalWrite(PinLed, HIGH); // LED encendido indica calibración

  // Calibración durante 5 segundos
  while (millis() < 5000) {
    ValorSensor = analogRead(PinLDR);
    if (ValorSensor > ValorMaximoSensor)
      ValorMaximoSensor = ValorSensor;
    if (ValorSensor < ValorMinimoSensor)
      ValorMinimoSensor = ValorSensor;
  }

  digitalWrite(PinLed, LOW); // Fin de calibración
}

void loop() {
  // Lectura actual del sensor
  ValorSensor = analogRead(PinLDR);

  // Conversión del valor de luz a frecuencia sonora (50–4000 Hz)
  int frecuencia = map(ValorSensor, ValorMinimoSensor, ValorMaximoSensor, 50, 4000);

  // Reproducir tono según la cantidad de luz detectada
  tone(PinZumbador, frecuencia, 20);

  delay(10); // Pequeña pausa para estabilidad
}
🔎 Resultado Esperado
Durante los primeros 5 segundos el LED se mantiene encendido indicando calibración.

Luego, al mover la mano sobre la LDR, el tono emitido por el zumbador cambiará según la cantidad de luz.

Cuanta más sombra generes, más grave será el tono; con más luz, el tono será más agudo.

⚙️ Nota adicional
Puedes variar los límites del map() para modificar el rango de frecuencias.

Si el zumbador suena débil, verifica la conexión de GND y polaridad.

Este experimento combina calibración de sensores, PWM, y generación de audio digital con Arduino.
