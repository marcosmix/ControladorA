#include "Modulos.h"
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Configuracion Disyplay 
//columnas y filas
#define COLS 20
#define ROWS 4


LiquidCrystal Pantalla(dRST,dE,dD1,dD2,dD3,dD4);
//fin configuracion Display

//configuracion Zonda
//Pin zonda 

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


void loop() 
{
  bool Epsi,EApsi=LOW;
    Bienvenida();
     Serial.println("estioy entrando al menu");
    while(!apagar)
    {      
     PintarDatos(TemperaturaAmbiente(sensorTemp),Alarma());
     Serial.println("preguntando por el si en menu principal");
     Epsi=EstabilizarPulso(_si);
     Serial.println(Epsi);
     if(EApsi==LOW&&Epsi==HIGH)
     {ConfigTemp();}      
     EApsi=Epsi;            
    } 
    Serial.println("termine ciclo");
}
