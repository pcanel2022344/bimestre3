/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: PABLO ALEXANDER CANEL AGUILON
 * Carnet: 2022344
 * Proyecto: Led PWM
*/
#define potenciometro_pwm A0     //PIN 14
#define pwmLed 3  


//Variables
unsigned int potenciometro = 0;
unsigned int iluminacionLed = 0;

void setup()
{
 Serial.begin(9600);  
 pinMode(potenciometro_pwm, INPUT); 
 pinMode(pwmLed, OUTPUT);  
}

void loop() {
  potenciometro = analogRead(potenciometro_pwm); //leo el canal analogico A0
  iluminacionLed = map(potenciometro, 0, 1023, 0, 255);
  analogWrite(pwmLed, iluminacionLed);
  delay(100);
  Serial.println(iluminacionLed);
}
