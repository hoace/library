#include "my_s32k144.h"

int main(void)
{
	PCC_init(portD);
	GPIO_init(portD,0,OUTPUT,INTERRUPT_DISABLE);
	for(;;)
	{
		GPIO(portD)->PTOR ^=1;
		for(int i=0;i<500000;i++);
	}
}
