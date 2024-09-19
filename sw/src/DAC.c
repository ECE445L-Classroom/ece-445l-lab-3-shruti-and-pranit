// DAC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the DAC module


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************DAC_Init********************
// Initialize 3-bit DAC
// Input: none
// Output: none
void DAC_Init(uint16_t data) {
	SYSCTL_RCGCSSI_R |= 0x02; // activate SSI1
	SYSCTL_RCGCGPIO_R |= 0x08;// activate port D
	while((SYSCTL_PRGPIO_R&0x08) == 0){};
	SSI1_CR1_R = 0x00000000; // disable SSI, master mode
	GPIO_PORTD_AFSEL_R |= 0x0B; // enable alternate function on PD3,1,0
	GPIO_PORTD_DEN_R |= 0x0B; // enable digital I/O on PD3,1,0
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0xFFFF0F00) + 0x00002022;
	GPIO_PORTD_AMSEL_R &= ~0x0B; // disable analog functionality on PD
	SSI1_CPSR_R = 0x08; // 80MHz/8 = 10 MHz SSIClk (should work up to 20 MHz)
	SSI1_CR0_R &= ~(0x0000FFF0); // SCR = 0, SPH = 0, SPO = 1 Freescale
	SSI1_CR0_R += 0x40; // SPO = 1
	SSI1_CR0_R |= 0x0F; // DSS = 16-bit data
	SSI1_DR_R = data; // load 'data' into transmit FIFO
	SSI1_CR1_R |= 0x00000002; // enable SS
		
}

// **************DAC_Out*********************
// output to DAC
// Input: 3-bit data, 0 to 8 
// Input=n is converted to n*3.3V/8
// Output: none
void DAC_Out(uint8_t data) {
	while((SSI1_SR_R&0x00000002)==0){};// wait until room in FIFO
	SSI1_DR_R = data;
}
