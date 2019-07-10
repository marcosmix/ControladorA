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
  
  int Esi,Eno,Emas,Emen;
  int EAsi;
  int EAno;
  int EAmas;
  int EAmen;
  
	PantallaConfiguracion(temperaturaIdeal);
  bool fin=true;
  float NuevaTI=temperaturaIdeal;
  
  do
  {
    delay(5);
      
   
    Esi=digitalRead(_si);
    if(Esi!=EAsi)
    {
      if(EstabilizarPulso(_si))
      {
        temperaturaIdeal=NuevaTI;
         fin=false;  
      }
    }
    
    Eno=digitalRead(_no);
    if(Eno!=EAno)
    {
      if(EstabilizarPulso(_no))
      {
        fin=false;  
      }
    }
    
    Emas=digitalRead(_mas);
    if(Emas!=EAmas)
    {
      if(EstabilizarPulso(_mas))
      {
        NuevaTI++;
      }
      PantallaConfiguracion(NuevaTI);
    }

     Emen=digitalRead(_men);
    if(Emen!=EAmen)
    {
      if(EstabilizarPulso(_men))
      {
        NuevaTI--;
      }
      PantallaConfiguracion(NuevaTI);
    }
    
  }while(fin);
}
