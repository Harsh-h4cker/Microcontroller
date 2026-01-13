/* Interfacing 16x2 LCD with 8051
   Date: 15-10-2025
*/

#include <reg52.h>

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void lcd_Init();
void delay(int);
void cmd(unsigned char);
void lcddata(unsigned char);
void set_cursor(int,int);
void print(char *p);


void delay(int ms)
{
	int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<112;j++);
}
void cmd(unsigned char value)
{
	P0 = value;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;
}

void lcddata(unsigned char vlaue)
{
	P0 = vlaue;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;
}
void print(char *p) 
{
	while(*p)
	{
		lcddata(*p++);
	}
}
void lcd_Init()
{
	P0 = 0x00;
	  cmd(0x38); // lcd in 8bit mode		
		cmd(0x01);// clear data register
		cmd(0x10);// shift cursor to left 
		cmd(0x0c);// dispaly on
}	