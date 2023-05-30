#ifndef __keyboard_H    // Se não foi definido... definir abaixo
 #define __keyboard_H
 void LeBotoes();  //Leitura de botões ou pushbuttons
 int LePot();      // Leitura de potenciometro
 float ConvertVolt(int PCM, float VMAX);    //Conversao de valores de tensao
 unsigned char scanKeyboard();
#endif
