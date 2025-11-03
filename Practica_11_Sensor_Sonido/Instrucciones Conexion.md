# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #11 – Sensor de Sonido**.

---

## 💡 Diagrama Físico  

<img width="889" height="589" alt="image" src="https://github.com/user-attachments/assets/fac32cc2-0d78-490a-8af4-4dc0f2f6dae8" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🎤 Conexión del Sensor de Sonido (KY-038 o LM393)  
1. **VCC** → Conecta al pin **5V** del Arduino.  
2. **GND** → Conecta al **GND (–)**.  
3. **AO (Salida Analógica)** → Conecta al pin **A0** del Arduino.  
4. **DO (Salida Digital)** → Conecta al pin **12** del Arduino.

---

## 💡 Conexión del LED Indicador  
1. Conecta el **ánodo (pata larga)** del LED al pin **2** del Arduino.  
2. Conecta una **resistencia de 330 Ω** desde el **cátodo (pata corta)** del LED a **GND (–)**.

---

## ⚙️ Tabla de pines  

| Pin Arduino | Conexión | Descripción |
|--------------|-----------|--------------|
| 12 | DO (digital) | Lectura de detección de sonido |
| A0 | AO (analógica) | Lectura de nivel de sonido |
| 2 | LED | Indicación visual |
| 5V | VCC | Alimentación del sensor |
| GND | GND | Tierra común |

---

## ✅ Verificación  
- Abre el **Monitor Serial** a 9600 baudios.  
- Aplaude o genera ruido cerca del micrófono.  
- Si se detecta sonido, se mostrará el mensaje **“SE DETECTÓ SONIDO”** y el LED se encenderá brevemente.

---

## 🔎 Resultado esperado  
El **LED** se encenderá al detectar un sonido por encima del umbral configurado, y en el **Monitor Serial** se mostrará la lectura analógica del sensor junto al mensaje de detección.
