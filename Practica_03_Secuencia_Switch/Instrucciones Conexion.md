# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #3 – Secuencia de LEDs con Switch**.

---

## 💡 Diagrama Físico  
<img width="651" height="676" alt="image" src="https://github.com/user-attachments/assets/7912b007-939e-4601-b1ee-2c478cdb49c5" />


---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

## 💡 Conexión de LEDs y Switch  
1. Coloca **10 LEDs** en el protoboard, uno por fila.  
2. Conecta la **pata larga (ánodo)** de cada LED a una **resistencia de 330 Ω**.  
3. El otro extremo de cada resistencia conéctalo a los **pines digitales 0 al 9** del Arduino UNO.  
4. Conecta la **pata corta (cátodo)** de todos los LEDs a la **línea GND (–)**.  
5. Coloca el **switch** en el protoboard.  
6. Conecta un lado del switch al pin **12** del Arduino.  
7. El otro lado del switch conéctalo a **5V**.  
8. Agrega una **resistencia de 5 kΩ** entre el pin **12** y **GND** para evitar lecturas flotantes (*pull-down resistor*).  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente |
|--------------|-------------|
| 0–9 | LEDs |
| 12 | Switch (entrada digital) |

---

## ✅ Verificación  
- Verifica que el **switch funcione**: cuando se presione, debe enviar un valor **HIGH** al pin 12.  
- Los **LEDs deben tener resistencias individuales de 330 Ω**.  
- Asegúrate de que no haya cortos entre la línea de 5V y GND.  

---

## 🔎 Resultado esperado  
Al presionar el **switch**, los **10 LEDs** se encenderán en secuencia de izquierda a derecha y luego en sentido inverso, demostrando el uso de **entradas y salidas digitales** junto con las estructuras **if** y **for**.
