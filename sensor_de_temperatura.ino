/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: msensor de temperatura  
   Dev: Pablo alexander canel aguilon
   Fecha: 6 de Julio
*/
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define boton 2
#define sensor 4

void isr_led(void);
void isr_sensor(void);

volatile static bool estado_led;
volatile static bool estado_sensor;

Ticker isr_accion_led(isr_led, 300);
Ticker isr_accion_sensor(isr_sensor, 300);
OneWire ourWire(2);
DallasTemperature sensors(&ourWire);

void setup(){
 Serial.begin(9600);
 pinMode(boton,OUTPUT);
 digitalWrite(boton, LOW);
 isr_accion_led.start();
 isr_accion_sensor.start();
}

void loop()
{
isr_accion_led.update();
isr_accion_sensor.update();
}

void isr_led(void)
{
 sensors.requestTemperatures();
 float tempC= sensors.getTempCByIndex(0);
 float tempF= sensors.getTempFByIndex(0);
 estado_led = digitalRead(boton);
 digitalWrite(boton, !estado_led);
 Serial.println(tempC);
}

void isr_sensor(void)
{
 pinMode(sensor,INPUT);
// estado_sensor= digitalRead(abierto);
 if(estado_sensor == LOW); 
 {
  Serial.println("encendido");
 }
if(estado_sensor == HIGH);
{
  Serial.println("cerado");
 }
}
