#include "keyboard.h"

int LePot() {
  int value = 0;
  value = analogRead(POT);
  return value;
}

float ConvertVolt(int PCM, float VMAX) {
  float escala = (float)VMAX / (float)1024;
  return PCM * escala;
}

unsigned char scanKeyboard() {
  short BTn = 0;
  unsigned char BTp = 0xff;
  static unsigned char oldBTp = 0xff;

  for (short i = 0; i < 4; i++) {  //Scan de linha
    digitalWrite(LINES[i], LOW);
    for (short z = 0; z < 4; z++) {  //Scan de coluna
      if (digitalRead(COLUMNS[z]) == LOW) {
        BTn = (i)*4 + (z + 1);
      }
    }
    delayMicroseconds(100);
    digitalWrite(LINES[i], HIGH);
  }

  switch (BTn) {
    case 1:
      BTp = '1';
      break;
    case 2:
      BTp = '2';
      break;
    case 3:
      BTp = '3';
      break;
    case 4:
      BTp = 'A';
      break;
    case 5:
      BTp = '4';
      break;
    case 6:
      BTp = '5';
      break;
    case 7:
      BTp = '6';
      break;
    case 8:
      BTp = 'B';
      break;
    case 9:
      BTp = '7';
      break;
    case 10:
      BTp = '8';
      break;
    case 11:
      BTp = '9';
      break;
    case 12:
      BTp = 'C';
      break;
    case 13:
      BTp = '*';
      break;
    case 14:
      BTp = '0';
      break;
    case 15:
      BTp = '#';
      break;
    case 16:
      BTp = 'D';
      break;
  }


  if (BTp != oldBTp) {
    oldBTp = BTp;
    return BTp;
  }else{
    return 0xff;
  }
}

void LeBotoes() {
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
