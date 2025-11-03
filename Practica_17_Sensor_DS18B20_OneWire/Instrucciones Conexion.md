# 🔌 Guía de Conexiones  
Práctica #17 – Comunicación 1-Wire con el sensor de temperatura **DS18B20**

---

## 💡 Diagrama Físico  

<img width="703" height="344" alt="image" src="https://github.com/user-attachments/assets/006bfb8d-7431-403a-bffe-b3518bd8491e" />


<img width="392" height="374" alt="image" src="https://github.com/user-attachments/assets/860942b2-4233-4bc1-b8da-075b2b46220b" />

---

## 🧰 Conexiones básicas (modo normal con fuente externa)

| Pin del Sensor DS18B20 | Conexión Arduino UNO | Descripción |
|--------------------------|----------------------|--------------|
| VDD (rojo)              | 5V                   | Alimentación del sensor |
| GND (negro)             | GND                  | Tierra común |
| DQ (amarillo/blanco)    | Pin digital 2        | Línea de datos One-Wire |

> Conecta una **resistencia de 4.7 kΩ** entre **DQ y 5V** (pull-up) para mantener estable la comunicación.

---

## ⚙️ Conexión modo “Parásito” (sin usar VDD)
- Conecta solo **DQ (datos)** al **pin digital 2**, **GND** a tierra y la resistencia de **4.7 kΩ entre DQ y 5V**.  
- Este modo permite alimentar el sensor directamente a través del bus de datos.

> 🔸 Se recomienda el modo de **alimentación externa** (3 cables) por ser más estable.

---

## 🧩 Conexión múltiple (2 o más sensores)
- Todos los sensores comparten el mismo **bus de datos (pin 2)**.  
- Cada sensor necesita su **resistencia de 4.7 kΩ** si se conecta a pines distintos.  
- Cada sensor tiene una **dirección única de 64 bits (8 bytes)** que permite identificarlos individualmente en el bus.

---

## ✅ Verificación
1. Carga el código en Arduino.  
2. Abre el **Monitor Serial** a 9600 baudios.  
3. Observa los valores de temperatura en grados Celsius.  
4. Si conectas varios sensores, se mostrarán como *Temperatura 1*, *Temperatura 2*, *Temperatura 3*, etc.

---

## 🔎 Resultado Esperado
El **Arduino UNO** muestra en el monitor serial las temperaturas medidas por uno o más sensores **DS18B20**, conectados al mismo bus One-Wire.
