# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #10 – Sensor de Temperatura y Humedad DHT11**.

---

## 💡 Diagrama Físico  

<img width="765" height="548" alt="image" src="https://github.com/user-attachments/assets/29df9530-e014-43b8-a96a-f574f42eb735" />


---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🌡️ Conexión del Sensor DHT11  
1. Coloca el sensor **DHT11** en el protoboard (cara frontal visible).  
2. Conecta el **pin 1 (VCC)** del sensor al **5V** del Arduino.  
3. Conecta el **pin 2 (DATA)** al **pin digital 2** del Arduino UNO.  
4. Conecta el **pin 4 (GND)** del sensor a **GND (–)**.  
5. Coloca una **resistencia de 10 kΩ** entre el **pin 1 (VCC)** y el **pin 2 (DATA)** como *pull-up resistor*.

---

## ⚙️ Tabla de pines  

| Pin Arduino | Pin DHT11 | Descripción |
|--------------|------------|--------------|
| 2 | DATA | Comunicación digital |
| 5V | VCC | Alimentación del sensor |
| GND | GND | Tierra común |

---

## ✅ Verificación  
- Abre el **Monitor Serial** (9600 baudios).  
- Cada 5 segundos se mostrará la **temperatura** y la **humedad** medidas.  

---

## 🔎 Resultado esperado  
El **sensor DHT11** leerá los valores de **temperatura (°C y °F)** y **humedad (%)**, mostrándolos en el **Monitor Serial**, junto con el **índice de calor** calculado.
