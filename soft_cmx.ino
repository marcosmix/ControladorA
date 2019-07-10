#include "Modulos.h"
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Configuracion Disyplay 
//columnas y filas
#define COLS 20
#define ROWS 4
//pines 
#define dRST 12
#define dE 11
#define dD1 5
#define dD2  4
#define dD3 3
#define dD4 2
#define _mas 10
#define _men 8
#define _si 7
#define _no 6

LiquidCrystal Pantalla(dRST,dE,dD1,dD2,dD3,dD4);
//fin configuracion Display

//configuracion Zonda
//Pin zonda 
#define pinZ 9
OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
//configuracion Zonda


bool apagar=false;
bool motores[3]={false,false,false};
float temperaturaIdeal=22;



void setup() 
{
  Serial.begin(9600);
  Pantalla.begin(COLS,ROWS);
  sensorTemp.begin();
  pinMode(_mas, INPUT);
  pinMode(_men, INPUT);
  pinMode(_si, INPUT);
  pinMode(_no, INPUT);
}

int Esi,EAsi;
void loop() 
{
    Bienvenida();
    
    while(!apagar)
    {
      
      PintarDatos(TemperaturaAmbiente(sensorTemp),Alarma());
      Esi=digitalRead(_si); 
      if(Esi!=EAsi)
      {
       if(EstabilizarPulso(_si))
       {
        ConfigTemp();
       }
      
      }
     
    }
     
}
