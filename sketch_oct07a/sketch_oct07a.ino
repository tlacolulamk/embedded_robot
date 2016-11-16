#include "motordriver_4wd.h"
#include "seeed_pwm.h"
#include "SPI_IN.h"

/*This code controls the motor. Specifically it can start/stop motor, change the direction, and adjust the speed. 
 * Code Modified 8/8/2016
 * Modified by: Zachary Phillips, Miguel Martinez, and Simon
 */
int spivalue;
void setup()
{
    spi.SPI_SlaveInit();
    MOTOR.init(); //Init all pin
}

void loop()
{
  spivalue = spi.SPI_SlaveReceive();
    if(spivalue==0x83){
    MOTOR.setSpeedDir1(40, DIRF); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRF); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    }else{
    MOTOR.setSpeedDir1(0, DIRR); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(0, DIRF); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    }
}
