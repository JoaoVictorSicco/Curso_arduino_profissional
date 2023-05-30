#ifndef __libdemo_h
  #define __libdemo_h
  #include<stdio.h>
  #include<string.h>
  #include<inttypes.h>
  #include "Arduino.h"

  class libdemo     // A classe recebe o mesmo nome da biblioteca. 
  {
    /*
      A classe possui a parte pública e privada. A primeira possui os métodos que são acessível ao usuário. As privadas são de uso somente da biblioteca
    */
    public:
      libdemo(uint8_t SCL_PIN,uint8_t SDA_PIN); //Método libdemo criado
      void retConfig(); //Printa na UART a configuração passada em libdemo.
      float temperature();

    private: // Essas variáveis são globais
      uint8_t SCL_PIN;
      uint8_t SDA_PIN;
    
    
  };

#endif
