/*Ingenia API.h*/

void RobotTask(uint8_t u8Command);
void RobotStop (void) void TimerInit(void);
Interrupt void TimerISR(void);
uint32_t TimetGetus(void);
void SPIInit(void);
void SPIEepromEnable(void);
void SPIEepromDisable(void);
void SPISensorEnable(void);
void SPISensorDisable(void);
uint8_t SPIRead(void);
