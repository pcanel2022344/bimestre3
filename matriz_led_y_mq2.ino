/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: PABLO ALEXANDER CANEL AGUILON
 * Carnet: 2022344
 * Proyecto: matriz led y sensor mq2
*/
#include <LedControl.h>

int adc, conver;

// Configuración de pines
const int dataPin = 2;
const int clockPin = 3;
const int csPin = 4;

// Crear instancia de la matriz LED
LedControl matriz = LedControl(dataPin, clockPin, csPin, 1);

// Definir el patrón de un gato
byte fuego1[8] = {
  B00000000,
  B00001000,
  B00011100,
  B00011100,
  B00111110,
  B01111110,
  B01111100,
  B00111000,
};
byte fuego2[8] = {
  B00000000,
  B00100000,
  B01110000,
  B01110000,
  B11111000,
  B11111100,
  B01111100,
  B00111000,
};

byte NIEVE1[8] = {
  B00100101,
  B10010000,
  B01111111,
  B11000010,
  B01000011,
  B11000010,
  B01000011,
  B01111110,
};
byte NIEVE2[8] = {
  B00000000,
  B00100101,
  B11111110,
  B01000011,
  B11000010,
  B01000011,
  B11000010,
  B01111111,
};

void setup() {
  Serial.begin(9600);
  matriz.shutdown(0, false);  // Encender la matriz LED
  matriz.setIntensity(0, 8);  // Ajustar la intensidad de brillo (0-15)
  matriz.clearDisplay(0);     // Limpiar la matriz LED
}

void loop() {
  adc = analogRead(A0);  // Salida del MQ
  conver = map(adc, 0, 1024, 0, 100);
  Serial.print("adc:");
  Serial.print(adc);
  Serial.print(" porcentaje:");
  Serial.print(conver);
  delay(100);

  if (conver < 10) {
    // Mostrar animaciones de nieve
    for (int fila = 0; fila < 8; fila++) {
      matriz.setRow(0, fila, NIEVE1[fila]);
    }
    delay(400);
    matriz.clearDisplay(0);
    delay(50);
    for (int fila = 0; fila < 8; fila++) {
      matriz.setRow(0, fila, NIEVE2[fila]);
    }
    delay(400);
    matriz.clearDisplay(0);
  } else {
    // Mostrar animaciones de fuego
    for (
int fila = 0; fila < 8; fila++) {
      matriz.setRow(0, fila, fuego1[fila]);
    }
    delay(400);
    matriz.clearDisplay(0);
    delay(50);
    for (int fila = 0; fila < 8; fila++) {
      matriz.setRow(0, fila, fuego2[fila]);
    }
    delay(400);
    matriz.clearDisplay(0);
  }
}
