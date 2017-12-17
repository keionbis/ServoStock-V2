
//AS5055 READ DATA PROGRAM
//www.AleyRobotics.com, 2013
//Email: info@AleyRobotics.com

#include <SPI.h>
  unsigned int result = 0;
  unsigned int result1 = 0;
  unsigned int result2 = 0;

void setup ()
{
Serial.begin(9600);
SPI.begin(18,19,23,5);
SPI.setBitOrder(MSBFIRST);
SPI.setClockDivider(SPI_CLOCK_DIV2); //you can chose faster SPI frequency 
}

void loop () {
  digitalWrite(SS, LOW);
  result1 = SPI.transfer(0xff);
  result2 = SPI.transfer(0xff);  
  digitalWrite(SS, HIGH);
  result1 &= 0b00111111;
  result1 = result1 << 8;
  result = (result1 | result2) >> 1;
  Serial.print("Result: ");
  Serial.print(" = ");
  Serial.println(result, DEC);
  delay(100);
}
