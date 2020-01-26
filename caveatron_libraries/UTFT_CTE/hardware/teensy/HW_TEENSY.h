#include <SPI.h>
SPISettings spiSet(10000000, MSBFIRST, SPI_MODE0);

void UTFT_CTE::_SPIstart()
{
	SPI.begin();
	
}

void UTFT_CTE::_SPIwrite(byte data)
{
	spiSend(data);
}

byte UTFT_CTE::_SPIread(void)
{
  return spiRec();
}

// SPI functions
//==============================================================================
/** chip select register number */
#define SPI_CHIP_SEL 27 //For Teensy
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
static inline uint8_t spiTransfer(uint8_t b) {

  SPI.beginTransaction(spiSet);
  digitalWrite(SPI_CHIP_SEL, LOW);
  b = SPI.transfer(b);
  digitalWrite (SPI_CHIP_SEL, HIGH);
  SPI.endTransaction();

  return b;
}
//------------------------------------------------------------------------------
/** SPI receive a byte */
static inline uint8_t spiRec() {
  return spiTransfer(0XFF);
}
//------------------------------------------------------------------------------
/** SPI send a byte */
static inline void spiSend(uint8_t b) {
  spiTransfer(b);
}
