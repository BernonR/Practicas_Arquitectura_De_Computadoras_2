# 📡 PRACTICA #16 – Control Remoto Infrarrojo con Arduino

---

## 🎯 Objetivo  
Aprender a recibir, decodificar y utilizar señales de un **control remoto IR** mediante la **librería IRremote**, controlando salidas digitales (LEDs) con los códigos recibidos.

---

## 🧰 Materiales
- Arduino UNO  
- Módulo receptor infrarrojo (KY-022 o equivalente)  
- 4 LEDs  
- 4 resistencias de 220 Ω  
- Control remoto IR (universal o de TV)  
- Protoboard  
- Cables Dupont  

---

## 🧠 Descripción  
Esta práctica permite controlar pines digitales del Arduino mediante un **control remoto infrarrojo**, usando la **librería IRremote**, que soporta protocolos de las marcas **Sony, LG, NEC, Samsung, Panasonic**, entre otras.  

El Arduino recibe los datos del control remoto por el módulo IR y, dependiendo del código recibido, ejecuta diferentes acciones como **encender o apagar LEDs**.

---

## 🧩 Instrucciones  
1. Descargar e instalar la librería **IRremote** desde:  
   👉 [https://github.com/z3t0/Arduino-IRremote](https://github.com/z3t0/Arduino-IRremote)
2. Conectar el módulo receptor IR al **pin 11**.  
3. Subir los programas de ejemplo para:  
   - **Encender un LED con cualquier tecla.**  
   - **Decodificar códigos IR.**  
   - **Controlar múltiples LEDs.**
4. Verificar los valores recibidos en el monitor serial a **9600 baudios**.  
5. Asignar cada código de tecla a un LED diferente usando `switch/case`.

---

## 💻 Ejemplo 1 – Encender LED con cualquier tecla

```cpp
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean estadoLED = LOW;

void setup() {
  irrecv.enableIRIn(); // Inicializa recepción IR
  pinMode(13, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    estadoLED = !estadoLED;
    digitalWrite(13, estadoLED ? HIGH : LOW);
    irrecv.resume(); // Listo para nueva lectura
  }
  delay(300);
}
Explicación:
Cada vez que el módulo IR recibe un dato, se invierte el estado del LED del pin 13.

💻 Ejemplo 2 – Decodificar códigos del control remoto
cpp
Copy code
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Codigo HEX: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(300);
}
Explicación:
Este programa muestra el código HEX de cada tecla en el Monitor Serial.
Se usa para identificar qué valor tiene cada botón del control remoto.

💻 Ejemplo 3 – Controlar 4 LEDs con el control remoto (NEC)
cpp
Copy code
#include <IRremote.h>

int receptor = 11;
IRrecv irrecv(receptor);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0x00FF30CF: Serial.println("Tecla: 4");
        digitalWrite(4, !digitalRead(4)); break;
      case 0x00FF18E7: Serial.println("Tecla: 5");
        digitalWrite(5, !digitalRead(5)); break;
      case 0x00FF7A85: Serial.println("Tecla: 6");
        digitalWrite(6, !digitalRead(6)); break;
      case 0x00FF10EF: Serial.println("Tecla: 7");
        digitalWrite(7, !digitalRead(7)); break;
      default:
        Serial.println("Otra tecla");
        break;
    }
    irrecv.resume();
  }
}
Explicación:
Cada tecla (4–7) activa o desactiva su respectivo LED.
Los códigos 0x00FF30CF, etc., corresponden al control NEC del kit.

💻 Ejemplo 4 – Control remoto SONY
cpp
Copy code
#include <IRremote.h>

int receptor = 11;
IRrecv irrecv(receptor);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  for (int i = 4; i <= 7; i++) pinMode(i, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xC10: Serial.println("Tecla: 4"); digitalWrite(4, !digitalRead(4)); break;
      case 0x210: Serial.println("Tecla: 5"); digitalWrite(5, !digitalRead(5)); break;
      case 0xA10: Serial.println("Tecla: 6"); digitalWrite(6, !digitalRead(6)); break;
      case 0x610: Serial.println("Tecla: 7"); digitalWrite(7, !digitalRead(7)); break;
      default: Serial.println("Otra tecla"); break;
    }
    irrecv.resume();
  }
  delay(300);
}
💡 Explicación General
IRrecv: Objeto que gestiona la recepción de señales infrarrojas.

decode_results: Estructura que almacena el valor recibido (HEX).

enableIRIn(): Activa el receptor IR.

irrecv.decode(): Detecta si llegó un nuevo código.

irrecv.resume(): Reinicia la recepción para el siguiente dato.

switch/case: Evalúa qué tecla se presionó y ejecuta la acción.

🔎 Resultado Esperado
Al presionar una tecla del control, se verá en el Monitor Serial el nombre de la tecla y su código.

Los LEDs del pin 4–7 se encenderán o apagarán dependiendo del botón presionado.

⚙️ Nota adicional
Si los códigos no coinciden, usa el Ejemplo 2 (decodificador) para identificar los valores de tu control.

La librería IRremote debe estar correctamente instalada en tu IDE de Arduino.

También puedes reemplazar los LEDs por relés, motores o cualquier actuador digital.
