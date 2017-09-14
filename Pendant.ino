#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>

PROGMEM prog_uchar byte1[256] = {119,127,17,16,86,119,119,119,119,86,87,16,86,16,119,16,119,16,16,16,16,16,16,16,16,16,19,16,16,0,0,0,3,16,16,127,67,0,0,64,255,70,68,111,71,71,110,103,239,111,71,239,70,78,111,206,76,4,255,0,0,103,4,78,255,207,78,207,206,200,4,255,238,0,79,0,76,239,206,239,12,6,6,6,119,38,111,38,39,2,0,0,55,247,7,119,255,6,127,2,7,143,4,3,206,0,0,0,207,0,0,16,0,0,0,0,0,0,236,160,0,32,236,254,255,254,255,255,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,17,19,255,255,255,255,247,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,16,255,249,251,144,217,129,217,253,0,88,255,176,16,249,249,112,40,48,255,104,57,40,40,8,168,0,232,236,32,255,111,104,107,232,32,237,43,8,0,233,40,0,169,168,0,1,8,136,169,8,136,136,171,0,168,0,136,0,0,0,175,11,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,136,128,128,0};
PROGMEM prog_uchar byte2[256] = {44,191,8,8,8,41,8,45,44,43,8,0,8,8,44,0,60,12,0,8,0,0,0,0,1,0,9,0,0,0,131,0,1,3,1,59,1,0,0,0,123,11,0,59,10,10,59,59,251,59,11,251,0,10,11,43,131,3,251,0,0,43,0,34,251,58,2,235,2,67,2,251,243,0,107,0,3,251,115,122,3,3,2,0,58,26,58,58,56,0,0,0,251,251,8,56,255,0,251,16,24,251,115,0,251,1,0,1,123,16,0,20,16,16,20,0,84,20,255,92,20,28,124,126,255,126,254,254,60,126,191,255,255,255,255,191,255,191,191,255,255,255,255,255,255,255,255,255,44,44,255,255,255,255,60,255,255,255,255,124,255,126,255,255,255,255,191,175,255,255,255,255,238,238,4,239,239,239,198,231,231,255,255,4,199,255,228,68,253,255,213,197,4,255,196,12,196,195,128,192,129,243,255,0,255,252,212,193,247,197,247,231,195,193,247,228,0,247,199,192,192,192,197,208,192,195,211,243,192,243,0,209,192,64,192,247,192,0,0,193,192,197,4,128,64,64,0,0,192,192,64,192,211,192,195,0};
PROGMEM prog_uchar byte3[256] = {6,15,2,0,2,6,2,6,6,2,0,0,0,0,6,0,6,0,0,2,0,0,2,0,0,2,2,0,0,0,0,0,0,6,4,6,2,2,0,2,14,0,0,0,2,2,14,2,14,14,2,14,0,0,6,8,10,2,14,0,0,14,0,0,12,12,2,14,8,8,8,12,14,0,14,0,8,14,14,12,10,0,0,2,14,0,12,10,0,0,2,0,9,15,0,3,15,0,11,0,0,10,10,0,8,0,2,2,8,2,0,3,2,2,1,2,7,7,15,15,3,1,7,7,15,7,15,15,7,15,5,13,15,15,15,9,15,9,15,13,15,15,15,15,15,15,15,15,1,3,13,15,15,15,1,15,13,15,15,7,13,7,15,15,15,13,13,13,15,15,15,13,15,15,1,13,15,15,13,15,15,15,15,1,13,15,15,7,15,15,15,5,5,15,13,5,15,11,9,9,8,15,15,1,15,15,15,1,15,15,15,13,9,8,13,15,0,15,15,11,3,8,15,13,8,13,15,15,10,15,0,13,8,8,12,15,8,0,0,8,8,11,0,8,0,0,0,0,8,8,10,8,13,8,12,0};

int pin1=0;//2
 int pin2=1;//3
 int pin3=2;//4
 int pin4=3;//5
 int pin5=4;//6
 
 uint16_t timer;
 
void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  wdt_enable(WDTO_2S);
}

