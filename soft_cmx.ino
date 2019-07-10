#include "Modulos.h"


bool configurar=true;
bool motores[3]={false,false,false};
bool Alarma()
{
  return false;
}


void setup() 
{
  Serial.begin(9600);
  Pantalla.begin(COLS,ROWS);
  sensorTemp.begin();
}





void loop() 
{
    Bienvenida();
    while(configurar)
    {
    PintarDatos(Pantalla);
    }
  
}
