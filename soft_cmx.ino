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
LiquidCrystal Pantalla(dRST,dE,dD1,dD2,dD3,dD4);
//fin configuracion Display

//configuracion Zonda
//Pin zonda 
#define pinZ 9
OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
//configuracion Zonda


bool configurar=false;
bool motores[3]={false,false,false};
float temperaturaIdeal=22;



void setup() 
{
  Serial.begin(9600);
  Pantalla.begin(COLS,ROWS);
  sensorTemp.begin();
}





void loop() 
{
    Bienvenida();
    
    while(!configurar)
    {
          
     PintarDatos(TemperaturaAmbiente(sensorTemp),Alarma());
    }
    
  
}
