

#include <avr/io.h>
#include <avr/interrupt.h>


class SPI_IN{
	
	
	public:
	
	void SPI_SlaveInit(void);
	char SPI_SlaveReceive(void);
	
	
	
	
	
	};

  extern SPI_IN spi;
