#ifndef Modulos_h
#define Modulos_h
#include <DallasTemperature.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

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
#define Cant_motores 3
#define T 3
#define _mot1 A1
#define _mot2 A2
#define _mot3 A3


//Display
void Bienvenida();
void PintarDatos(float TA,bool alarma);
void PantallaConfiguracion(float temp);

//Zonda
float TemperaturaAmbiente(DallasTemperature sensor);

//Control 
bool EstatusDeSistema();
bool Alarma();
void ConfigTemp();
bool EstabilizarPulso(int pin);
void  ConfiguracionIncial(byte resetear);
void ControlarTemperatura(float temp[T],float TA);

//Memoria EEEPROM
bool Guardar_ZS(int indice,byte Dato);
int Leer_ZS(int i);
bool Guardar(byte dato);
 
//Control de Motores 
void ControlMotores(int orden);
void ConfigurarMotores(int p[Cant_motores]);
void AccionarMotores(bool mot[Cant_motores],int _pMotores[Cant_motores]);
#endif 
