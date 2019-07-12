#ifndef Modulos_h
#define Modulos_h
#include <DallasTemperature.h>
#define _mas 10
#define _men 8
#define _si 7
#define _no 6

void Bienvenida();
void PintarDatos(float TA,bool alarma);
void PantallaConfiguracion(float temp);

float TemperaturaAmbiente(DallasTemperature sensor);

bool EstatusDeSistema();
bool Alarma();
void ConfigTemp();
bool EstabilizarPulso(int pin);
bool LeerPulsoEnBajo(int pin,bool EstA);

#endif 
