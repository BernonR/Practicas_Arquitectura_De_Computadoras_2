# 🔬 PRACTICA #12 – Lámpara de Mezcla de Colores (RGB + LDR)

---

## 🎯 Objetivo  
Aprender a utilizar **fotoresistencias (LDR)** y **modulación PWM** para crear una lámpara RGB que varíe sus colores suavemente según la intensidad de luz del ambiente.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 LED RGB de cátodo común  
- 3 resistencias de **220 Ω**  
- 3 resistencias de **10 kΩ**  
- 3 sensores LDR  
- 3 papeles celofán (rojo, verde, azul)  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica combina **entradas analógicas** (LDR) y **salidas PWM** (LED RGB) para controlar la intensidad de cada color según la luz ambiental.  
Cada LDR detecta una tonalidad filtrada por el papel celofán y modifica la intensidad del color correspondiente del LED RGB.

La función `analogWrite()` permite aplicar **modulación por ancho de pulso (PWM)** para variar el brillo de los LEDs con valores de **0 a 255**, controlando así la mezcla final del color.

---

## 🧩 Instrucciones  
- **analogRead()** → Lee el nivel de luz del sensor (0 a 1023).  
- **analogWrite()** → Controla la intensidad del color del LED (0 a 255).  
- **Serial.println()** → Muestra los valores en el monitor serial.  
- **delay()** → Permite estabilizar las lecturas.  
- **pinMode()** → Configura los pines de entrada/salida.  

---

## 💻 Código Original  

```cpp
const int PinLedVerde = 9;
const int PinLedRojo = 11;
const int PinLedAzul = 10;

const int PinEntradaLDR_Rojo = A0;
const int PinEntradaLDR_Verde = A1;
const int PinEntradaLDR_Azul = A2;

int ValorSensorRojo = 0;
int ValorSensorVerde = 0;
int ValorSensorAzul = 0;

int ValorRojo = 0;
int ValorVerde = 0;
int ValorAzul = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PinLedVerde, OUTPUT);
  pinMode(PinLedRojo, OUTPUT);
  pinMode(PinLedAzul, OUTPUT);
}

void loop() {
  ValorSensorRojo = analogRead(PinEntradaLDR_Rojo);
  delay(5);
  ValorSensorVerde = analogRead(PinEntradaLDR_Verde);
  delay(5);
  ValorSensorAzul = analogRead(PinEntradaLDR_Azul);

  Serial.print("Mapa de valores sensores\t Rojo: ");
  Serial.print(ValorSensorRojo);
  Serial.print("\t Verde: ");
  Serial.print(ValorSensorVerde);
  Serial.print("\t Azul: ");
  Serial.println(ValorSensorAzul);

  ValorRojo = ValorSensorRojo / 4;
  ValorVerde = ValorSensorVerde / 4;
  ValorAzul = ValorSensorAzul / 4;

  analogWrite(PinLedRojo, ValorRojo);
  analogWrite(PinLedVerde, ValorVerde);
  analogWrite(PinLedAzul, ValorAzul);
}
💡 Explicación del código
Las LDR generan valores de luz entre 0 y 1023.

Cada lectura se divide entre 4 para ajustarla al rango PWM (0–255).

Se imprime el mapa de valores para observar la respuesta de cada sensor.

El color del LED RGB cambia de acuerdo con la luz captada en cada canal (rojo, verde y azul).

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #12 – Lámpara de Mezcla de Colores
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Esta práctica utiliza tres sensores LDR con filtros de color
   (rojo, verde y azul) para variar el brillo de un LED RGB
   mediante modulación PWM, creando una mezcla de color dinámica.
----------------------------------------------------------- */

const int PinLedRojo = 11;
const int PinLedVerde = 9;
const int PinLedAzul = 10;

const int LDR_Rojo = A0;
const int LDR_Verde = A1;
const int LDR_Azul = A2;

int valorR, valorG, valorB;
int pwmR, pwmG, pwmB;

void setup() {
  Serial.begin(9600);
  pinMode(PinLedRojo, OUTPUT);
  pinMode(PinLedVerde, OUTPUT);
  pinMode(PinLedAzul, OUTPUT);
}

void loop() {
  // Lectura analógica de las LDR
  valorR = analogRead(LDR_Rojo);
  valorG = analogRead(LDR_Verde);
  valorB = analogRead(LDR_Azul);

  // Conversión a rango PWM (0–255)
  pwmR = valorR / 4;
  pwmG = valorG / 4;
  pwmB = valorB / 4;

  // Impresión de valores en el Monitor Serial
  Serial.print("Rojo: ");
  Serial.print(pwmR);
  Serial.print("\tVerde: ");
  Serial.print(pwmG);
  Serial.print("\tAzul: ");
  Serial.println(pwmB);

  // Ajuste del brillo de cada canal RGB
  analogWrite(PinLedRojo, pwmR);
  analogWrite(PinLedVerde, pwmG);
  analogWrite(PinLedAzul, pwmB);

  delay(100);
}
🔎 Resultado Esperado
La lámpara cambia su color suavemente según la cantidad de luz detectada por los tres sensores:

Más luz sobre el sensor rojo → mayor brillo del LED rojo.

Más luz sobre el verde → aumenta el verde.

Más luz sobre el azul → domina el azul.

Al variar la iluminación ambiental, el LED mezcla los tres colores creando distintos tonos.

⚙️ Nota adicional
Puedes colocar una pelota de ping pong o una cúpula difusora sobre el LED RGB para suavizar la mezcla de colores.

Los pines 9, 10 y 11 son PWM (~), por lo que pueden controlar el brillo de forma analógica.

Este montaje demuestra la relación entre entradas analógicas y salidas PWM, ideal para proyectos de iluminación reactiva o ambiental.
