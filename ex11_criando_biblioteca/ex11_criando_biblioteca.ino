// Curso arduino profissional WRKITS
// Aula 5.2 - Criando bibliotecas
// Exemplo Criação de bibliotecas

libdemo demo(10,13);  //SCL e SDA 

#include "libdemo.h"

void setup()
{
  Serial.begin(115200);
  demo.retConfig;
  
}

void loop()
{
  delay(500);
  Serial.println(demo.temperature);  
  
}
 


  
