#ifndef Modulos_h
#define Modulos_h
#include <DallasTemperature.h>


void Bienvenida();
void PintarDatos(float TA,bool alarma);
float TemperaturaAmbiente(DallasTemperature sensor);
bool EstatusDeSistema();
bool Alarma();

#endif 
