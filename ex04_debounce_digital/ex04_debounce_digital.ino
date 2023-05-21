// Curso arduino profissional WRKITS
// Aula 3.4 - Debounce digital
// Exemplo Debounce digital


#define LED1             27
#define BT1               9                         //Botão utilizado para alternar o estado do led
#define debounce_time   450

bool BT1_STATUS = 0;
bool LEDSTATUS = 0;

void leitura_botao();

void setup()
{
  pinMode(LED1, OUTPUT);                //Declarando o led como saída
  pinMode(BT1,  INPUT);                 //Declarando o botão como entrada
}

void loop()
{
  leitura_botao();
  digitalWrite(LED1, BT1_STATUS);

}


void leitura_botao()
{
  static bool BT1_FLAG = 0;             // Variável de sinalização pra saber quando o botão comutou
  static long long BT1_DEBOUNCE = 0;    // Variável para o uso do millis

  // Verifica se o botão foi pressionado e muda o status de BT1_FLAG para 1 dentro do if
  if (!digitalRead(BT1) && !BT1_FLAG)
  {
    BT1_FLAG = 1;
    BT1_DEBOUNCE = millis();            // Registra o tempo que isso aconteceu
  }

  // Verifica se o botão continua pressionado, se BT1_FLAG continua em HIGH e se o tempo de debounce já ocorreu
  if (!digitalRead() && BT1_FLAG && (BT1_DEBOUNCE + debounce_time < millis()))
  {
    BT1_DEBOUNCE = millis();
    bt1_status = 1;

  }

  if (digitalRead() && BT1_FLAG && (BT1_DEBOUNCE + debounce_time < millis()))
  {
    BT1_FLAG = 0;
    BT1_STATUS = 0;

  }



}
