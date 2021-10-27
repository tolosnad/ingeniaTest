/* Ingenia API.c */

void RobotTask(uint8_t u8Command) {

}

void RobotStop (void) {

}

void TimerInit(void) {

}

Interrupt void TimerISR(void) {
  SPIEepromDisable(); //1us
  SPISensorEnable(); //1us
  sensorData = SPIRead(); //5us
  if(sensorData > 128){
    RobotStop(); //15us
  }
  SPISendorDisable(); //1us
  SPIEepromEnable(); //1us
  TimerInit(); 
}

uint32_t TimetGetus(void) {
  uint32_t dummy = 11;
  return dummy;
  
}

void SPIInit(void) {

}

void SPIEepromEnable(void){

}

void SPIEepromDisable(void){

}

void SPISensorEnable(void){

}

void SPISensorDisable(void){

}

uint8_t SPIRead(void){
  uint8_t dummy = 1;
  return dummy;
}

