#ifndef CMXDisplay_h
#define CMXDisplay_h
#include "Arduino.h"
#include <LiquidCrystal.h>

class CMXDisplay
{
public:
	CMXDisplay(int pinD);
	void Bienvenida(LiquidCrystal Pantalla);
  void PintarDatos(LiquidCrystal Pantalla,float Temperatura,bool motor[3],bool Alarma);
  int GetPin();
private:
  int _pinD;


};

#endif
