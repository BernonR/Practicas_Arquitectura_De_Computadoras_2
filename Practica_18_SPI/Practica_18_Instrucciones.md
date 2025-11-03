# 🧩 Práctica #18 – Comunicación SPI entre Arduinos

---

## 🎯 Objetivo
Implementar una comunicación **SPI (Serial Peripheral Interface)** entre dos placas **Arduino UNO**, configuradas en modo **maestro y esclavo**, para lograr un intercambio **Full Duplex**, es decir, que ambos puedan enviar y recibir información simultáneamente.

---

## 🧠 Conceptos Clave
El protocolo **SPI** es una interfaz de comunicación **síncrona y full duplex** que permite la transferencia rápida de datos entre un dispositivo maestro y uno o varios esclavos.

### Líneas principales del bus SPI
| Línea | Nombre | Descripción |
|--------|----------|-------------|
| MOSI | Master Out, Slave In | Datos del maestro hacia el esclavo |
| MISO | Master In, Slave Out | Datos del esclavo hacia el maestro |
| SCK | Serial Clock | Señal de reloj generada por el maestro |
| SS | Slave Select | Selecciona el esclavo activo (LOW = activo) |

---

## ⚙️ Materiales
| Cantidad | Componente | Descripción |
|-----------|-------------|-------------|
| 2 | Placas Arduino UNO | Una actuará como maestro y la otra como esclavo |
| 1 | Protoboard | Para realizar las conexiones SPI |
| 8 | Cables Dupont macho-macho | Para conectar los pines SPI entre Arduinos |
| 1 | Cable USB | Para alimentación y carga del programa |

---

## 💻 Desarrollo
Se implementaron tres ejemplos para comprender la comunicación SPI entre Arduinos.

---

### 🧩 Ejemplo 1 – Maestro Básico

```cpp
#include <SPI.h>

char mensaje[] = "Hola desde Maestro";
byte indice = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop() {
  digitalWrite(10, LOW);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(mensaje[indice]);
  SPI.endTransaction();
  digitalWrite(10, HIGH);
  Serial.print("Maestro envió: ");
  Serial.println(mensaje[indice]);
  indice++;
  if (mensaje[indice] == '\0') indice = 0;
  delay(1000);
}
🧩 Ejemplo 2 – Esclavo Básico
cpp
Copy code
#include <SPI.h>

volatile byte datoRecibido;

void setup() {
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect) {
  datoRecibido = SPDR;
  SPDR = datoRecibido + 1;
}

void loop() {
  Serial.print("Esclavo recibió: ");
  Serial.println((char)datoRecibido);
  delay(1000);
}
🧩 Ejemplo 3 – Comunicación Full Duplex
Maestro Full Duplex
cpp
Copy code
#include <SPI.h>

char mensaje[] = "BR";
byte recibido;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop() {
  digitalWrite(10, LOW);
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  for (byte i = 0; i < sizeof(mensaje); i++) {
    recibido = SPI.transfer(mensaje[i]);
    Serial.print("Envío: ");
    Serial.print(mensaje[i]);
    Serial.print(" | Recibió: ");
    Serial.println((char)recibido);
    delay(500);
  }
  SPI.endTransaction();
  digitalWrite(10, HIGH);
  delay(1000);
}
Esclavo Full Duplex
cpp
Copy code
#include <SPI.h>

volatile byte recibido;
byte respuesta;

void setup() {
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect) {
  recibido = SPDR;
  respuesta = recibido + 1;
  SPDR = respuesta;
}

void loop() {
  Serial.print("Recibido: ");
  Serial.print((char)recibido);
  Serial.print(" -> Enviado: ");
  Serial.println((char)respuesta);
  delay(1000);
}
📈 Resultados
Se logra la transmisión simultánea entre maestro y esclavo.

El maestro envía datos a través de MOSI, mientras que el esclavo responde por MISO.

El intercambio ocurre sincronizado por la señal de reloj SCK.

Salida esperada (Monitor Serial):

Maestro

makefile
Copy code
Envío: B | Recibió: C
Envío: R | Recibió: S
Esclavo

yaml
Copy code
Recibido: B -> Enviado: C
Recibido: R -> Enviado: S
📊 Conclusiones
SPI permite una comunicación síncrona y rápida entre múltiples dispositivos.

Su arquitectura Full Duplex facilita el intercambio simultáneo de datos.

Requiere sincronización precisa de reloj y tierra común.

Es ideal para proyectos que necesiten transferencia rápida y confiable de datos.

