#include "CMXControlZonda.h"
#include "CMXDisplay.h"

#define COLS 20
#define ROWS 4
#define pinZ 12
#define pinD
LiquidCrystal Pantalla(12,11,5,4,3,2);
OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
CMXControlZonda zonda(pinZ);
CMXDisplay xdisplay(pinD);


bool configurar=true;
bool motores[3]={false,false,false};


void setup() 
{
  Serial.begin(9600);
  Pantalla.begin(COLS,ROWS);
  sensorTemp.begin();
}


bool Alarma()
{
  return false;
}


void loop() 
{
    xdisplay.Bienvenida(Pantalla,zonda.Consultar(sensorTemp),motores[3],Alarma());
    while(configurar)
    {
    xdisplay.PintarDatos(Pantalla);
    }
  
}



