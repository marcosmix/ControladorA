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

bool LeerPulsoEnBajo(int pin,bool EstA)
{
  if(digitalRead(pin)==LOW)
  return true;
  
  if(digitalRead(pin)==HIGH&&EstA)
  return false;
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
  Serial.println("Entre a configara temperatura");
  do
  {
    Serial.println("Pregunto por el si");
    Serial.println(_si);
    Esi=EstabilizarPulso(_si);
    Serial.println(Esi);
    Serial.println(EAsi);
    Serial.println("al pulsar si");
    Serial.println(ESalir);
    Serial.println(EASalir);
    if(EAsi==LOW&&Esi==HIGH)
    {     
       temperaturaIdeal=NuevaTI;
       fin=true;  
       Serial.println("Me fui por el si");
    }
    EAsi=Esi;
    
    Serial.println("Pregunto por el no");
    Serial.println(_no);
    ESalir=EstabilizarPulso(_no);
    Serial.println(ESalir);
    Serial.println(EASalir);
    if(EASalir==LOW&&ESalir==HIGH)
    {
        fin=true;  
        Serial.println("Me fui por el no");
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
    Serial.println("pinto en pantalla y vuelo al ciclo");
    PantallaConfiguracion(NuevaTI);
  }while(!fin);
   Serial.println("salgo a configara temperatura");
}
