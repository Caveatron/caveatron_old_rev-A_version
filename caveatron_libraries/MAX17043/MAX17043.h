// MAX17043/44 library for Arduino
//
// Luca Dentella (http://www.lucadentella.it)

/*
	This library has been modified for use with the Caveatron
	Provides function to set custom i2C port
	Creates external instance of library
	Rev 2017-10-18 - Joe Mitchell
*/

#include "Arduino.h"
// *** Start Modifications for Caveatron ***
#include "Wire.h"
// *** End Modifications for Caveatron ***

#ifndef _MAX17043_H
#define _MAX17043_H

#define MAX17043_ADDRESS	0x36

#define VCELL_REGISTER		0x02
#define SOC_REGISTER		0x04
#define MODE_REGISTER		0x06
#define VERSION_REGISTER	0x08
#define CONFIG_REGISTER		0x0C
#define COMMAND_REGISTER	0xFE


class MAX17043 {

	public:
	
		// *** Start Modifications for Caveatron ***
		void setI2CPort(TwoWire &theWire);
		// *** End Modifications for Caveatron ***
		float getVCell();
		float getSoC();
		int getVersion();
		byte getCompensateValue();
		byte getAlertThreshold();
		void setAlertThreshold(byte threshold);
		boolean inAlert();
		void clearAlert();
		
		void reset();
		void quickStart();
	
	private:

		void readConfigRegister(byte &MSB, byte &LSB);
		void readRegister(byte startAddress, byte &MSB, byte &LSB);
		void writeRegister(byte address, byte MSB, byte LSB);
		// *** Start Modifications for Caveatron ***
		TwoWire *_wire = &Wire;		//Defaults to Wire0
		// *** End Modifications for Caveatron ***
};

// *** Start Modifications for Caveatron ***
extern MAX17043 MAXbatt;
// *** End Modifications for Caveatron ***

#endif