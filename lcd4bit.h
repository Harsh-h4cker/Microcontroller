
#include <reg52.h>

extern bit RS;
extern bit RW;
extern bit EN;  //control pins
extern bit d4;
extern bit d5;
extern bit d6;
extern bit d7;  //data pins

extern bit a0,a1,a2,a3,a4,a5,a6,a7;
sbit a0 = B^0;
sbit a1 = B^1;
sbit a2 = B^2;
sbit a3 = B^3;
sbit a4 = B^4;
sbit a5 = B^5;
sbit a6 = B^6;
sbit a7 = B^7; //B register


void lcd_Init(void);
void delay(int);
void cmd(unsigned char);
void lcddata(unsigned char);
void set_cursor(int,int);
void print(char *p);
void clr(void);

void lcd_Init()
{
	  cmd(0x02);
	  cmd(0x28); //lcd in 4 bit mode,5*7 font
		cmd(0x01); // clear data register
		cmd(0x10); // shift cursor to left position
		cmd(0x0C); // display on
}
void delay(int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<112;j++);
}
void cmd(unsigned char value)
{
	B = value;
	RS = 0;
	RW = 0;
	d4 = a4;
	d5 = a5;
	d6 = a6;
	d7 = a7;
	EN = 1;
	delay(10);
	EN = 0;
	d4 = a0;
	d5 = a1;
	d6 = a2;
	d7 = a3;
	EN = 1;
	delay(10);
	EN = 0;
}

void lcddata(unsigned char value)
{
	B = value;
	RS = 1;
	RW = 0;
	d4 = a4;
	d5 = a5;
	d6 = a6;
	d7 = a7;
	EN = 1;
	delay(10);
	EN = 0;
	d4 = a0;
	d5 = a1;
	d6 = a2;
	d7 = a3;
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

void set_cursor(int c,int r)
{
	if(r == 0)
	{
		cmd(0x80+c);
	}
	else if(r == 1)
	{
		cmd(0xC0+c);
	}
}

void clr()
{
	cmd(0x01);
}

