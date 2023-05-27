// Curso arduino profissional WRKITS
// Aula 4.4 - Teclado Matricial 
// Exemplo Teclado Matricial

#include<LiquidCrystal.h>


#define LED1             27
#define BT1               9                         //Botão utilizado para alternar o estado do led
#define debounce_time   450
#define POT              A0

//Variáveis display
#define RS                5
#define EN                6
#define DISP_D4           7
#define DISP_D5           8
#define DISP_D6           9
#define DISP_D7          10

unsigned short LINES[4] = {A5,A4,A3,A2};
unsigned short COLUMS[4] = {A1,2,3,4};

// Definição de pinos para o display
LiquidCrystal lcd(RS,EN,DISP_D4,DISP_D5,DISP_D6,DISP_D7);

unsigned char scanKeyboard();         // Função retorna unsigned char (um botão pressionado), realiza um scan do teclado e fazer a conversão do botão da matriz ao que é um botão pressionado


bool BT1_STATUS = 0;
bool LEDSTATUS = 0;

//void leitura_botao();
int leitura_potenciometro();            //Função que realiza a leitura de um potenciômetro e retorna um valor inteiro

void interrupcao0();                    // Função da interrupção

float converte_tensao(int valor_do_potenciometro, float tensao_maxima);

void interrupcao0()
{
  Serial.print("Interrupcao atuada");
}
void setup()
{
  Serial.begin(115200);
  lcd.begin(20,4);
  pinMode(LED1, OUTPUT);                //Declarando o led como saída
  pinMode(BT1,  INPUT);                 //Declarando o botão como entrada
  pinMode(POT,  INPUT);

  for (short i = 0; i<4;i++)
  {
    pinMode(LINES[i],OUTPUT);
    digitalWrite(LINES[i],HIGH);
    pinMode(COLUMS[i],INPUT);
    digitalWrite(COLUMS[i],HIGH);
  }

}

void loop()
{
  static long long ElapsedTime = 0;     // Variável para comparação do tempo millis
  int valor_potenciometro = 0;
  float tensao = 0;

  valor_potenciometro = leitura_potenciometro(); //Função de leitura
  tensao = converte_tensao(valor_potenciometro, 5); //Conversão para tensão
  //leitura_botao();

  if (ElapsedTime + 250 < millis())
  {
    ElapsedTime = millis();
    lcd.clear();
    lcd.setCursor(3,0);     //Coluna,linha
    lcd.print("DEMO LCD 20X4");
    lcd.setCursor(0,1);
    lcd.print("VOLTAGE: ");
    lcd.setCursor(10,1);
    lcd.print(((int)tensao)%10);
    lcd.print(".");
    lcd.print(((int)(tensao*10))%10);
    lcd.print("v");

    for(short i=0;i<((int)((float)tensao*4));i++)
    {
      lcd.setCursor(i,3);
      lcd.print("#");
    }
  }
  analogWrite(LED1,(valor_potenciometro/4));  // Valor do potenciometro vai até 1024, porém o analogwrite vai até 255, então divide o 1024 por 4 pra dar 255 
}

int leitura_potenciometro()
{
  int valor = 0;
  valor = analogRead(A0);
  return valor;
}

float converte_tensao(int valor_do_potenciometro, float tensao_maxima)
{
  float escala = (float)tensao_maxima / (float)1024;
  return valor_do_potenciometro * escala;

}
