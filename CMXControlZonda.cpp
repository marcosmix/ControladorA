#include "Arduino.h"
#include "CMXControlZonda.h"



CMXControlZonda::CMXControlZonda(int _pinZonda)
{
	pinZonda =_pinZonda;

}
int CMXControlZonda::GetPin()
{
  return pinZonda;
}

float CMXControlZonda::Consultar(DallasTemperature sensorTemp)
{
  
	sensorTemp.requestTemperatures();
	return sensorTemp.getTempCByIndex(0);
}


