#include "Modulos.h"
#include "Arduino.h"
#include <DallasTemperature.h>


extern float temperaturaIdeal;
extern DallasTemperature sensorTemp;
int tiempoAntirebote=10;

bool EstatusDeSistema()
{
  float ta;
  ta=TemperaturaAmbiente(sensorTemp);
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

int cuenta=0;
int estadoBoton;
int estadoBotonAnterior;

bool EstabilizarPulso(int pin)
{
  int contador=0;
  bool estado;
  bool estadoAnterior;

  do
  {
    estado=digitalRead(pin);
    if(estado!=estadoAnterior)
    {
      contador=0;
      estadoAnterior=estado;
    }else
    {
      contador=contador+1;
    }
    delay(1);
  }while(contador<tiempoAntirebote);
  
  return estado;
}

void ConfigTemp()
{
	PantallaConfiguracion(temperaturaIdeal);
  bool fin=false;
  while(fin)
  {
    if(digitalRead(_si)==HIGH||digitalRead(_no)==HIGH)
    {
      fin==true;
      return 0;
    }
  
    if(digitalRead(_mas)==HIGH)
    {
      temperaturaIdeal+1;
      PantallaConfiguracion(temperaturaIdeal);
    }
    
    if(digitalRead(_mas)==HIGH)
    {
      temperaturaIdeal-1;
      PantallaConfiguracion(temperaturaIdeal);
    }
    
  }
}
