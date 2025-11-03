# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #15 – Bola de Cristal**.

---

## 💡 Diagrama Físico  

<img width="336" height="324" alt="image" src="https://github.com/user-attachments/assets/68e9bda1-da31-4c9d-94a6-f7ed8e82b7cf" />

<img width="496" height="218" alt="image" src="https://github.com/user-attachments/assets/38598237-3e73-46a6-a25f-4a5ef0636be2" />



---

## 🧰 Conexiones Principales  
- Conecta **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

## 🧿 Sensor de Inclinación  
1. Coloca el sensor de inclinación en la placa de pruebas.  
2. Conecta un terminal a **+5V**.  
3. Conecta el otro terminal al **pin digital 6** del Arduino y a **GND** mediante una **resistencia de 10 kΩ** (pull-down).  
   > Este sensor detectará el movimiento o inclinación de la “bola de cristal”.

---

## 🧮 Conexión de la Pantalla LCD (16x2)  
Conecta los pines de la LCD al Arduino según la siguiente tabla:

| Pin LCD | Descripción             | Conexión Arduino |
|----------|------------------------|------------------|
| 1 (Vss)  | Tierra (GND)           | GND              |
| 2 (Vcc)  | Alimentación +5 V      | 5V               |
| 3 (Vo)   | Contraste (por potenciómetro) | Terminal central del potenciómetro |
| 4 (RS)   | Registro de selección  | Pin 12           |
| 5 (RW)   | Modo lectura/escritura | GND (modo escritura) |
| 6 (EN)   | Habilitación           | Pin 11           |
| 11 (D4)  | Datos 4                | Pin 5            |
| 12 (D5)  | Datos 5                | Pin 4            |
| 13 (D6)  | Datos 6                | Pin 3            |
| 14 (D7)  | Datos 7                | Pin 2            |
| 15 (LED+) | Luz de fondo          | 5V mediante una resistencia de 220 Ω |
| 16 (LED–) | Luz de fondo (GND)    | GND              |

---

## ⚙️ Potenciómetro para Contraste  
- Conecta un extremo del potenciómetro a **5V**, el otro a **GND**,  
  y el **terminal central (wiper)** al pin **3 (Vo)** de la pantalla LCD.  
- Este potenciómetro ajusta la visibilidad de los caracteres en pantalla.

---

## ✅ Verificación  
1. Carga el programa en la placa Arduino.  
2. Asegúrate de que la pantalla LCD muestre el texto:  
Preguntame
Bola de Cristal

3. Al mover la placa (sensor de inclinación), la pantalla mostrará una respuesta aleatoria.  

---

## 🔎 Resultado Esperado  
La **pantalla LCD** mostrará una respuesta diferente cada vez que el sensor detecte movimiento.  
Así, la “bola de cristal” contestará preguntas al azar con mensajes como:  
> “Sí”, “Es probable”, “Pregunta de nuevo”, “No es seguro”, etc.
