#include "Modulos.h"
#include "Arduino.h"
#include <DallasTemperature.h>

float TemperaturaAmbiente(DallasTemperature sensor)
{
 	sensor.requestTemperatures();
	return sensor.getTempCByIndex(0);
}
