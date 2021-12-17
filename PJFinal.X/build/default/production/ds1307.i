# 1 "ds1307.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "E:/Program Files/Microchip/MPLABX/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ds1307.c" 2
# 1 "./i2c.h" 1




 void i2cInit(void);
 unsigned char i2cWriteByte(unsigned char send_start, unsigned char send_stop, unsigned char byte);
 unsigned char i2cReadByte(unsigned char nack, unsigned char send_stop);
# 2 "ds1307.c" 2
# 1 "./ds1307.h" 1
# 14 "./ds1307.h"
 void dsInit(void);
 void dsStartClock(void);
 void dsStopClock(void);
 int dec2bcd(int value);
 int bcd2dec(int value);
 void dsWriteData(unsigned char value, int address);
 int dsReadData(int address);
# 3 "ds1307.c" 2






int dec2bcd(int value) {
 return ((value / 10 * 16) + (value % 10));
}
int bcd2dec(int value) {
 return ((value / 16 * 10) + (value % 16));
}
void dsInit(void) {
 i2cInit();
}
void dsStartClock(void) {
 int seconds;
 seconds = dsReadData(0);
 dsWriteData(0x7f & seconds,0);
 return;
}
void dsWriteData(unsigned char value, int address) {
 i2cWriteByte(1,0, (0x68<<1)|0);
 i2cWriteByte(0,0,address);
 i2cWriteByte(0,1,value);
}
int dsReadData(int address) {
 int result;
 i2cWriteByte(1,0,(0x68<<1) | 0);
 i2cWriteByte(0,0,address);
 i2cWriteByte(1,0, (0x68<<1) | 1);
 result = i2cReadByte(1,1 );
 return result;
}
