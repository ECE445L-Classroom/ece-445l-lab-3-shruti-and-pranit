// DAC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the DAC module


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************DAC_Init********************
// Initialize 3-bit DAC
// Input: none
// Output: none
void DAC_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x02;
	int delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_DIR_R |= 0x07;
  GPIO_PORTB_DEN_R |= 0x07;
}

// **************DAC_Out*********************
// output to DAC
// Input: 3-bit data, 0 to 8 
// Input=n is converted to n*3.3V/8
// Output: none
void DAC_Out(uint8_t data) {
	GPIO_PORTB_DATA_R = data;
}
