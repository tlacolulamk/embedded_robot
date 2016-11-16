#ifndef __SPI_CONFIGURATION
#define __SPI_CONFIGURATION
class spi_configuration
{
    private:
          
    public:    
    void init();    
    int spi_ReadData();
    void spi_Stop_Car();
    void spi_Forward_Straight_Motion();    
    void spi_Forward_Reverse_Motion();       
    void spi_Forward_90Right_Turn();   
    void spi_Forward_90Left_Turn();
   
};
#endif

