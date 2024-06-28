/*
5) Write an ECP to find the second highest digit in a given integer and display its binary equivalent
   on 8-LEDS (4-Active High LEDS& 4-Active Low LEDS).  
*/

#include <LPC21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"

#define leds 17 //p1.17 to p1.24 

u32 sec_high(u32 x);

s32 main()
{
	u32 i=154;


	IODIR1|=(0xFF<<leds); //cfg as output
	
	//INITIAL LEDS OFF (upper nibble-AH, lower nibble-AL)
	IOPIN1 = (IOPIN1&(~(0XFF<<leds))) | (0X0F<<leds);
	
	i= sec_high(i);
	
				IOPIN1=  (IOPIN1&(~(0xFF <<leds))) | ((i^(0x0F))<<leds);
				delay_ms(500);

	while(1);
}

u32 sec_high(u32 x)
{
	u32 cur=0,sec=0;
		u16 f=0;
	
	while(x)
	{

			if((x%10)> cur)
			{
				f++;
				sec=cur;
				cur= x%10;
			}
			
			if((x%10>sec) && ((x%10)<cur))
			{
				sec=x%10;
			}
	
		x/=10;
	}
	
	if(f==1)
	{
		sec=cur;
	}
	
return sec;	
}
