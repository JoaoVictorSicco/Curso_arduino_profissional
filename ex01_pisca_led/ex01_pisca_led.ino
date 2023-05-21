// Curso arduino profissional WRKITS
// Aula 3.1 - Saída digital
// Exemplo pisca led


#define LED1 27
bool LEDSTATUS = 0;

void setup() 
{
  pinMode(LED1,OUTPUT);
  

}

void loop() 
{
  
//  digitalWrite(LED1,LED1STATUS);
//  delay(500);
//  digitalWrite(LED1,HIGH);
//  delay(500);

  
  digitalWrite(LED1,LED1STATUS);
  delay(500);
  LED1STATUS = !LED1STATUS;
}
