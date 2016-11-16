#include "SPI_IN.h"



void SPI_IN::SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDRB = _BV(4);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
char SPI_IN::SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return Data Register */
	return SPDR;
}

SPI_IN spi;
