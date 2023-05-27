// Curso arduino profissional WRKITS
// Aula 3.8 - PWM (Saída "Analógica")
// Exemplo PWM


#define LED1             27
#define BT1               9                         //Botão utilizado para alternar o estado do led
#define debounce_time   450
#define POT              A0

//bool BT1_STATUS = 0;
//bool LEDSTATUS = 0;

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
  pinMode(LED1, OUTPUT);                //Declarando o led como saída
  pinMode(BT1,  INPUT);                 //Declarando o botão como entrada
  pinMode(POT,  INPUT);

  attachInterrupt(digitalPinToInterrupt(BT1), Interrupcao0, FALLING);
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
    Serial.print("Status do potenciometro: ");
    Serial.print(tensao);
    Serial.println();
  }
  analogWrite(LED1,(valor_potenciometro/4));  // Valor do potenciometro vai até 1024, porém o analogwrite vai até 255, então divide o 1024 por 4 pra dar 255 
}


//void leitura_botao()
//{
//  static bool BT1_FLAG = 0;             // Variável de sinalização pra saber quando o botão comutou
//  static long long BT1_DEBOUNCE = 0;    // Variável para o uso do millis
//
//  // Verifica se o botão foi pressionado e muda o status de BT1_FLAG para 1 dentro do if
//  if (!digitalRead(BT1) && !BT1_FLAG)
//  {
//    BT1_FLAG = 1;
//    BT1_DEBOUNCE = millis();            // Registra o tempo que isso aconteceu
//  }
//
//  // Verifica se o botão continua pressionado, se BT1_FLAG continua em HIGH e se o tempo de debounce já ocorreu
//  if (!digitalRead() && BT1_FLAG && (BT1_DEBOUNCE + debounce_time < millis()))
//  {
//    BT1_DEBOUNCE = millis();
//    bt1_status = 1;
//
//  }
//
//  if (digitalRead() && BT1_FLAG && (BT1_DEBOUNCE + debounce_time < millis()))
//  {
//    BT1_FLAG = 0;
//    BT1_STATUS = 0;
//
//  }
//}

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
