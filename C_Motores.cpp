#include "Arduino.h"
#include "Modulos.h"
extern bool motores[Cant_motores];

void ConfigurarMotores(int p[Cant_motores])
{
  for(int i=0;i<Cant_motores;i++)
        {
          pinMode(p[i],OUTPUT);
        }
 }

void ControlMotores(int orden)
{
    for(int i=0;i<orden+1;i++)
        {
          motores[i]=true;
        }
}

void AccionarMotores(bool mot[Cant_motores],int _p[Cant_motores])
{
  for(int i=0;i<Cant_motores;i++)
  {
    digitalWrite(_p[i],mot[i]);  
  }  
}
