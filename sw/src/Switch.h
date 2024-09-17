// Switch.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the Switch Module

#define SWITCH_H
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************Switch_Init********************
// Initialize ports PC4-7, PF0, PF4
// Input: none
// Output: none
void Switch_Init(void);


uint32_t Switch_In(void);