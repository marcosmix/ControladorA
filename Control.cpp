#include "Modulos.h"
#include "Arduino.h"
#include <DallasTemperature.h>

extern float temperaturaIdeal;
extern DallasTemperature sensorTemp;

bool EstatusDeSistema()
{
  float ta=TemperaturaAmbiente(sensorTemp);
  float dif_TATI=ta-temperaturaIdeal;
  if(dif_TATI>=5||dif_TATI<=-5)
  return true;
  else
  return false;
}


bool Alarma()
{
  return EstatusDeSistema();
}
