
#include "Modulos.h"
#include "Arduino.h"

#define IN 21
#define FIN 999

int IND=21; 

bool Guardar_ZS(int indice,byte Dato)
{
  if(indice>=0&&indice<=20)
  {
    EEPROM.write(indice,Dato);
    Serial.println("escribi los datos todo bien GUARDAR ZS");
    return true;
    
  }else
  {
    Serial.println("escribi los datos todo bien GUARDAR ZS");
    return false;
     
   }
  
}

int Leer_ZS(int i)
{
  if(i>=0&&i<=20)
  {
    int dato=EEPROM.read(i);
    Serial.println("e leido este dato");
    Serial.println(dato);
     Serial.print(" en ");
     Serial.print(i);
    return dato;
  }
  
  else{return 9999;}
  
}

bool Guardar(byte dato)
{
   if(IND<=FIN)
   {
      EEPROM.write(IND,dato);
      IND++;
      return true;
    }else{
      return false;}
}

/*
0 temperatura ideal
1 temperatura 2
2 temperatura 3
3 temperatura 4
4 Reset       


20 en adelante registros 
dia hora codigo 

*/
