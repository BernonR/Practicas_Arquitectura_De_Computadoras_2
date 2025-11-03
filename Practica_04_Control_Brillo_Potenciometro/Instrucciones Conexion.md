# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #4 – Control de brillo de LED con potenciómetro**.

---

## 💡 Diagrama Físico  

<img width="681" height="547" alt="image" src="https://github.com/user-attachments/assets/299c1850-196e-4425-9293-54250aab309b" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

## 💡 Conexión del LED y potenciómetro  
1. Coloca un **LED** en el protoboard.  
2. Conecta la **pata larga (ánodo)** del LED al **pin digital 1** del Arduino.  
3. Conecta la **pata corta (cátodo)** del LED a **GND (–)** mediante una **resistencia de 330 Ω**.  
4. Coloca el **potenciómetro de 10 kΩ** en el protoboard.  
5. Conecta un extremo del potenciómetro a **5V**, el otro a **GND**, y la salida central al **pin analógico A0** del Arduino UNO.  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente         |
|--------------|-------------------|
| A0           | Potenciómetro (entrada analógica) |
| 1            | LED (salida digital) |

---

## ✅ Verificación  
- Gira el potenciómetro y observa cómo cambia la intensidad del LED.  
- Si el LED no responde, revisa que el pin central del potenciómetro esté conectado a **A0** y que el LED tenga su resistencia de **330 Ω** correctamente.  

---

## 🔎 Resultado esperado  
El **LED variará su brillo** en función de la posición del potenciómetro, demostrando el uso de **entradas analógicas (A0–A5)** y la lectura de valores con `analogRead()`.
