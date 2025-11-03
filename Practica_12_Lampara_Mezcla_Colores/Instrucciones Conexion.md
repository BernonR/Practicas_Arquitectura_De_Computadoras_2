# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #12 – Lámpara de Mezcla de Colores (RGB + LDR)**.

---

## 💡 Diagrama Físico  

<img width="472" height="349" alt="image" src="https://github.com/user-attachments/assets/b041926e-501d-4918-ad30-54963c55c07b" />

<img width="507" height="206" alt="image" src="https://github.com/user-attachments/assets/f61a56f6-9c64-48c9-b0f5-3fd75d24dc0e" />


---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🌈 Conexión del LED RGB  
1. Utiliza un **LED RGB de cátodo común** (4 patas).  
2. Conecta el **pin común (más largo)** del LED a **GND (–)**.  
3. Conecta el **pin rojo** al pin digital **11** del Arduino.  
4. Conecta el **pin verde** al pin digital **9**.  
5. Conecta el **pin azul** al pin digital **10**.  
6. Coloca una **resistencia de 220 Ω** en serie con cada color.

---

## ☀️ Conexión de los sensores LDR  
1. Coloca **tres fotoresistencias (LDR)** en el centro del protoboard.  
2. Conecta un extremo de cada LDR a **5V**.  
3. Conecta el otro extremo de cada LDR a una **resistencia de 10 kΩ** que va a **GND (–)**.  
4. Conecta el punto intermedio (entre la LDR y la resistencia) a los pines analógicos:  
   - **A0 → Sensor Rojo**  
   - **A1 → Sensor Verde**  
   - **A2 → Sensor Azul**  

---

## 🎨 Filtros de color  
- Coloca papel celofán **rojo, verde y azul** sobre cada LDR.  
  - Rojo sobre A0  
  - Verde sobre A1  
  - Azul sobre A2  

Esto permite que cada sensor reaccione solo al color correspondiente de la luz.

---

## ⚙️ Tabla de pines  

| Pin Arduino | Conexión | Descripción |
|--------------|-----------|--------------|
| 11 | LED Rojo | Salida PWM |
| 9 | LED Verde | Salida PWM |
| 10 | LED Azul | Salida PWM |
| A0 | LDR Rojo | Entrada analógica |
| A1 | LDR Verde | Entrada analógica |
| A2 | LDR Azul | Entrada analógica |

---

## ✅ Verificación  
- Abre el **Monitor Serial (9600 baudios)**.  
- Cambia la luz ambiental o ilumina cada sensor individualmente con una linterna.  
- El LED RGB variará su color dependiendo de la intensidad de luz detectada por cada LDR.

---

## 🔎 Resultado esperado  
Cada canal de color (rojo, verde y azul) del LED se ajustará según la iluminación percibida por su correspondiente sensor LDR, creando una **mezcla de color suave y dinámica**.
