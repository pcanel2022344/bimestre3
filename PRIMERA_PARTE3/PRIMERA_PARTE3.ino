/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: pablo alexander canel aguilon
 * Fecha: 
 * Proyecto: contador
 */

#define btn_rising  2
#define btn_falling 3
#define a 4
#define b 5
#define c 6
#define d 7
#define a2 8
#define b2 9
#define c2 10
#define d2 11
void funcionA(void);
void funcionB(void);
int unidades = 0;
int decenas = 0;

void setup() {
Serial.begin(19200);
pinMode(btn_rising, INPUT);
pinMode(btn_falling, INPUT);
attachInterrupt(digitalPinToInterrupt(btn_rising),funcionA,RISING);//asendente
attachInterrupt(digitalPinToInterrupt(btn_falling),funcionB,FALLING);//desendente
pinMode(a,OUTPUT); 
pinMode(b,OUTPUT); 
pinMode(c,OUTPUT); 
pinMode(d,OUTPUT); 
pinMode(a2,OUTPUT); 
pinMode(b2,OUTPUT); 
pinMode(c2,OUTPUT); 
pinMode(d2,OUTPUT); 
}

void loop() {
 
  
 switch(unidades)//contador de unidades 
  {
 case 0:
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 break;
 case 1:
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 break;
 case 2:
 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 break;
 case 3:
 digitalWrite(a,HIGH);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 break;
 case 4:
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 break;
 case 5:
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 break;
 case 6:
 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 break;
 case 7:
 digitalWrite(a,HIGH);
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 break;
 case 8:
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 break;
 case 9:
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 break;
}
switch(decenas)//contador de unidades 
  {
 case 0:
 digitalWrite(a2,LOW);
 digitalWrite(b2,LOW);
 digitalWrite(c2,LOW);
 digitalWrite(d2,LOW);
 break;
 case 1:
 digitalWrite(a2,HIGH);
 digitalWrite(b2,LOW);
 digitalWrite(c2,LOW);
 digitalWrite(d2,LOW);
 break;
 case 2:
 digitalWrite(a2,LOW);
 digitalWrite(b2,HIGH);
 digitalWrite(c2,LOW);
 digitalWrite(d2,LOW);
 break;
 case 3:
 digitalWrite(a2,HIGH);
 digitalWrite(b2,HIGH);
 digitalWrite(c2,LOW);
 digitalWrite(d2,LOW);
 break;
 case 4:
 digitalWrite(a2,LOW);
 digitalWrite(b2,LOW);
 digitalWrite(c2,HIGH);
 digitalWrite(d2,LOW);
 break;
 case 5:
 digitalWrite(a2,HIGH);
 digitalWrite(b2,LOW);
 digitalWrite(c2,HIGH);
 digitalWrite(d2,LOW);
 break;

 case 6:
 digitalWrite(a2,HIGH);
 digitalWrite(b2,LOW);
 digitalWrite(c2,HIGH);
 digitalWrite(d2,LOW);
 break;

}
}

void funcionA(void){

unidades=unidades +1;
if (unidades==10)
{
  unidades =0;
  decenas=decenas+1;
}

  if(decenas>=5&&unidades>=0)
{
  decenas =0;
  unidades=0;
}


}


void funcionB(void){
 unidades=unidades-1;
 if (unidades<0)
 {
 unidades = 9;
 decenas = decenas -1;
}
  if(decenas<0&&unidades<=10)
{
  decenas =5;
  unidades=0;
}



}
