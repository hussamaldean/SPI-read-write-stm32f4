//SPI pins
//MOSI PA7
//MISO PA6
//SCK PA5
//CS PA4
//AF5 for the gpio
#include "adc.h"
#include "LiquidCrystal.h"
#include "SPI.h"
char str[3];
char str1[3];
uint8_t adc;
uint16_t c;
int main(void){
spi_init();
LCD_init();
ADC_init();
setCursor(0,0);
LCD_Disp("Master: STM32F4");

while(1)
{
adc=readADC();
c=spi_read_write(adc);
setCursor(0,1);
LCD_Disp("SlaveVal:");
sprintf(str,"%u",c);
LCD_Disp(str); LCD_Disp("   ");
delay(100);
setCursor(0,2);
LCD_Disp("Sent value:");
setCursor(0,3);
sprintf(str1,"%u",adc);
LCD_Disp(str1); LCD_Disp("   ");
}

}



