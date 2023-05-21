// Curso arduino profissional WRKITS
// Aula 3.2 - Evite delays
// Exemplo evite delays


#define LED1 27
bool LEDSTATUS = 0;

void setup()
{
  pinMode(LED1, OUTPUT);
}

void loop()
{
  // Função millis - Comparar quanto tempo se passou desde o último acionamento comparando com o tempo atual
  static long long tempo = 0;

  digitalWrite(LED1, LED1STATUS);
  if (tempo + 500 < millis())
  {
    LED1STATUS = !LEDSTATUS;
    tempo = millis();
  }
  LED1STATUS = !LED1STATUS;
}
