# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #7 – Sensor de Temperatura Digital (DS18B20)**.

---

## 💡 Diagrama Físico  

<img width="721" height="487" alt="image" src="https://github.com/user-attachments/assets/1b356b36-0baa-4509-a76c-df76c96e1100" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🌡️ Conexión del Sensor DS18B20  
1. Coloca el sensor **DS18B20** en el protoboard (la parte plana debe mirar hacia ti).  
2. Conecta el **pin izquierdo (GND)** del sensor a la **línea azul (–)**.  
3. Conecta el **pin derecho (VDD)** a la **línea roja (+)**.  
4. Conecta el **pin central (DATA)** al **pin digital 2** del Arduino UNO.  
5. Coloca una **resistencia de 4.7 kΩ** entre el **pin de datos (centro)** y el **VDD (derecha)** del sensor (pull-up).  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Conexión DS18B20 | Descripción          |
|--------------|------------------|----------------------|
| 2            | DATA (centro)    | Comunicación 1-Wire  |
| 5V           | VDD (derecha)    | Alimentación         |
| GND          | GND (izquierda)  | Tierra               |

---

## ✅ Verificación  
- Conecta el Arduino al puerto USB.  
- Abre el **Monitor Serial** (9600 baudios).  
- Debes ver un mensaje con la **temperatura actual en grados Celsius (°C)** actualizándose constantemente.

---

## 🔎 Resultado esperado  
El **sensor DS18B20** medirá la temperatura ambiente y el **Arduino** la mostrará en la pantalla serial en °C, actualizándose cada segundo.
