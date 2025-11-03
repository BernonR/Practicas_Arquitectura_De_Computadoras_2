# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #9 – Medidor de Luz con LDR**.

---

## 💡 Diagrama Físico  

<img width="564" height="492" alt="image" src="https://github.com/user-attachments/assets/520c5c27-784d-4148-adb9-35d58ec11b41" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🌞 Conexión del Sensor LDR  
1. Coloca la **LDR** en el protoboard.  
2. Conecta un extremo de la LDR al **pin A0** del Arduino UNO.  
3. Conecta el otro extremo de la LDR a **5V**.  
4. Conecta una **resistencia de 10 kΩ** entre el pin **A0** y **GND** (formando un divisor de voltaje).  

---

## 💡 Conexión de LEDs  
- Coloca **10 LEDs** en el protoboard, en líneas separadas.  
- Conecta el **ánodo (pata larga)** de cada LED a los **pines digitales 2 al 11** del Arduino UNO.  
- Conecta el **cátodo (pata corta)** de cada LED a **GND (–)** a través de una **resistencia de 330 Ω**.

---

## ⚙️ Tabla de pines  

| Pin Arduino | Elemento conectado | Descripción |
|--------------|--------------------|--------------|
| 2 – 11 | LED 1–10 | Salidas digitales (vúmetro) |
| A0 | LDR | Entrada analógica de luz |
| 5V | LDR / LEDs | Alimentación |
| GND | LDR / LEDs | Tierra común |

---

## ✅ Verificación  
- Abre el **Monitor Serial** (9600 baudios).  
- Al aumentar la luz sobre la LDR, más LEDs se encenderán.  
- En oscuridad, solo los primeros LEDs o ninguno encenderán.

---

## 🔎 Resultado esperado  
El circuito funcionará como un **vúmetro de luz**, encendiendo progresivamente los LEDs según la cantidad de luz detectada por la **LDR**.
