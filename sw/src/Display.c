// Display.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the Display module


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "../inc/ST7735.h"

void Display_Init(void) {
	ST7735_InitR(INITR_REDTAB); // initialize LCD
	ST7735_FillScreen(ST7735_BLACK);
	ST7735_DrawLine(1,1,40,40, ST7735_CYAN);
}

void Display_AnalogClock(void) {
	
}

void Display_DigitalClock(void) {
	
	
}

void Display_AlarmSettings(void) {
	
}

void Display_TimeChangeSettings(void) {
	
}