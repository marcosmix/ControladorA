#include <LiquidCrystal.h>
#include "CMXControlZonda.h"
//#include "CMXDisplay.h"

#define COLS 20
#define ROWS 4
#define pinZ 9
LiquidCrystal Pantalla(12,11,5,4,3,2);
OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
CMXControlZonda zonda(pinZ);
//CMXDisplay.h xdisplay();

const float valorbajo=14;
const float valormedio=25;
const float valoralto=35;
bool configurar=true;
bool motor1=false;
bool motor2=false;
bool motor3=false;

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

void PintarDatos()
{
 
  Pantalla.clear();
  Pantalla.setCursor(1,1);
  Pantalla.print("Temperatura");
  Pantalla.setCursor(13,1);
  Pantalla.print(zonda.Consultar(sensorTemp));
  Pantalla.setCursor(18,1);
  Pantalla.print("c");
  Pantalla.setCursor(1,2);
  Pantalla.print("M1:");
  Pantalla.setCursor(5,2);
  if(motor1){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  Pantalla.setCursor(11,2);
  Pantalla.print("M2:");
  Pantalla.setCursor(14,2);
  if(motor2){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
   Pantalla.setCursor(1,3);
  Pantalla.print("M3:");
  Pantalla.setCursor(4,3);
  if(motor2){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  
  if(!Alarma())
  {
     Pantalla.setCursor(0,0);
     Pantalla.print("Sistema funciondo ok");
  }else
  {
    Pantalla.setCursor(0,0);
     Pantalla.print("Error en sistema!!!");
  }

  
  delay(5000);
  
  
  
}


void loop() 
{
    //xdisplay.bienvenida(Pantalla);
    while(configurar)
    {
        PintarDatos();
    }
  
}



