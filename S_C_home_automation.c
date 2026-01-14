// Serial comm using 8051

#include <reg52.h>
#include "lcd4bit.h"
sbit lamp = P1^0;

void S_init()
{
  SCON = 0x50; // 8bit UART mode 
  TMOD = 0x20; // timer 1 in 8bit auto reload (mode 2) 
  TH1  = 0xFD;  // 9600 baud 	rate
  TR1 = 1; // timer start
}
void S_tx(unsigned char t)
{
	SBUF = t;
	while(TI == 0);
  TI = 0;
}
 unsigned char s_rx(void)
{
unsigned char rxd;
while(RI == 0);
 rxd = SBUF;
 P1 = rxd;
 RI = 0;	
	return rxd;
}
void S_tx_msg(unsigned char* p) //for transmitt msg
{
	int i=0;
	while (p[i] != '\0')
	{
		S_tx(p[i++]);
	}
}
void s_rx_msg(unsigned char* p)  // for receving msg
{
	int k = 0;
	while (k < 15)
	{
		p[k] = s_rx();
		k++;
	}
}

void main()
{ 
	unsigned char r;
	S_init();
	lcd_Init();
	S_tx_msg("Home Automation");
	set_cursor(0,1);
	clr();
	
	while(1)
	{
		S_tx_msg("Hello");
		
		r= s_rx();
		if(r == 'A')
		{
			lamp = 1;
			S_tx_msg("Lamp on\n");
			set_cursor(3,0);
			print("ON");
		}
		else if (r == 'a')
		{
			lamp = 0;
			S_tx_msg("Lmp OFF\n");
		
		}
	}
}