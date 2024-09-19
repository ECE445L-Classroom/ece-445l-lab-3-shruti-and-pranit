// Switch.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the Switch Module


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************Switch_Init********************
// Initialize ports PC4-7, PF0, PF4
// Input: none
// Output: none
void Switch_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x24;
	int delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTC_DIR_R &= ~0xF0;
  GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTF_DIR_R &= ~0x11;
  GPIO_PORTF_DEN_R |= 0x11;
}


uint32_t Switch_In(void) {
	
	if((GPIO_PORTC_DATA_R&0x10) == 1) {
		return 0; // move up
	}
	else if((GPIO_PORTC_DATA_R&0x20) == 1) {
		return 1; // move down
	}
	else if ((GPIO_PORTC_DATA_R&0x40) == 1) {
		return 2; // move right
	}
	else if((GPIO_PORTC_DATA_R&0x80) == 1) {
		return 3; // move left
	}
	else if((GPIO_PORTF_DATA_R&0x01) == 1) {
		return 4; // enter
	}
	else if((GPIO_PORTF_DATA_R&0x10) == 1) {
		return 5; // stop
	}
	return -1;
	
}