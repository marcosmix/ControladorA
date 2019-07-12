#ifndef Modulos_h
#define Modulos_h
#include <DallasTemperature.h>

//pines 
#define dRST 12
#define dE 11
#define dD1 5
#define dD2 4
#define dD3 3
#define dD4 2

#define _mas 10
#define _men 8
#define _si 13
#define _no 9

#define pinZ A0

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
