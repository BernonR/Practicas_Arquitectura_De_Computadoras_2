# 🔌 Guía de Conexiones  
Sigue estos pasos para armar el circuito de la **Práctica #6 – Contador de Pulsos**.

---

## 💡 Diagrama Físico  

<img width="570" height="451" alt="image" src="https://github.com/user-attachments/assets/c5fbfb01-dba2-4ffd-88bd-0c288b30b5e7" />


---

## 🧰 Conexiones básicas  
- Conecta el pin **5V** del Arduino a la **línea roja (+)** del protoboard.  
- Conecta el pin **GND** del Arduino a la **línea azul (–)**.  

---

## 💡 Conexión de LED y Switch  
1. Coloca un **LED** en el protoboard.  
2. Conecta la **pata larga (ánodo)** al **pin digital 11** del Arduino.  
3. Conecta la **pata corta (cátodo)** a **GND (–)** mediante una **resistencia de 330 Ω**.  
4. Coloca el **switch** en el protoboard.  
5. Conecta un lado del switch al **pin 13** del Arduino.  
6. Conecta el otro lado del switch a **5V**.  
7. Coloca una **resistencia de 5 kΩ** entre el pin 13 y **GND (–)** (pull-down).  

---

## ⚙️ Tabla de pines  

| Pin Arduino | Componente             |
|--------------|------------------------|
| 11           | LED (salida digital)   |
| 13           | Switch (entrada digital) |

---

## ✅ Verificación  
- Al presionar el switch, el **LED parpadeará brevemente**.  
- En el **Monitor Serial (9600 baudios)** se mostrará el conteo de pulsos registrados.  
- Si el LED no responde, revisa la resistencia del switch y las conexiones GND.  

---

## 🔎 Resultado esperado  
Cada vez que presiones el **switch**, el contador aumentará en una unidad y se mostrará en la **pantalla serial**.  
El LED indicará visualmente cada pulsación detectada.
