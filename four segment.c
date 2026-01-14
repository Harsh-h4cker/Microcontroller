/* 4 segment interfcing with 8051
   date: 30-09-2025 
*/

// four seven segment interfacing 
 
#include <reg52.h>
 
void delay(int ms)
 {
	 int i,j;
	 for(i=0;i<ms;i++)
	   for(j=0;j<112;j++);
 }
 
void main()
{
	int count,tempt,num,i;
	char segment_cc[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	char segment_ca[]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
	while(1)
	{
		for(count=0;count<=9999;count++)
		{
			for(i=0;i<=112;i++)
			{
				num=count;
				tempt = num/1000;
				num = num%1000;
				P1 = 0xe1; 
				P0 = segment_ca[tempt];
				P2 = segment_cc[tempt];
				delay(2);
			
				
				tempt = num/100;
				num = num%100;
				P1 = 0xd2;  
				P0 = segment_ca[tempt];
				P2 = segment_cc[tempt];
				delay(2);
				
				
				tempt = num/10;
				P1 = 0xb4;  
				P0 = segment_ca[tempt];
				P2 = segment_cc[tempt];
				delay(2);
				
				tempt = num%10;
				P1 = 0x78;
				P0 = segment_ca[tempt];
				P2 = segment_cc[tempt];
			  delay(2);	
				
			}
		}
		 delay(100);
	}
}
