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
  bool Esi,Emas,Emen,EAsi=false,EAmas=false,EAmen=false;
  //EAno=false,Eno,
  bool ESalir;
  bool EASalir=false;
  
	PantallaConfiguracion(temperaturaIdeal);
  bool fin=false;
  float NuevaTI=temperaturaIdeal;
  
  delay(500);
  do
  {
    Esi=EstabilizarPulso(_si);
    if(EAsi==LOW&&Esi==HIGH)
    {     
       temperaturaIdeal=NuevaTI;
       fin=true;  
       Guardar_ZS(0,NuevaTI);
    }
    EAsi=Esi;
    
    ESalir=EstabilizarPulso(_no);
    if(EASalir==LOW&&ESalir==HIGH)
    {
        fin=true;  
        
    }
    EASalir=ESalir;
    
    Emas=EstabilizarPulso(_mas);
    if(EAmas==LOW&&Emas==HIGH)
    {
      NuevaTI++;
    }
    EAmas=Emas;
   
    Emen=EstabilizarPulso(_men);
    if(EAmen==LOW&&Emen==HIGH)
    {
       NuevaTI--;
    }
    EAmen=Emen;
    
    PantallaConfiguracion(NuevaTI);
  }while(!fin);
 }

 void  ConfiguracionIncial(byte resetear)
 {
    Guardar_ZS(0,25);
    Guardar_ZS(4,123);
    resetear=Leer_ZS(4);
   
 }

 void ControlarTemperatura(float temp[T],float TA)
 {
      for(int i=0;i<T;i++)
      {
        if(TA>temp[i])
        {
         ControlMotores(i); 
        }
      }
      
 }
