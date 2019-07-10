#ifndef Modulos
#define Modulos
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
#define dD2	4
#define dD3	3
#define dD4 2
LiquidCrystal Pantalla(dRST,dE,dD1,dD2,dD3,dD4);
//fin configuracion Display

//configuracion Zonda
//Pin zonda 
#define pinZ 9
OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
//configuracion Zonda

void Bienvenida();
//void PintarDatos(LiquidCrystal Pantalla,float Temperatura,bool motor[3],bool Alarma);

float Consultar(DallasTemperature sensorTemp);


#endif 
