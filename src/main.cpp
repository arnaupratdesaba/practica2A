#include <Arduino.h>

/*
 * PRÁCTICA 2 - PARTE A: Interrupción por hardware
 * Código extraído y reconstruido según el guion de la práctica.
 */

// Estructura para almacenar las propiedades y estado del botón
struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

// Instanciamos el botón 1. 
// (Asumimos el pin 18 por defecto, cámbialo si tu conexión física es distinta)
Button button1 = {18, 0, false};

/* * Rutina de Servicio de Interrupción (ISR)
 * Se almacena en la RAM (IRAM_ATTR) para que se ejecute más rápido.
 */
void IRAM_ATTR isr() {
  button1.numberKeyPresses += 1;
  button1.pressed = true;
}

void setup() {
  Serial.begin(115200);
  
  // Configuramos el pin del botón con la resistencia pull-up interna
  pinMode(button1.PIN, INPUT_PULLUP);
  
  // Adjuntamos la interrupción al pin del botón
  // FALLING: Se dispara cuando el estado pasa de HIGH a LOW (al pulsar)
  attachInterrupt(button1.PIN, isr, FALLING);
}

void loop() {
  // Comprobamos si la bandera "pressed" ha sido activada por la ISR
  if (button1.pressed) {
    Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);
    button1.pressed = false; // Reiniciamos la bandera
  }

  // Desvincular (Detach) la interrupción después de 1 Minuto (60000 ms)
  static uint32_t lastMillis = 0;
  
  if (millis() - lastMillis > 60000) {
    lastMillis = millis();
    detachInterrupt(button1.PIN);
    Serial.println("Interrupt Detached!");
  }
}
