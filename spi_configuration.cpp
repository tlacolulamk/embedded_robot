#include <Arduino.h>
#include "SPI.h"
#include "seeed_pwm.h"
#include "motordriver_4wd.h"
#include "spi_configuration.h"
#include "spi_queue.h"

void spi_configuration::init(){
  pinMode(PB2,OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
}
int spi_configuration::spi_ReadData(){
  
  digitalWrite(PB2,LOW);
  int spi_value = SPI.transfer(0);
  digitalWrite(PB2,HIGH);
  return spi_value;
}

void spi_configuration::spi_Forward_Straight_Motion(){
  int value;
  if((value && 0x03)==0x03){
    MOTOR.setSpeedDir1(40, DIRF); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRF); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
  }
}
void spi_configuration::spi_Forward_Reverse_Motion(){
  int value;
  if((value & 0x01)==0x01){
    MOTOR.setSpeedDir1(40, DIRR); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRR); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
  }
}
void spi_configuration::spi_Forward_90Right_Turn(){
  int value;
  if((value & 0x1F)==0x1F){
    MOTOR.setSpeedDir1(40, DIRR); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRR); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    //The motor speed&direction aren't correct yet
  }
}
void spi_configuration::spi_Forward_90Left_Turn(){
  int value;
  if((value & 0x3F)==0x3F){
    MOTOR.setSpeedDir1(40, DIRR); //Set motor 1 and motor 2 direction:DIRF, Speed:80 (range:0-100).
    MOTOR.setSpeedDir2(40, DIRR); //Set motor 1 and motor 2 direction:DIRR, Speed:80 (range:0-100).
    //The motor speed&direction aren't correct yet
  }

}



