// Curso arduino profissional WRKITS
// Aula 3.5 - UART (Comunicação Serial)
// Exemplo UART - Envio de dados através do digital Write 


#define LED1             27
#define BT1               9                         //Botão utilizado para alternar o estado do led
#define debounce_time   450

bool BT1_STATUS = 0;
bool LEDSTATUS = 0;

void leitura_botao();

void setup()
{
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);                //Declarando o led como saída
  pinMode(BT1,  INPUT);                 //Declarando o botão como entrada
}

void loop()
{
  static long long ElapsedTime = 0;
  leitura_botao();
  digitalWrite(LED1, BT1_STATUS);
  if(ElapsedTime +250<millis())
  {
    ElapsedTime = millis();
    Serial.print("LED1 STATUS:");
    Serial.println(BT1_STATUS);
    Serial.write(2);                // Envia o binário de 2
    Serial.write(50);               // Para enviar o número 2 deve-se enviar o seu correspondente em ASCII (nesse caso 50 corresponde a 2)
  }


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
