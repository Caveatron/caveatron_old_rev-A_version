void UTFT_CTE::_SPIstart()
{
	spiBegin();
	spiInit(4);
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
#define SPI_CHIP_SEL 3
//------------------------------------------------------------------------------
/** Disable DMA Controller. */
static void dmac_disable() {
  DMAC->DMAC_EN &= (~DMAC_EN_ENABLE);
}
//** Enable DMA Controller. */
static void dmac_enable() {
  DMAC->DMAC_EN = DMAC_EN_ENABLE;
}
//------------------------------------------------------------------------------
static void spiBegin() {
  PIO_Configure(
      g_APinDescription[PIN_SPI_MOSI].pPort,
      g_APinDescription[PIN_SPI_MOSI].ulPinType,
      g_APinDescription[PIN_SPI_MOSI].ulPin,
      g_APinDescription[PIN_SPI_MOSI].ulPinConfiguration);
  PIO_Configure(
      g_APinDescription[PIN_SPI_MISO].pPort,
      g_APinDescription[PIN_SPI_MISO].ulPinType,
      g_APinDescription[PIN_SPI_MISO].ulPin,
      g_APinDescription[PIN_SPI_MISO].ulPinConfiguration);
  PIO_Configure(
      g_APinDescription[PIN_SPI_SCK].pPort,
      g_APinDescription[PIN_SPI_SCK].ulPinType,
      g_APinDescription[PIN_SPI_SCK].ulPin,
      g_APinDescription[PIN_SPI_SCK].ulPinConfiguration);
  pmc_enable_periph_clk(ID_SPI0);

  pmc_enable_periph_clk(ID_DMAC);
  dmac_disable();
  DMAC->DMAC_GCFG = DMAC_GCFG_ARB_CFG_FIXED;
  dmac_enable();
}
//------------------------------------------------------------------------------
//  initialize SPI controller
static void spiInit(uint8_t spiRate) {
  Spi* pSpi = SPI0;
  uint8_t scbr = 255;
  if (spiRate < 14) {
    scbr = (2 | (spiRate & 1)) << (spiRate/2);
  }
  scbr = spiRate;  //thd
  //  disable SPI
  pSpi->SPI_CR = SPI_CR_SPIDIS;
  // reset SPI
  pSpi->SPI_CR = SPI_CR_SWRST;
  // no mode fault detection, set master mode
  pSpi->SPI_MR = SPI_PCS(SPI_CHIP_SEL) | SPI_MR_MODFDIS | SPI_MR_MSTR;
  // mode 0, 8-bit,
  pSpi->SPI_CSR[SPI_CHIP_SEL] = SPI_CSR_SCBR(scbr) | SPI_CSR_NCPHA;
  // enable SPI
  pSpi->SPI_CR |= SPI_CR_SPIEN;
}
//------------------------------------------------------------------------------
static inline uint8_t spiTransfer(uint8_t b) {
  Spi* pSpi = SPI0;

  pSpi->SPI_TDR = b;
  while ((pSpi->SPI_SR & SPI_SR_RDRF) == 0) {}
  b = pSpi->SPI_RDR;
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
