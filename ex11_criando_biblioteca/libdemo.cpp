#include "libdemo.h"

libdem:: libdemo(uint8_t SCL_PIN,uint8_t SDA_PIN)
{
  _SCL_PIN = SCL_PIN;
  _SDA_PIN = SDA_PIN;
}
void libdemo:: retConfig() //Printa na UART a configuração passada em libdemo.
{
  Serial.begin(115200);
  Serial.print("SDA: ");
  Serial.println(_SDA_PIN);
  Serial.print("SCL: ");
  Serial.print(_SCL_PIN);
  Serial.println();
}
float libdemo:: temperature()
{
  return 12.3;
}
