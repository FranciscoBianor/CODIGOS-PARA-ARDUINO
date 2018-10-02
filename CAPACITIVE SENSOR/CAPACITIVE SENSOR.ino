#include <CapacitiveSensor.h>

const int d1 = 13;
const int d11 = 12;
const int d2 = 11;
const int d22 = 10;
const int d3 = 7;
const int d33 = 6;
const int d4 = 5;
const int d44 = 4;
const int d5 = 3;
const int d55 = 2;
const int pal = 9;
const int pall = 8;

 
//varia de acordo com o resistor e tamanho da superfície capacitiva, mude para testar.
const long sensibilidade = 15000; 
 
CapacitiveSensor cs1 = CapacitiveSensor(d1,d11);
CapacitiveSensor cs2 = CapacitiveSensor(d2,d22);
CapacitiveSensor cs3 = CapacitiveSensor(d3,d33);
CapacitiveSensor cs4 = CapacitiveSensor(d4,d44);
CapacitiveSensor cs5 = CapacitiveSensor(d5,d55);
CapacitiveSensor csp = CapacitiveSensor(pal,pall);
 
 

 
void setup()
{
    cs1.set_CS_AutocaL_Millis( 0xFFFFFFFF);
    cs2.set_CS_AutocaL_Millis( 0xFFFFFFFF);
    cs3.set_CS_AutocaL_Millis( 0xFFFFFFFF);
    cs4.set_CS_AutocaL_Millis( 0xFFFFFFFF);
    cs5.set_CS_AutocaL_Millis( 0xFFFFFFFF);
    csp.set_CS_AutocaL_Millis( 0xFFFFFFFF);
 
    //Inicia a serial para ajudar no debug
    Serial.begin(9600);
}
 
void loop()
{
    //chama a função que lê a capacitância...
    long a = cs1.capacitiveSensor(30);
    long b = cs2.capacitiveSensor(30);
    long c = cs3.capacitiveSensor(30);
    long d = cs4.capacitiveSensor(30);
    long e = cs5.capacitiveSensor(30);
    long p = csp.capacitiveSensor(30);
 
    //Imprime o valor da capacitância na serial para ajudar no debug.
//    Serial.print("d1 = ");
//    Serial.println(a);
//    delay(100);
//    Serial.print("d2 = ");
//    Serial.println(b);
//    delay(100);
//    Serial.print("d3 = ");
//    Serial.println(c);
//    delay(100);
//    Serial.print("d4 = ");
//    Serial.println(d);
//    delay(100);
//    Serial.print("d5 = ");
//    Serial.println(e);
//    delay(100);
//    Serial.print("pal = ");
//    Serial.println(p);
//    delay(100);

   
    if((a<100)&&(b<150)&&(c<100)&&(d<100)&&(e<100)&&(p>180)){
      Serial.println("pedra");
    }
    else if((a>50)&&(b>50)&&(c>50)&&(d>50)&&(e>50)&&(p<600)){
      Serial.println("papel");
    }
    else {
      Serial.println("nada");
    }
    delay(100);
}
