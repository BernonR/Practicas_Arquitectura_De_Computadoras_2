# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #13 – Indicador del Estado de Ánimo (Servo + Potenciómetro)**.

---

## 💡 Diagrama Físico  

<img width="714" height="501" alt="image" src="https://github.com/user-attachments/assets/5e643ae8-91ac-44fd-81b1-b7e385f2fd84" />

<img width="700" height="303" alt="image" src="https://github.com/user-attachments/assets/7d8a937f-8999-49c1-abdc-7a8b732d8989" />

---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 🎛️ Conexión del Potenciómetro  
1. Coloca el **potenciómetro de 10 kΩ** en el protoboard.  
2. Conecta un extremo a **5V** y el otro a **GND**.  
3. Conecta el **pin central** al **A0** del Arduino.  
4. (Opcional) Coloca un **condensador de 100 µF** entre 5V y GND cerca del potenciómetro para estabilizar la lectura.

---

## ⚙️ Conexión del Servomotor  
1. Conecta el **cable rojo (VCC)** del servo a **5V**.  
2. Conecta el **cable negro o marrón (GND)** a **GND (–)**.  
3. Conecta el **cable blanco o amarillo (señal)** al **pin digital 9** del Arduino.  
4. Coloca un **condensador de 100 µF** entre 5V y GND cerca del servo para evitar caídas de tensión.

---

## 🧩 Componentes utilizados

| Componente | Descripción | Cantidad |
|-------------|--------------|-----------|
| Arduino UNO | Placa de desarrollo | 1 |
| Servomotor SG90 o similar | Motor de rotación controlada | 1 |
| Potenciómetro 10 kΩ | Entrada analógica para control | 1 |
| Condensadores 100 µF | Filtro de alimentación | 2 |
| Protoboard + cables | Conexión del circuito | - |

---

## ✅ Verificación  
- Sube el programa y abre el **Monitor Serial (9600 baudios)**.  
- Al girar el potenciómetro, el servo se moverá proporcionalmente (0°–180°).  
- En el monitor serial se mostrarán los valores del potenciómetro y el ángulo actual.

---

## 🔎 Resultado esperado  
El servomotor rotará suavemente de 0° a 180° según la posición del potenciómetro.  
Al conectar una **flecha de cartón al brazo del servo**, podrás crear un **indicador mecánico de estado de ánimo**, con etiquetas como:
- 😡 “No entrar”  
- 🙂 “Por favor llamar”  
- 😁 “Puede pasar”
