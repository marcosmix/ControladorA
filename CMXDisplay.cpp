#include "Arduino.h"
#include "CMXDisplay.h"
#include <LiquidCrystal.h>

CMXDisplay::CMXDisplay(int pinD)
{
  _pinD=pinD;
}
int CMXDisplay::GetPin()
{
  return _pinD;
}
void CMXDisplay::Bienvenida(LiquidCrystal Pantalla)
{
	delay(500);

  for(int i=0;i<=4;i++)
  {
    
    Pantalla.clear();
    Pantalla.setCursor(0,i);
    Pantalla.print("Bievenido");
    delay(500);
    
  }

}

void CMXDisplay::PintarDatos(LiquidCrystal Pantalla,float Temperatura,bool motor[3],bool Alarma)
{
  Pantalla.clear();
  Pantalla.setCursor(1,1);
  Pantalla.print("Temperatura");
  Pantalla.setCursor(13,1);
  Pantalla.print(Temperatura);
  Pantalla.setCursor(18,1);
  Pantalla.print("c");
  Pantalla.setCursor(1,2);
  Pantalla.print("M1:");
  Pantalla.setCursor(5,2);
  if(motor[0]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  Pantalla.setCursor(11,2);
  Pantalla.print("M2:");
  Pantalla.setCursor(14,2);
  if(motor[1]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
   Pantalla.setCursor(1,3);
  Pantalla.print("M3:");
  Pantalla.setCursor(4,3);
  if(motor[2]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  
  if(Alarma)
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
