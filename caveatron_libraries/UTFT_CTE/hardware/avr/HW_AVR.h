void UTFT_CTE::_SPIstart()
{
	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	sbi(P_F_CS, B_F_CS);
}

void UTFT_CTE::_SPIwrite(byte data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

byte UTFT_CTE::_SPIread(void)
{
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

