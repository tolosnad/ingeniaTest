#include api.h

uint8_t sensorData; //global variable, will be updated by the interruption

int main(void){
  uint8_t epromData;
  //Init Timer and initialitze interruption
  TimerInit();
  //SPI bus initialization
  SPIInit();
  SPIEepromDisable(); //1us
  SPISensorEable(); //1us
  sensorData = SPIRead(); //5us
  if(sensorData > 128){
    RobotStop(); //15us
  }
  SPISensorDisable(); //1us
  // Enable Eprom
  SPIEepromEnable(); //1us
  while(true) {
    //read eprom data
    epromData = SPIRead(); //5us
    if(sensorData > 128){
      RobotStop(); //15us
    } else {
      RobotTask(epromData); //100ms
    } 
  }   
}
