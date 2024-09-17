// DAC.h
// Runs on LM4F120/TM4C123
// Provide functions that initialize the DAC module

#define DAC_H
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************DAC_Init********************
// Initialize 3-bit DAC
// Input: none
// Output: none
void DAC_Init(void);

// **************DAC_Out*********************
// output to DAC
// Input: 3-bit data, 0 to 8 
// Input=n is converted to n*3.3V/8
// Output: none
void DAC_Out(uint8_t data);