#include "my_s32k144.h"

void GPIO_init(int PORTx, int PINx, int direc, int interrupt)
{
	PORT(PORTx)->PCR[PINx] |= (1<<8);
	if(direc==OUTPUT)
	{
		GPIO(PORTx)->PDDR |= (1<<PINx);
	}
	else
	{
		GPIO(PORTx)->PDDR &= ~(1<<PINx);
	}

	PORT(PORTx)->PCR[PINx] |= (interrupt<<16);
}

