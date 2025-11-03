# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #2 – Secuencia de LEDs con Variables**.

---

## 💡 Diagrama Físico  

<img width="688" height="392" alt="image" src="https://github.com/user-attachments/assets/7f15922a-28d7-4da5-a466-ab794f092101" />


---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

## 💡 Conexión de LEDs  
1. Coloca **10 LEDs** en el protoboard, uno por fila.  
2. Conecta la **pata larga (ánodo)** de cada LED a una **resistencia de 330 Ω**.  
3. El otro extremo de cada resistencia conéctalo a los **pines digitales 0 al 9** del Arduino UNO.  
4. Conecta la **pata corta (cátodo)** de todos los LEDs a la **línea GND (–)** del protoboard.  

---

## ⚙️ Tabla de pines  

| Pin Arduino | LED |
|--------------|-----|
| 0 | LED 1 |
| 1 | LED 2 |
| 2 | LED 3 |
| 3 | LED 4 |
| 4 | LED 5 |
| 5 | LED 6 |
| 6 | LED 7 |
| 7 | LED 8 |
| 8 | LED 9 |
| 9 | LED 10 |

---

## ✅ Verificación  
- Cada LED debe tener su **resistencia individual**.  
- El **ánodo (pata larga)** va al **pin digital** (a través de la resistencia).  
- El **cátodo (pata corta)** va a **GND (–)**.  
- Revisa todas las conexiones antes de subir el código al Arduino.  

---

## 🔎 Resultado esperado  
Al ejecutar el programa, los **10 LEDs** se encenderán uno tras otro en una **secuencia rápida**, mostrando el uso de **variables** y **bucles for()** para controlar las salidas digitales de forma eficiente.
