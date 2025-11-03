# 🔌 Guía de Conexiones  
Práctica #16 – Control remoto infrarrojo con Arduino y librería **IRremote**  

---

## 💡 Diagrama Físico  

<img width="626" height="370" alt="image" src="https://github.com/user-attachments/assets/f9283735-3e42-4351-9dd0-fcdd26d43547" />

<img width="536" height="504" alt="image" src="https://github.com/user-attachments/assets/6a4053d6-8bcb-461c-b9ed-e15e23733042" />


---

## 🧰 Conexiones del módulo receptor IR  
El sensor infrarrojo tiene tres pines:
| Pin | Descripción | Conexión Arduino |
|------|--------------|------------------|
| S (Señal) | Salida digital de datos IR | **Pin 11** |
| VCC | Alimentación | **5V** |
| GND | Tierra | **GND** |

> El pin de datos (S) envía las señales decodificadas al Arduino, mientras que los otros dos proporcionan alimentación.

---

## 🔴 Conexión de LEDs (controlados desde el control remoto)

| Pin Arduino | Componente | Descripción |
|--------------|-------------|--------------|
| 4 | LED 1 | Controlado por tecla “4” |
| 5 | LED 2 | Controlado por tecla “5” |
| 6 | LED 3 | Controlado por tecla “6” |
| 7 | LED 4 | Controlado por tecla “7” |

Cada LED debe conectarse a su pin digital a través de una **resistencia de 220 Ω** hacia **GND**.

---

## ⚙️ Materiales
- 1 Placa Arduino UNO  
- 1 Módulo receptor infrarrojo (KY-022 o equivalente)  
- 4 LEDs  
- 4 resistencias de 220 Ω  
- 1 Control remoto IR (cualquier marca)  
- Cables de conexión  
- Protoboard  

---

## ✅ Verificación
1. Carga el programa al Arduino.  
2. Abre el **Monitor Serial** a 9600 baudios.  
3. Presiona teclas del control remoto y observa el código hexadecimal recibido.  
4. Luego, prueba los botones **4–7**, los cuales encenderán y apagarán los LEDs correspondientes.  

---

## 🔎 Resultado Esperado
- El **Monitor Serial** mostrará los valores en **HEX** y el nombre de la tecla presionada.  
- Al presionar las teclas **4, 5, 6 o 7**, los LEDs se encenderán o apagarán.  
- Cada tecla del control remoto podrá ser programada para accionar distintos pines digitales.
