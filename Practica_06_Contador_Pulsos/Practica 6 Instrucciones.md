# 🔬 PRACTICA #6 – Contador de Pulsos  

---

## 🎯 Objetivo  
Aprender cómo **almacenar y contar pulsos** generados por un **switch o botón**, y mostrar el resultado mediante el **Monitor Serial**.

---

## 🧰 Materiales  
- Arduino UNO  
- Protoboard  
- 1 LED  
- 1 resistencia de **330 Ω**  
- 1 resistencia de **5 kΩ**  
- 1 **switch o pulsador**  
- Cables de conexión  

---

## 🧠 Descripción  
Esta práctica permite registrar cuántas veces se presiona un **botón** y mostrar ese conteo en el **Monitor Serial**.  
Cada vez que se detecta un cambio en el estado del botón, se incrementa un contador y el resultado se envía al puerto serial del Arduino.

---

## 🧩 Instrucciones  
- **pinMode()** → Configura pines como `INPUT` o `OUTPUT`.  
- **digitalRead()** → Lee el estado de un pin digital (`HIGH` o `LOW`).  
- **digitalWrite()** → Enciende o apaga un pin digital (`HIGH` o `LOW`).  
- **Serial.begin()** → Inicia la comunicación serial con una velocidad específica (9600 baudios).  
- **Serial.print() / println()** → Muestra información en el Monitor Serial.  
- **delay()** → Evita lecturas rápidas sucesivas.

---

## 💻 Código Original  

```cpp
int led = 11;
int boton = 13;
int valor = 0;
int contador = 0;
int estadoanteriorboton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  valor = digitalRead(boton);
  digitalWrite(led, valor);

  if (valor != estadoanteriorboton) {
    if (valor == 1) {
      contador++;
      Serial.print(contador);
      Serial.write(10);
      Serial.write(13);
    }
  }

  estadoanteriorboton = valor;
}
💡 Explicación del código
Se definen los pines del LED (11) y el botón (13).

Cada vez que el estado del botón cambia, se incrementa el contador.

Serial.print(contador) muestra el valor actual en el Monitor Serial.

El LED refleja el estado del botón encendiéndose con cada pulsación.

🧮 Código Mejorado (con comentarios)
cpp
Copy code
/* -----------------------------------------------------------
   PRACTICA #6 – Contador de Pulsos
   Alumno: Bernon Romero
   Placa: Arduino UNO
   Librerías: Ninguna
   Descripción:
   Este programa cuenta el número de veces que se presiona un
   botón y muestra el valor en el Monitor Serial. Cada vez que
   se detecta un pulso, el LED se enciende brevemente.
----------------------------------------------------------- */

// ------------------------------
// 🔧 Declaración de variables
// ------------------------------
int led = 11;                 // Pin del LED (salida digital)
int boton = 13;               // Pin del botón (entrada digital)
int valor = 0;                // Estado actual del botón
int contador = 0;             // Contador de pulsos
int estadoAnteriorBoton = 0;  // Estado previo del botón

// ------------------------------
// ⚙️ Configuración inicial
// ------------------------------
void setup() {
  Serial.begin(9600);        // Inicializa comunicación serial
  pinMode(led, OUTPUT);      // Configura el pin del LED como salida
  pinMode(boton, INPUT);     // Configura el pin del botón como entrada
}

// ------------------------------
// 🔁 Bucle principal
// ------------------------------
void loop() {
  valor = digitalRead(boton);      // Lee el estado actual del botón
  digitalWrite(led, valor);        // Enciende/apaga LED según el botón

  // Si hay un cambio en el estado del botón...
  if (valor != estadoAnteriorBoton) {
    // ...y si se ha presionado (valor HIGH)
    if (valor == HIGH) {
      contador++;                   // Incrementa el contador
      Serial.print("Pulsos: ");     // Muestra texto
      Serial.println(contador);     // Muestra número actual de pulsos
    }
  }

  estadoAnteriorBoton = valor;     // Guarda el estado actual
  delay(50);                       // Pequeño retardo para evitar rebotes
}
🔎 Resultado Esperado
Cada vez que el usuario presione el switch, el LED parpadeará y el contador aumentará en uno, mostrando el número total de pulsos detectados en el Monitor Serial (9600 baudios).
