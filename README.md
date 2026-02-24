# 🚐 Control inalámbrico de luces para casilla rodante con ESP32 + ESP-NOW

Hola a todos 🙂

Quiero compartirles un proyecto que desarrollé para resolver un problema bastante común en casillas rodantes o carros: **el cable que une el vehículo con el tráiler para manejar las luces** (posición, giro, freno, etc.).

Con el uso, ese cable se corta, se sulfata, se desconecta… o simplemente molesta.  
La idea de este proyecto fue simple:

> 💡 Reemplazar completamente el cable físico por un sistema inalámbrico confiable.

Y todo usando **ESP32** y el protocolo **ESP-NOW**.

---

# 🧠 ¿Cómo funciona el sistema?

El proyecto se divide en dos partes:

## 1️⃣ Módulo Transmisor (TX) – Va en el vehículo

Este módulo:
- Toma las señales de las luces del auto (giro izquierdo, giro derecho, freno, posición, etc.).
- Las detecta mediante entradas protegidas.
- Las envía de forma inalámbrica al módulo receptor.

## 2️⃣ Módulo Receptor (RX) – Va en la casilla rodante

Este módulo:
- Recibe los datos inalámbricos.
- Activa relés.
- Los relés manejan las luces del carro.

De esta manera:

Vehículo → (Wireless) → Casilla  
Sin cables entre ambos.

---

# 📡 ¿Qué es ESP-NOW? (Explicado simple)

ESP-NOW es un protocolo de comunicación inalámbrica creado por Espressif (los fabricantes del ESP32).

Lo interesante es que:

- No necesita WiFi.
- No necesita router.
- No necesita internet.
- Es muy rápido.
- Es muy estable.
- Consume muy poca energía.

Es como si los ESP32 hablaran entre ellos directamente, por radio, en forma privada.

A diferencia del WiFi tradicional:
- No hay red.
- No hay contraseña.
- No hay configuración complicada.

Solo se emparejan por la dirección MAC y listo.

Para este tipo de proyecto (donde solo necesitamos enviar estados ON/OFF) es perfecto.

---

# 💻 hablemos del SKETCH...

La lógica del sketch es bastante simple:

## En el Transmisor:
1. Lee el estado de cada entrada.
2. Guarda esos estados en una estructura.
3. Envía esa estructura mediante ESP-NOW.

## En el Receptor:
1. Recibe la estructura.
2. Actualiza las salidas según los datos recibidos.
3. Activa o desactiva relés.

Es un sistema directo:

Entrada → Envío → Recepción → Salida

No hay delays complejos.  
No hay librerías raras.  
Solo la librería ESP-NOW incluida en el ESP32.

---

# 🛠 ¿Puede hacerlo alguien sin experiencia?

Sí!!! ... La idea del proyecto es que cualquiera pueda:

1. Entender cómo funciona el circuito.
2. Copiar el sketch en el IDE Arduino.
3. Cargarlo en dos ESP32.
4. Armar la placa o hacerlo en protoboard.
5. Tener su sistema inalámbrico funcionando.

No hace falta ser experto en RF.  
No hace falta saber redes.  
No hace falta saber WiFi avanzado.

Si podés:
- Subir un sketch a un ESP32
- Conectar un relé
- Identificar una señal de 12V

Podés hacerlo.

---

# 🚀 Ventajas del sistema

✅ Elimina el cable entre vehículo y casilla  
✅ Reduce falsos contactos  
✅ Fácil de mantener  
✅ Bajo costo  
✅ Escalable (podés agregar más funciones)  
✅ Muy bajo consumo  

---

# 🎯 Conclusión

Este proyecto demuestra que con un par de ESP8266/ESP32 y ESP-NOW se puede resolver un problema real de forma simple, económica y elegante.

La electrónica es sencilla.  
El código es claro.  
El sistema es robusto.

Y lo mejor:

Podés hacerlo vos mismo.
