// Curso arduino profissional WRKITS
// Aula 3.3 - Entrada digital
// Exemplo entrada digital


#define LED1 27
#define BT1   9                         //Botão utilizado para alternar o estado do led
bool LEDSTATUS = 0;

void setup()
{
  pinMode(LED1, OUTPUT);                //Declarando o led como saída
  pinMode(BT1,  INPUT);                 //Declarando o botão como entrada
}

void loop()
{
//  bool bt_status = 0;                   // Declarando uma variável booleana para o ler o status do botão
//  bt_status = !digitalRead(BT1);         // A variável assume o valor do estado do botão através da leitura feita pelo digitalRead()
//  digitalWrite(LED1,bt_status);         // O status da variável é responsável por alternar o estado do led
//  

    // Maneira mais simples
    digitalWrite(LED1, !digitalRead(BT1));
  
}
