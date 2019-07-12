#include "Modulos.h"

//Configuracion Disyplay 
//columnas y filas
#define COLS 20
#define ROWS 4


LiquidCrystal Pantalla(dRST,dE,dD1,dD2,dD3,dD4);
//fin configuracion Display

//configuracion Zonda
//Pin zonda 

OneWire puertoTemp(pinZ);
DallasTemperature sensorTemp(&puertoTemp);
//configuracion Zonda


bool motores[Cant_motores]={false,false,false};
int _pMotores[Cant_motores]={_mot1,_mot2,_mot3};

bool apagar=false;
float temperaturaIdeal=Leer_ZS(0);
byte resetear=Leer_ZS(4);

void setup() 
{
  Serial.begin(9600);
  Pantalla.begin(COLS,ROWS);
  sensorTemp.begin();
  pinMode(_mas, INPUT);
  pinMode(_men, INPUT);
  pinMode(_si, INPUT);
  pinMode(_no, INPUT);
  ConfigurarMotores(_pMotores);
  
}


//Serial.println("");


void loop() 
{
  
  if(resetear!=123)
  {
    
    ConfiguracionIncial(&resetear);
    temperaturaIdeal=Leer_ZS(0);
  }
  
  bool Epsi,EApsi=LOW;
  bool Epno,EApno=LOW;
    Bienvenida();
     
    while(!apagar)
    {      
     PintarDatos(TemperaturaAmbiente(sensorTemp),Alarma());
     
     Epsi=EstabilizarPulso(_si);
     Epno=EstabilizarPulso(_no);
    
     if((EApsi==LOW&&Epsi==HIGH)&&(EApno==LOW&&Epno==HIGH))
     {ConfiguracionIncial(&resetear);}
     
     if(EApsi==LOW&&Epsi==HIGH)
     {ConfigTemp();}      
     
     EApsi=Epsi;
     EApno=Epno;
     

                 
    } 
   
}