void loop(){
  for(int iter=0 ;iter<255;iter++){
    wdt_reset();
  timer=millis();
  while(millis()-timer<250){
    
    if(pgm_read_byte_near(byte1 + iter) & (1 << 0)) 
      LED1();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 1))
      LED2();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 2))
      LED3();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 3))
      LED4();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 4))
      LED5();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 5))
      LED6();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 6))
      LED7();
    if(pgm_read_byte_near(byte1 + iter) & (1 << 7))
      LED8();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 0))
      LED9();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 1))
      LED10();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 2))
      LED11();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 3))
      LED12();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 4))
      LED13();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 5))
      LED14();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 6))
      LED15();
    if(pgm_read_byte_near(byte2 + iter) & (1 << 7))
      LED16();
    if(pgm_read_byte_near(byte3 + iter) & (1 << 0))
      LED17();
    if(pgm_read_byte_near(byte3 + iter) & (1 << 1))
      LED18();
    if(pgm_read_byte_near(byte3 + iter) & (1 << 2))
      LED19();
    if(pgm_read_byte_near(byte3 + iter) & (1 << 3))
      LED20();
    }
  }
  wdt_reset();
  delay(1000);
  wdt_reset();
  delay(1000);
  wdt_reset();
  delay(1000);
  wdt_reset();
  delay(3000);
  
}

void LED1(){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, HIGH); // LED 1
  digitalWrite(pin1, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
}
void LED2(){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, HIGH); // LED 2
  digitalWrite(pin2, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
}
void LED3(){ 
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, HIGH); // LED 3
  digitalWrite(pin2, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
}
void LED4(){
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin3, HIGH); // LED 4
  digitalWrite(pin3, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
}
void LED5(){
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin3, HIGH); // LED 5
  digitalWrite(pin3, LOW);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
}
void LED6(){
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin4, HIGH); // LED 5
  digitalWrite(pin4, LOW);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
}
void LED7(){
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin4, HIGH); // LED 7
  digitalWrite(pin4, LOW);
  pinMode(pin5, INPUT);
  pinMode(pin4, INPUT);
}
void LED8(){
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH); // LED 7
  digitalWrite(pin5, LOW);
  pinMode(pin5, INPUT);
  pinMode(pin4, INPUT);
}
void LED9(){
  pinMode(pin3, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, HIGH); // LED 9
  digitalWrite(pin1, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin3, INPUT);
}
void LED10(){
  pinMode(pin1, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin3, HIGH); // LED 10
  digitalWrite(pin3, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin3, INPUT);
}
void LED11(){
  pinMode(pin4, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, HIGH); // LED 11
  digitalWrite(pin2, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin4, INPUT);
}
void LED12(){
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin4, HIGH); // LED 12
  digitalWrite(pin4, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin4, INPUT);
}
void LED13(){
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin3, HIGH); //LED 13
  digitalWrite(pin3, LOW);
  pinMode(pin3, INPUT);
  pinMode(pin5, INPUT);
}
void LED14(){
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT); 
  digitalWrite(pin5, HIGH); // LED 14
  digitalWrite(pin5, LOW);
  pinMode(pin3, INPUT);
  pinMode(pin5, INPUT);
}
void LED15(){
  pinMode(pin1, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1, HIGH); // LED 15
  digitalWrite(pin1, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin4, INPUT);
}
void LED16(){
  pinMode(pin4, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin4, HIGH); // LED 16
  digitalWrite(pin4, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin4, INPUT);
}
void LED17(){
  pinMode(pin2, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin2, HIGH); // LED 17
  digitalWrite(pin2, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin5, INPUT);
}
void LED18(){
  pinMode(pin2, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin5, LOW);
  pinMode(pin2, INPUT);
  pinMode(pin5, INPUT);
}
void LED19(){
  pinMode(pin1, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin1, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin5, INPUT);
}
void LED20(){
  pinMode(pin1, OUTPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin5, LOW);
  pinMode(pin1, INPUT);
  pinMode(pin5, INPUT);
}
