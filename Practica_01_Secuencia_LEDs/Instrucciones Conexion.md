## 🔌 Guía de Conexiones

Sigue estos pasos para armar el circuito de la **Práctica #1 – Secuencia de LEDs**.

### 💡 Diagrama Fisico

<img width="475" height="443" alt="image" src="https://github.com/user-attachments/assets/4488ef77-2274-4518-9a7a-e407b94bbaee" />


---

### 🧰 Conexiones básicas
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

### 💡 Conexión de LEDs
1. Coloca **10 LEDs** en el protoboard, uno por fila.  
2. Conecta la **pata larga (ánodo)** de cada LED a una **resistencia de 330 Ω**.  
3. El otro extremo de cada resistencia conéctalo a un **pin digital** del Arduino.  
4. Conecta la **pata corta (cátodo)** de todos los LEDs a la **línea GND (–)** del protoboard.

---

### ⚙️ Pines utilizados

| Pin Arduino | LED | Descripción |
|--------------|-----|--------------|
| 3  | LED 1  | Salida digital |
| 4  | LED 2  | Salida digital |
| 5  | LED 3  | Salida digital |
| 6  | LED 4  | Salida digital |
| 7  | LED 5  | Salida digital |
| 8  | LED 6  | Salida digital |
| 9  | LED 7  | Salida digital |
| 10 | LED 8  | Salida digital |
| 11 | LED 9  | Salida digital |
| 12 | LED 10 | Salida digital |

---

### ✅ Verificación
- Cada LED debe tener su **resistencia individual**.  
- El **ánodo** va hacia el pin digital (a través de la resistencia).  
- El **cátodo** va a la línea **GND (–)**.  
- Revisa las conexiones antes de subir el código al Arduino.

---

### 🔎 Resultado esperado
Los **10 LEDs** se encienden y apagan **uno por uno en secuencia**, generando un **efecto de movimiento luminoso continuo**.
