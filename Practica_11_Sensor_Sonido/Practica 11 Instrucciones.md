# 🔬 PRACTICA #11 – Sensor de Sonido (KY-038 / LM393)

---

## 🎯 Objetivo  
Aprender a utilizar un **sensor de sonido** para detectar variaciones de ruido en el ambiente y activar una salida digital (LED) cuando el nivel supere un umbral determinado.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- Módulo Sensor de Sonido (KY-038 o LM393)  
- 1 LED  
- 1 resistencia de **330 Ω**  
- Cables de conexión  

---

## 🧠 Descripción  
El sensor de sonido **KY-038 / LM393** detecta el nivel de ruido ambiental mediante un micrófono electret.  
Dispone de **dos salidas**:

- **AO (analógica):** devuelve un valor entre **0 y 1023**, proporcional a la intensidad del sonido.  
- **DO (digital):** se activa (HIGH) cuando el sonido supera un nivel establecido por el **potenciómetro azul** de ajuste de sensibilidad.

---

## ⚙️ Componentes principales del módulo

| Parte | Función |
|-------|----------|
| **Micrófono electret** | Convierte ondas sonoras en señales eléctricas. |
| **Comparador LM393** | Compara la señal del micrófono con el nivel de referencia ajustado. |
| **Potenciómetro (preset)** | Permite modificar la sensibilidad del sensor. |
| **LED de salida digital** | Indica cuándo el módulo detecta un sonido. |
| **LED de alimentación** | Muestra que el módulo está energizado. |

---

## 📐 Funcionamiento  
Cuando el micrófono detecta un sonido fuerte (por ejemplo, una palmada), la salida **DO** se pone en estado **HIGH**, encendiendo el LED conectado.  
Al mismo tiempo, la salida **AO** entrega un valor analógico proporcional a la intensidad del sonido, que puede verse en el **Monitor Serial**.

---

## 🧩 Instrucciones  
- **digitalWrite()** → Controla el encendido y apagado del LED.  
- **digitalRead()** → Lee si el sensor detecta un sonido (HIGH/LOW).  
- **analogRead()** → Lee el valor analógico del nivel de ruido.  
- **Serial.println()** → Muestra los valores y mensajes en el Monitor Serial.  
- **delay()** → Pausa el programa por un tiempo definido.  
- **Serial.begin()** → Inicializa la comunicación serial (9600 baudios).

---

## 💻 Código Original  

```cpp
int MIC_D = 12;
int MIC_A = 0;
int LED = 2;
int VALOR;
bool SONIDO;

void setup() {
  Serial.begin(9600);
  pinMode(MIC_D, INPUT);
  pinMode(MIC_A, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  VALOR = analogRead(MIC_A);
  Serial.println(VALOR);
  delay(500);

  SONIDO = digitalRead(MIC_D);

  if (SONIDO == HIGH) {
    Serial.println("SE DETECTO SONIDO");
    digitalWrite(LED, HIGH);
    delay(100);
  } else {
    digitalWrite(LED, LOW);
    delay(100);
  }
}
💡 Explicación del código
Se leen las entradas analógica y digital del módulo.

Si la lectura digital (DO) es HIGH, significa que el sonido superó el umbral configurado.

Se enciende el LED y se muestra el mensaje en el Monitor Serial.

También se imprimen los valores analógicos (AO) para observar la intensidad del sonido.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #11 – Sensor de Sonido (KY-038 / LM393)
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa detecta sonidos usando un sensor KY-038
   o LM393. Enciende un LED cuando el ruido supera un
   umbral y muestra los valores en el Monitor Serial.
----------------------------------------------------------- */

int MIC_D = 12;    // Pin digital del sensor (DO)
int MIC_A = A0;    // Pin analógico del sensor (AO)
int LED = 2;       // Pin para el LED indicador
int VALOR = 0;     // Variable para valor analógico
bool SONIDO = 0;   // Estado del sonido (detecto o no)

void setup() {
  Serial.begin(9600);       // Comunicación serial
  pinMode(MIC_D, INPUT);    // Entrada digital
  pinMode(MIC_A, INPUT);    // Entrada analógica
  pinMode(LED, OUTPUT);     // LED de salida
}

void loop() {
  // Lectura analógica
  VALOR = analogRead(MIC_A);
  Serial.print("Nivel de sonido: ");
  Serial.println(VALOR);
  delay(300);

  // Lectura digital
  SONIDO = digitalRead(MIC_D);

  // Si se detecta sonido
  if (SONIDO == HIGH) {
    Serial.println("🔊 SE DETECTO SONIDO 🔊");
    digitalWrite(LED, HIGH);
    delay(100);
  } 
  else {
    digitalWrite(LED, LOW);
  }
  delay(100);
}
🔎 Resultado Esperado
El sistema reaccionará ante sonidos fuertes:

El LED se encenderá por un instante.

En el Monitor Serial se mostrará:

python-repl
Copy code
Nivel de sonido: 320
SE DETECTO SONIDO
Nivel de sonido: 210
...
Si no hay ruido, el LED permanecerá apagado.

⚙️ Nota adicional
Puedes ajustar la sensibilidad del sensor girando el potenciómetro azul (en sentido horario para hacerlo más sensible).

La salida analógica permite crear sistemas más precisos, como medidores de nivel de ruido o activadores por voz.

El módulo LM393 funciona con 5V, por lo que es ideal para el Arduino UNO sin componentes adicionales.
