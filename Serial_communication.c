// Serial comm using 8051

#include <reg52.h>
void S_init()
{
  SCON = 0x50; // 8bit UART mode 
  TMOD = 0x20; // timer 1 in 8bit auto reload (mode 2) 
  TH1  = 0xFD;  // 9600 baud 	rate
  TR1 = 1; // timer start
}
void S_tx(void)
{
	SBUF = 'K';
	while(TI == 0);
  TI = 0;	
}
void s_rx(void)
{
unsigned char rxd;
while(RI == 0);
 rxd = SBUF;
 P1 = rxd;
 RI = 0;	
}

void main()
{
	S_init();
	while(1)
	{
		S_tx();
		s_rx();
	}
}