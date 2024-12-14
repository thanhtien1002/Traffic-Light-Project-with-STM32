/*
 * fsm_automatic.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "fsm_automatic.h"
#include "global.h"
#include "lcd.h"
int led_buffer[2] = {0, 0};
int init_flag = 0;
void autoMODE1_task() {
	if (mode == MODE1) {
		switch (statusAUTO1) {
				case INIT:
					statusAUTO1 = STATE_RED;
					break;
				case STATE_RED:
					enableRed1();
					enableRed3();
					led_buffer[0] = counterRed1;
					counterRed1--;
					if (counterRed1 == INIT) {
						counterRed1 = AUTO_RED;
						statusAUTO1 = STATE_GREEN;
					}
				    break;
				case STATE_GREEN:
					enableGreen1();
					enableGreen3();
					led_buffer[0] = counterGreen1;
					counterGreen1--;
					if (counterGreen1 == INIT) {
						counterGreen1 = AUTO_GREEN;
						statusAUTO1 = STATE_YELLOW;
					}
					break;
				case STATE_YELLOW:
						enableYellow1();
						enableYellow3();
						led_buffer[0] = counterYellow1;
						counterYellow1--;
						if (counterYellow1 == INIT) {
							counterYellow1 = AUTO_YELLOW;
							statusAUTO1 = STATE_RED;
						}
					break;
				default:
					break;
				}
	}
}

void autoMODE2_task() {
	if (mode == MODE1) {
		switch (statusAUTO2) {
				case INIT:
					statusAUTO2 = STATE_GREEN;
					break;
				case STATE_RED:
					enableRed2();
					enableRed4();
					led_buffer[1] = counterRed2;
					counterRed2--;
					if (counterRed2 == INIT) {
						counterRed2 = AUTO_RED;
						statusAUTO2 = STATE_GREEN;
					}
				    break;
				case STATE_GREEN:
					enableGreen2();
					enableGreen4();
					led_buffer[1] = counterGreen2;
					counterGreen2--;
					if (counterGreen2 == INIT) {
						counterGreen2 = AUTO_GREEN;
						statusAUTO2 = STATE_YELLOW;
					}
					break;
				case STATE_YELLOW:
						enableYellow2();
						enableYellow4();
						led_buffer[1] = counterYellow2;
						counterYellow2--;
						if (counterYellow2 == INIT) {
							counterYellow2 = AUTO_YELLOW;
							statusAUTO2 = STATE_RED;
						}
					break;
				default:
					break;
				}
	}
}

void autoMODE3_task() {
	if (mode == MODE1) {
		switch (statusAUTO3) {
			case INIT:
				statusAUTO3 = HIGH_DIGIT;
				lcd_clear_display();
				lcd_init();
				lcd_send_string("WAITING TIME");
				break;
			case HIGH_DIGIT:
				lcd_clear_display();
			    lcd_goto_XY(1, 0);
			    lcd_send_string("X ROAD: ");
			    lcd_send_int(led_buffer[0]);
			    lcd_goto_XY(2, 0);
			    lcd_send_string("Y ROAD: ");
			    lcd_send_int(led_buffer[1]);
			    statusAUTO3 = LOW_DIGIT;
			    break;
			case LOW_DIGIT:
				lcd_clear_display();
			    lcd_goto_XY(1, 0);
			    lcd_send_string("X ROAD: ");
			    lcd_send_int(led_buffer[0]);
			    lcd_goto_XY(2, 0);
			    lcd_send_string("Y ROAD: ");
			    lcd_send_int(led_buffer[1]);
			    statusAUTO3 = HIGH_DIGIT;
			    break;
			default:
				break;
		}
	}
}

void autoMODE4_task() {
			// CHANGE MODE
			switch (statusAUTO4) {
				case INIT:
					if (isButtonPressed(BUTTON1) == 1) {
						mode = MODE2;
						lcd_clear_display();
						init_flag = 0; // clear screen
					}
					break;
				case MODE2:
					if (isButtonPressed(BUTTON1) == 1) {
						mode = MODE3;
						lcd_clear_display();
					}
					break;
				case MODE3:
					if (isButtonPressed(BUTTON1) == 1) {
						mode = MODE1;
						lcd_clear_display();
					}
					initVar();
					break;
				default:
					break;
				}
}

