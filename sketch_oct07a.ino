#include "motordriver_4wd.h"
#include "seeed_pwm.h"
#include "spi_configuration.h"
#include "spi_queue.h"

/*This code controls the motor. Specifically it can start/stop motor, change the direction, and adjust the speed. 
 * Code Modified 8/8/2016
 * Modified by: Zachary Phillips, Miguel Martinez, and Simon
 */
int spivalue;
spi_configuration SPI1;
void setup()
{
    
    queue10 spi_queue;
    MOTOR.init(); //Init all pin
    SPI1.init();
    
}

void loop()
{
    spivalue = SPI1.spi_ReadData();
    if(spivalue==0x83){
    MOTOR.setSpeedDir1(40, DIRF); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRR); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    }
    else{
    MOTOR.setSpeedDir1(0, DIRR); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(0, DIRF); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    delay(1500);
    }
}
