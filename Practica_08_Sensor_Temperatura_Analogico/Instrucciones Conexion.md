# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #8 – Sensor de Temperatura Analógico (LM35)**.

---

## 💡 Diagrama Físico  

<img width="586" height="459" alt="image" src="https://github.com/user-attachments/assets/c3f64bc4-4f46-4e6d-a660-744da9f89099" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🌡️ Conexión del Sensor LM35  
1. Coloca el sensor **LM35** en el protoboard (la cara plana hacia ti).  
2. Conecta el **pin izquierdo (Vs)** a **5V**.  
3. Conecta el **pin central (Vout)** al **pin A0** del Arduino UNO.  
4. Conecta el **pin derecho (GND)** a la **línea azul (–)**.  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Conexión LM35 | Descripción |
|--------------|----------------|--------------|
| A0 | Vout (centro) | Señal analógica del sensor |
| 5V | Vs (izquierdo) | Alimentación |
| GND | GND (derecho) | Tierra |

---

## ✅ Verificación  
- Conecta el Arduino mediante USB.  
- Abre el **Monitor Serial** (9600 baudios).  
- Observa los valores de temperatura actualizándose cada segundo.  

---

## 🔎 Resultado esperado  
El **sensor LM35** mide la temperatura ambiente y el **Arduino** la muestra en el **Monitor Serial** expresada en **grados Celsius (°C)**, actualizándose cada segundo.
