#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"
#include "seven segment.h"
#include "std_macros.h"

#define TIMEOFGREEN 1100 // 10 seconds
#define TIMEOFYELLOW 600 // 5 seconds
#define TIMEOFRED 800 // 7 seconds

#define GREEN 0
#define YELLOW 1
#define RED 2


signed short counter = TIMEOFGREEN;
unsigned char flag = GREEN;
int main(void)
{
	LED_vInit('C',PINC0);
	LED_vInit('C',PINC1);
	LED_vInit('C',PINC2);
	seven_seg_vinit('A');
	SET_BIT(DDRA,PINA4);
	SET_BIT(DDRA,PINA5);
	
    while(1)
    {
		if(GREEN == flag)
		{
			LED_vTurnOn('C',PINC2);
			LED_vTurnOff('C',PINC1);
			LED_vTurnOff('C',PINC0);
			counter = TIMEOFGREEN;
			flag = YELLOW;
		}
		else if(YELLOW == flag)
		{
			LED_vTurnOn('C',PINC1);
			LED_vTurnOff('C',PINC2);
			LED_vTurnOff('C',PINC0);
			counter = TIMEOFYELLOW;
			flag = RED;
		}
		else if(RED == flag)
		{
			LED_vTurnOn('C',PINC0);
			LED_vTurnOff('C',PINC2);
			LED_vTurnOff('C',PINC1);
			counter = TIMEOFRED;
			flag = GREEN;
		}
		else
		{
			
		}
		while(counter>0)
		{
			
			SET_BIT(PORTA,PINA4);
			CLR_BIT(PORTA,PINA5);
			seven_seg_write('A',counter/100%10);
			_delay_ms(5);
			SET_BIT(PORTA,PINA5);
			CLR_BIT(PORTA,PINA4);
			seven_seg_write('A',counter/1000 );
			_delay_ms(5);
			counter--;
		}
		
	}

}