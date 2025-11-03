# 🔹 Práctica #1 – Secuencia de LEDs

## 🎯 Objetivo
Aprender el uso de las **salidas digitales en Arduino**, mediante el **encendido y apagado secuencial de LEDs**, controlando el tiempo de activación mediante la función `delay()`.

---

## 🧰 Listado de componentes
- 🔌 Cables de conexión  
- 🧠 Arduino UNO  
- 💡 10 LEDs  
- ⚙️ 1 resistencia de **330 Ω**

---

## 📝 Descripción
Esta práctica consiste en programar una **secuencia de encendido y apagado de LEDs** conectados a una placa Arduino UNO.  
El tiempo de encendido puede variar utilizando la función `delay()`, generando un patrón de iluminación repetitivo y controlado.

---

## ⚙️ Instrucciones principales

### 🔸 `pinMode()`
Se utiliza en la sección `setup()` para configurar el modo de trabajo de un pin, que puede ser:
- `INPUT` → Entrada de señal.  
- `OUTPUT` → Salida de señal.  

Los pines configurados como entrada se comportan eléctricamente como **alta impedancia**, mientras que los pines de salida permiten **enviar voltaje** a los componentes conectados (por ejemplo, LEDs).

---

### 🔸 `digitalWrite()`
Permite **escribir un valor lógico digital** en un pin configurado como salida:
- `digitalWrite(pin, HIGH)` → Envía 5V al pin (enciende LED).  
- `digitalWrite(pin, LOW)` → Envía 0V al pin (apaga LED).

---

### 🔸 `delay()`
Detiene temporalmente la ejecución del programa por el número de **milisegundos** especificado:
- `delay(200)` → Pausa de 200 ms antes de continuar con la siguiente instrucción.

---

📘 **Resultado esperado:**  
Los LEDs se encenderán y apagarán uno a uno en una secuencia repetitiva, demostrando el funcionamiento básico de las **salidas digitales** y el control de **tiempo en Arduino**.
