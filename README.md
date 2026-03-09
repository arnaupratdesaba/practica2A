# Práctica 2A: Interrupciones por Hardware en ESP32

Este repositorio contiene la primera parte de la Práctica 2 sobre el uso y gestión de interrupciones de hardware utilizando un microcontrolador ESP32 bajo el entorno de Arduino.

## 📝 Descripción del Proyecto

El código implementa un contador de pulsaciones mediante el uso de una **Interrupción de Hardware**. En lugar de leer continuamente el estado de un botón (técnica de *Polling*), el ESP32 pausa su ejecución normal únicamente cuando detecta que el botón ha sido presionado, ejecuta una Rutina de Servicio de Interrupción (ISR) súper rápida, y vuelve a su tarea principal. 

Como característica adicional, el programa incluye un temporizador no bloqueante que **desactiva automáticamente el botón (separa la interrupción) después de 60 segundos** de ejecución.

## 🚀 Características Principales

* **Interrupciones (ISR):** Uso de `attachInterrupt()` para detectar flancos de bajada (`FALLING`).
* **Optimización de Memoria:** Uso del atributo `IRAM_ATTR` para alojar la función de interrupción en la memoria RAM, garantizando una ejecución inmediata.
* **Estructuras de datos:** Uso de `struct` para encapsular las propiedades y el estado del botón de forma limpia.
* **Temporización no bloqueante:** Uso de `millis()` para calcular el paso del tiempo sin detener el procesador (sin usar `delay()`).
* **Desvinculación:** Uso de `detachInterrupt()` para anular el comportamiento del botón dinámicamente.

## 🛠️ Hardware Requerido

* 1x Placa de desarrollo ESP32.
* 1x Pulsador (Botón).
* Cables de conexión (Jumpers).

### Esquema de conexión:
* Un pin del botón conectado al **GPIO 18** del ESP32.
* El otro pin del botón conectado a **GND**.
* *(No se requiere resistencia externa ya que el código activa la resistencia `INPUT_PULLUP` interna del ESP32).*

## 💻 Instalación y Uso

1.  Abre el código `practicaA_interrupciones.ino` en tu editor favorito (Arduino IDE, VS Code + PlatformIO).
2.  Asegúrate de tener instaladas las tarjetas de la familia **ESP32** en tu gestor de placas.
3.  Selecciona tu modelo de ESP32 y el puerto COM correspondiente.
4.  Sube el código a la placa.
5.  Abre el **Monitor Serie** y configúralo a una velocidad de **115200 baudios**.
6.  Pulsa el botón: verás cómo el contador aumenta por pantalla.
7.  Espera 1 minuto: verás el mensaje `"Interrupt Detached!"` y el botón dejará de funcionar.

## 📜 Licencia

Este proyecto es parte de una práctica académica. Eres libre de usarlo, modificarlo y distribuirlo con fines educativos.
```eof
