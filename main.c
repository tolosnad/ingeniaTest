/*Ingenia Exercice 3 */

#include api.h

uint8_t sensorData; //global variable, will be updated by the interruption

int main(void){
  uint8_t epromData;
  //Init Timer and initialitze interruption
  TimerInit();
  //SPI bus initialization
  SPIInit();
  SPIEepromDisable(); //1us
  SPISensorEnable(); //1us
  sensorData = SPIRead(); //5us
  SPISensorDisable(); //1us
  while(true) {
    // Enable Eprom
    SPIEpromEnable(); //1us
    //read eprom data
    epromData = SPIRead();
    if(sensorData < 128 ) {
      RobotTask(epromData); //100ms
    } else {
      RobotStop(); //15us
    }
  }   
}
