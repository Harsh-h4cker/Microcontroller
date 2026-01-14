/* 2segment interfcing with 8051
   date: 29-09-2025 
*/

// doule seven segment interfacing 
 
#include <reg52.h>

sbit seg_1 = P1^0;
sbit seg_2 = P1^1;
int a,b,k;

 char segment_cc[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 
void delay(int ms)
 {
	 int i,j;
	 for(i=0;i<ms;i++)
	   for(j=0;j<112;j++);
 }

 
 void display()
 {
	
	 seg_1 = seg_2 = 1;
	 P0 = segment_cc[0];
	 seg_1=0;
	 delay(2);
	 seg_1=1;
	 P0 = segment_cc[1];
	 seg_2=0;
	 delay(2);
	 seg_2=1;		 
 }
 
  void main()
	{
		while(1)
		{
			display();
		}
	}
 