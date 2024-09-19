// Display.h
// Runs on LM4F120/TM4C123
// Provide functions that initialize the Display Module

#define DISPLAY_H
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "../inc/ST7735.h"

void Display_Init(void);

void Display_AnalogClock(void);

void Display_DigitalClock(void);