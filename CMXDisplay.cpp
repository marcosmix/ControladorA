#include "Modulos.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

extern LiquidCrystal Pantalla;
extern bool motores[3];


void Bienvenida()
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

void PintarDatos(float TA,bool alarma)
{
  
  Pantalla.clear();
  Pantalla.setCursor(1,1);
  Pantalla.print("Temperatura");
  Pantalla.setCursor(13,1);
  Pantalla.print(TA);
  Pantalla.setCursor(18,1);
  Pantalla.print("c");
  Pantalla.setCursor(1,2);
  Pantalla.print("M1:");
  Pantalla.setCursor(5,2);
  if(motores[0]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  Pantalla.setCursor(11,2);
  Pantalla.print("M2:");
  Pantalla.setCursor(14,2);
  
  if(motores[1]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
   Pantalla.setCursor(1,3);
  Pantalla.print("M3:");
  Pantalla.setCursor(4,3);

  if(motores[2]){Pantalla.print("ok/on ");}else{Pantalla.print("ok/off");}
  
  if(!alarma)
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


void PantallaConfiguracion(float temp)
{
  Pantalla.clear();
  Pantalla.setCursor(0,1);
  Pantalla.print("Indique temperatura:");
  Pantalla.setCursor(0,1);
  Pantalla.print(temp);
    
}
