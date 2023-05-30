// Curso arduino profissional WRKITS
// Aula 4.4 - Teclado Matricial 
// Exemplo Teclado Matricial

//Inclusão de bibliotecas
#include <LiquidCrystal.h>
#include "keyboard.h"


//Definições de pinos
#define BT1 2
#define POT A0
#define DebounceTime 450
//Display
#define RS 5
#define EN 6
#define DISP_D4 7
#define DISP_D5 8
#define DISP_D6 9
#define DISP_D7 10

unsigned short LINES[4] = { A5, A4, A3, A2 };
unsigned short COLUMNS[4] ={ A1, 2, 3, 4 }; 

//Definição de pinos para o displau
LiquidCrystal lcd(RS, EN, DISP_D4, DISP_D5, DISP_D6, DISP_D7);


unsigned char scanKeyboard();

bool LED1STATUS = 0;
bool BT1STATUS = 0;

// Funções estão em keyboard.ino
extern void LeBotoes();
extern int LePot();
extern float ConvertVolt(int PCM, float VMAX);


void setup() {
  Serial.begin(115200);
  lcd.begin(20, 4);
  pinMode(BT1, INPUT);
  pinMode(POT, INPUT);

  for (short i = 0; i < 4; i++) {
    pinMode(LINES[i], OUTPUT);
    digitalWrite(LINES[i], HIGH);
    pinMode(COLUMNS[i], INPUT);
    digitalWrite(COLUMNS[i], HIGH);
  }
}

void loop() {
  static long long ElapsedTime = 0;
  int PotValue = 0;
  float Volt = 0;
  unsigned char Button = 0xff;
  static int Setpoint = 0;

  //Leitura do potenciometro
  PotValue = LePot();               //Funcao de leitura
  Volt = ConvertVolt(PotValue, 5);  //Conversao de engenharia

  if (ElapsedTime + 250 < millis()) {
    ElapsedTime = millis();
    lcd.clear();
    lcd.setCursor(3, 0);  //(coluna, linha)
    lcd.print("DEMO LCD 20X4");
    lcd.setCursor(0, 1);
    lcd.print("VOLTAGE: ");
    lcd.setCursor(10, 1);
    lcd.print(((int)Volt) % 10);
    lcd.print(".");
    lcd.print(((int)(Volt * 10)) % 10);
    lcd.print("v");

    for (short i = 0; i < ((int)((float)Volt * 4)); i++) {
      lcd.setCursor(i, 3);
      lcd.print("#");
    }
    lcd.setCursor(0, 2);

    //Rotina para atualizar tela - Setpoint teclado
    lcd.print("SETPOINT: ");
    lcd.print((Setpoint / 10) % 10);
    lcd.print(".");
    lcd.print((Setpoint) % 10);
  }

  //Rotina de scan do teclado
  Button = scanKeyboard();
  if (Button != 0xff) {
    //   Serial.println(Button);
    if (Button >= 48 && Button <= 57) {    
      Setpoint = Setpoint * 10 + (Button - 48);
      if (Setpoint > 99) {
        Setpoint = 0;
      }
    }
  }
}

/*void LeBotoes() {
  static bool BT1_FLAG = 0;
  static long long BT1_DEBOUNCE = 0;

  if (!digitalRead(BT1) && !BT1_FLAG) {
    BT1_FLAG = 1;
    BT1_DEBOUNCE = millis();
  }

  if (!digitalRead(BT1) && BT1_FLAG && (BT1_DEBOUNCE + DebounceTime < millis())) {
    BT1_DEBOUNCE = millis();
    BT1STATUS = 1;
  }

  if (digitalRead(BT1) && BT1_FLAG && (BT1_DEBOUNCE + DebounceTime < millis())) {
    BT1_FLAG = 0;
    BT1STATUS = 0;
  }
}
*/


 


  
