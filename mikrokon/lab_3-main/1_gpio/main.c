#include <stdint.h>
#include <stdbool.h>

#define GPIO ((NRF_GPIO_REGS *)0x50000000)

typedef struct
{
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

void button_init()
{
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	// GPIO->PIN_CNF[14] = (12 >> 2);
	//  Fill inn the configuration for the remaining buttons
}

int btn1pressed()
{
	return (!(GPIO->IN & (1 << 13)));
}

int btn2pressed()
{
	return (!(GPIO->IN & (1 << 14)));
}

void led_init(){
	for (int i = 17; i <= 20; i++)
		{
			GPIO->DIRSET = (1 << i);
			
		}
}


int main()
{
	
	
	button_init();
	led_init();

	//int sleep = 0;
	while (1)
	{
		if (btn1pressed())
		{
			for (int i = 17; i <= 20; i++)
			{
			
				GPIO->OUTCLR = (1 << i);
			}
		}
		
		if (btn2pressed())
		{
			for (int i = 17; i <= 20; i++)
			{
				
				GPIO->OUTSET = (1 << i);
			}
		}
		
		
		/*
		

		sleep = 1000;
		while (--sleep)
			; // Delay

		if (1)
		{
			for (int i = 17; i <= 20; i++)
			{
				GPIO->DIRCLR= (1<< i);
				GPIO->OUTCLR = (1 << i);
			}
		}
		sleep = 1000;
		while (--sleep)
			; // Delay
		*/

		/* Check if button 1 is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */

	}
	return 0;
}
