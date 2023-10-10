#include "my_s32k144.h"

void PCC_init(int PORTx)
{
	PCC(PORTx) |= (1<<30);
}

