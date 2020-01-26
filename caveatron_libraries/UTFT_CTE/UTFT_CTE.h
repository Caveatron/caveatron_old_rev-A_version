/*
	This library has been modified for use with the Caveatron
	Changed BVS defines to CBVS to avoid conflict with UTFT_GHL library
	Adds new function definitions for returning pixel size of strings in x and y
	Moves five global variable declarations from UTFT_CTE.cpp for consistency
	Adds new hardware folder and functions to support Teensy 3.5/3.6
	Rev 2019-01-24 - Joe Mitchell
*/

#ifndef UTFT_CTE_h											
#define UTFT_CTE_h											

#if defined(__AVR__)										
	#include "hardware/avr/HW_AVR_defines.h"				
	#include "SPI.h"
#elif defined (__MK64FX512__) || defined (__MK66FX1M0__) //Caveatron Modification for Teensy 3.5/3.6	
	#include "hardware/teensy/HW_TEENSY_defines.h"		//Caveatron Modification for Teensy 3.5/3.6	
#elif defined(__arm__)										
	#include "hardware/arm/HW_ARM_defines.h"				
#endif														

#include <UTFT.h>
#if ((!defined(UTFT_VERSION)) || (UTFT_VERSION<241))
	#error : You will need UTFT v2.41 or higher to use this add-on library...
#endif

// *** Start Modification for Caveatron ***
//BVS= Bitstream vera sans, suffix = font size in pixel (height)
//Caveatron modification - changed to CBVS to avoid conflict with GHL_UTFT library
#define CBVS_13 10											 
#define CBVS_15 12											 
#define CBVS_19 14											 
#define CBVS_22 18											 
#define CBVS_28 22											 
#define CBVS_34 28											 
#define CBVS_43 38											 
#define CBVS_52 53											 
#define CBVS_74 78											 
#define CBVS_112 122	
// *** End Modification for Caveatron ***										 

class UTFT_CTE
{
	public:
		UTFT_CTE(UTFT *ptrUTFT);							
		void	SPI_Flash_init(int CSpin);
		void	show_color_bar();
		void	Load_image(int X, int Y, int location);
		void	Send_Flash_information_to_UART();
		void	Put_Text(String st, int x, int y, int font_number);
		void	Put_Text_array(char *st, int x, int y, int font_number);
		void	Set_character_spacing(unsigned char space);

		// *** Start Modification for Caveatron ***
		uint8_t Get_Text_size_x(String st, int font_number);
		uint8_t Get_Text_size_y(int font_number);
		uint8_t	Get_Text_array_size(char *st, int font_number);
		
	private:
		// Declarations moved from CTE_UTFT.cpp
		unsigned char font_height;
		unsigned int font_size;
		unsigned long font_address;
		unsigned int PositionX, PositionY;
		unsigned char Charspace = 1;
		// *** End Modification for Caveatron ***
		
	protected:												
		UTFT	*_UTFT;
		regtype *P_F_CS;
		regsize B_F_CS;
		void	setXY_2(word x1, word y1, word x2, word y2);
		void	setXY_4(word x1, word y1, word x2, word y2);
		void	Draw_character(unsigned char character);

		void	_SPIstart();								
		void	_SPIwrite(byte data);						
		byte	_SPIread();									
};

#if defined(__arm__)										
	static	void spiInit(uint8_t spiRate);					
	static	void spiBegin();								
	static	uint8_t spiRec();								
	static	void spiSend(uint8_t b);						
#endif														

#endif														
