# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #5 – PWM: Control de brillo de LED con potenciómetro**.

---

## 💡 Diagrama Físico  
<img width="740" height="376" alt="image" src="https://github.com/user-attachments/assets/251a86a9-4989-43c2-b39b-4c29f7934cbb" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 💡 Conexión del LED y potenciómetro  
1. Coloca el **LED** en el protoboard.  
2. Conecta la **pata larga (ánodo)** del LED al **pin digital 9 (PWM)** del Arduino.  
3. Conecta la **pata corta (cátodo)** del LED a **GND (–)** mediante una **resistencia de 330 Ω**.  
4. Coloca el **potenciómetro de 5 kΩ** en el protoboard.  
5. Conecta un extremo del potenciómetro a **5V**, el otro a **GND**, y el pin central al **A0** del Arduino.  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente                    |
|--------------|--------------------------------|
| 9            | LED (salida PWM)              |
| A0           | Potenciómetro (entrada analógica) |

---

## ✅ Verificación  
- El LED debe **variar su brillo suavemente** al girar el potenciómetro.  
- Si el LED no enciende, revisa que esté conectado a un **pin PWM (9)** y que la **resistencia esté correctamente colocada**.  
- Abre el **Monitor Serial (9600 baudios)** para visualizar el valor analógico leído en tiempo real.  

---

## 🔎 Resultado esperado  
Al girar el potenciómetro, el **LED cambiará gradualmente su intensidad** gracias al uso del **PWM (Modulación por Ancho de Pulso)**, permitiendo un control analógico de brillo con señales digitales.
