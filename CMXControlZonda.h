#ifndef CMXControlZonda_h
#define CMXControlZonda_h
#include "Arduino.h"

class CMXControlZonda
{
	public:
	    CMXControlZonda(int _pinZonda);
			float Consultar(DallasTemperature sensorTemp);
      int GetPin();
	private:
		int pinZonda;
		
};


#endif 
