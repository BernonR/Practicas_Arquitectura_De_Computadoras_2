# 🔌 Guía de Conexiones  
Sigue estos pasos para montar correctamente la **Práctica #14 – Theremin controlado por luz**.

---

## 💡 Diagrama Físico  

<img width="745" height="467" alt="image" src="https://github.com/user-attachments/assets/a5678367-35a0-44cf-a48a-2155d34284bc" />

<img width="851" height="392" alt="image" src="https://github.com/user-attachments/assets/327f98c3-9298-413c-acc6-19e4f09b47f0" />



---

## 🧰 Conexiones principales  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)** del protoboard.  

---

## 🔊 Conexión del Zumbador Piezoeléctrico  
1. Conecta el pin **positivo (+)** del zumbador al **pin digital 8** del Arduino.  
2. Conecta el pin **negativo (–)** del zumbador a **GND (–)**.  

---

## 🌞 Conexión de la Fotoresistencia (LDR)  
1. Coloca la **LDR** en el centro del protoboard.  
2. Conecta un extremo de la LDR a **5V (+)**.  
3. Conecta el otro extremo al **pin analógico A0** y también a **GND (–)** mediante una **resistencia de 10 kΩ**.  
   > Este montaje forma un divisor de tensión que permitirá medir la variación de luz.

---

## 💡 LED de calibración (integrado en la placa)  
- No se necesita conexión adicional, se utiliza el LED integrado del **pin 13** para indicar la **calibración del sensor**.  
- El LED se encenderá durante 5 segundos al iniciar, y luego se apagará indicando que el sensor ya está calibrado.

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente            | Descripción                   |
|--------------|----------------------|-------------------------------|
| A0           | Fotoresistencia (LDR) | Entrada analógica de luz      |
| 8            | Zumbador piezoeléctrico | Salida de audio               |
| 13           | LED integrado         | Indicador de calibración      |

---

## ✅ Verificación  
1. Sube el programa a la placa Arduino.  
2. Durante los primeros **5 segundos**, el LED estará encendido mientras se calibra el sensor.  
3. Luego, el LED se apaga y el **zumbador emitirá sonidos** que cambiarán de tono según la cantidad de luz.  
4. Acerca o aleja la mano sobre la LDR y escucha cómo varía el sonido.

---

## 🔎 Resultado esperado  
El zumbador reproducirá distintos tonos según la luz incidente.  
Al mover la mano sobre la LDR se obtienen sonidos similares a un **Theremin**, con frecuencias que oscilan entre **50 Hz y 4000 Hz**.
