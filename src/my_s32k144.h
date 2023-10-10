/*
 * my_s32k144.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Admin
 */

#ifndef MY_S32K144_H_
#define MY_S32K144_H_

#define PCC_base 0x40065000u
#define PCC(port) (*(volatile unsigned int*) (PCC_base + 0x124u + 4*(port)))

#define Port_base 0x40049000u
typedef struct {
	volatile unsigned int PCR[32];
} PCR_type;
#define PORT(port) ((PCR_type*)(Port_base + 0x1000*(port)))

#define GPIO_base 0x400FF000u
typedef struct GPIO {
	volatile unsigned int PDOR;
	volatile unsigned int PSOR;
	volatile unsigned int PCOR;
	volatile unsigned int PTOR;
	volatile unsigned int PDIR;
	volatile unsigned int PDDR;
	volatile unsigned int PIDR;
} GPIO_type;
#define GPIO(port) ((GPIO_type*)(GPIO_base + 0x40*(port)))

#define portA 0
#define portB 1
#define portC 2
#define portD 3
#define portE 4

#define INPUT 0
#define OUTPUT 1

#define INTERRUPT_DISABLE 0
#define INTERRUPT_LOGIC0 8
#define INTERRUPT_RISING 9
#define INTERRUPT_FALLING 10
#define INTERRUPT_2EDGE 11
#define INTERRUPT_LOGIC1 12

void PCC_init(int PORTx);
void GPIO_init(int PORTx, int PINx, int direc, int interrupt);

#endif /* MY_S32K144_H_ */
