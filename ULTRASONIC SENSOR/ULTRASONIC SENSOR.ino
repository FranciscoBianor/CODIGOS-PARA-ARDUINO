#include <Ultrasonic.h>
int cont =0;
int buz=12;
 Ultrasonic ultrassom(10 ,9); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(8) e o echo(7) respectivamente
Ultrasonic ultrassom1(5,4); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(5) e o echo(4) respectivamente
 
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
 void setup() {
 Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
 long distancia;
 pinMode(buz, OUTPUT);
 }
 
// Função que se repete infinitamente quando a placa é ligada
 void loop()
 {
  int distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
   int distancia1 = ultrassom1.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em                                  // centímetros(CM) ou polegadas(INC)
   Serial.print(distancia); //imprime o valor da variável distancia
   Serial.println("cm");
   Serial.print(distancia1); //imprime o valor da variável distancia
   Serial.println("cm");
   
   if((distancia<=180 && distancia>=13 )||(distancia1<=180&& distancia1>=13)){
    cont++;
   }
    Serial.println(cont);
   if (cont>2){ 
    Serial.println("Sai dai porra");
    digitalWrite(buz,HIGH);
    delay(1000);
    digitalWrite(buz,LOW);
    
    cont=0;
   }
   Serial.println(cont);
   delay(400);
 }
