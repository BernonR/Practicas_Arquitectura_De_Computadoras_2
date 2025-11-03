# 🔌 Guía de Conexiones

Sigue estos pasos para armar el circuito de la **Práctica #18 – Comunicación SPI entre Arduinos**.

---

## 💡 Diagrama Físico

<img width="697" height="451" alt="image" src="https://github.com/user-attachments/assets/0f6efff9-a6c8-400e-b2d4-12a996b7426f" />

---

## 🧰 Conexiones básicas

1. Conecta **GND** de ambos Arduinos entre sí (tierra común).
2. Conecta el **pin 5V del Maestro** al **5V del Esclavo** para compartir la alimentación.
3. Usa cables dupont para conectar las líneas SPI según la tabla siguiente:

---

## ⚙️ Tabla de Pines SPI

| Arduino Maestro | Arduino Esclavo | Descripción |
|------------------|-----------------|--------------|
| 10 | 10 | SS – Selección de esclavo |
| 11 | 11 | MOSI – Datos Maestro → Esclavo |
| 12 | 12 | MISO – Datos Esclavo → Maestro |
| 13 | 13 | SCK – Señal de reloj |
| GND | GND | Tierra común |

---

## ✅ Verificación
1. Carga el programa **Maestro** en una placa Arduino UNO.
2. Carga el programa **Esclavo** en la otra placa.
3. Abre el **Monitor Serial** en ambas placas.
4. Observa cómo ambos se comunican enviando y recibiendo caracteres en tiempo real.

---

## 🔎 Resultado Esperado
- El **maestro** enviará los caracteres “B” y “R” al esclavo.
- El **esclavo** responderá incrementando cada carácter en una unidad ASCII (“C” y “S” respectivamente).
- Ambos monitores mostrarán el intercambio continuo de datos.

---
