/*
 * fsm_manual.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "fsm_manual.h"
#include "button.h"


// CONFIG RED
void manMODE2_1_task() {
	if (mode == MODE2) {
		// Blinked LED
		switch (statusMODE2_1) {
			case INIT:
				statusMODE2_1 = TOGGLE;
				break;
			case TOGGLE:
				toggleRED1();
				toggleRED2();
				break;
			default:
				break;
		}
	}
}

void manMODE2_2_task() {
	if (mode == MODE2) {
	// DISPLAY CONFIG RED
		switch (statusMODE2_2) {
			case INIT:
				statusMODE2_2 = HIGH_DIGIT;
				break;
			case HIGH_DIGIT:
				statusMODE2_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME RED: ");
				lcd_send_int(AUTO_RED);
				break;
			case LOW_DIGIT:
				statusMODE2_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME RED: ");
				lcd_send_int(AUTO_RED);
				break;
			default:
				break;
		}
	}
}

void manMODE2_3_task() {
	if (mode == MODE2) {
			// Change time for mode
			switch (statusMODE2_3) {
			case INIT:
				if (isButtonPressed(BUTTON3) == 1) {
					statusMODE2_3 = INCREASE;
					AUTO_RED++;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON3) == 1) {
					AUTO_RED += 1;
					if (AUTO_RED > UPPER_BOUND)
						AUTO_RED = UPPER_BOUND;
				}
				if (isButtonPressed(BUTTON2) == 1) {
					statusMODE2_3 = SAVE;
				}
				break;
			case DECREASE:
				if (isButtonPressed(BUTTON4) == 1) {
					AUTO_RED -= 1;
					if (AUTO_RED < LOWER_BOUND) {
						AUTO_RED = LOWER_BOUND;
					}
				}
				if (isButtonPressed(BUTTON2) == 1) {
					statusMODE2_3 = SAVE;
				}
				break;
			case SAVE:
				if (AUTO_RED != (AUTO_GREEN + AUTO_YELLOW)) {
					time_traffic_base();
				}
				mode = MODE1;
				initVar();
				break;
			default:
				break;
			}

			// Continue to MODE3
			if (isButtonPressed(BUTTON1) == 1) {
				mode = MODE3;
			}
	}
}

// CONFIG GREEN
void manMODE3_1_task() {
	if (mode == MODE3) {
		// Blinked LED
		switch (statusMODE3_1) {
			case INIT:
				statusMODE3_1 = TOGGLE;
				break;
			case TOGGLE:
				toggleGREEN1();
				toggleGREEN2();
				break;
			default:
				break;
		}
	}
}

void manMODE3_2_task() {
	if (mode == MODE3) {
	// DISPLAY CONFIG GREEN
		switch (statusMODE3_2) {
			case INIT:
				statusMODE3_2 = HIGH_DIGIT;
				break;
			case HIGH_DIGIT:
				statusMODE3_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME GREEN: ");
				lcd_send_int(AUTO_GREEN);
				break;
			case LOW_DIGIT:
				statusMODE3_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME GREEN: ");
				lcd_send_int(AUTO_GREEN);
				break;
			default:
				break;
		}
	}
}

void manMODE3_3_task() {
	if (mode == MODE3) {
			// Change time for mode
			switch (statusMODE3_3) {
			case INIT:
				if (isButtonPressed(BUTTON3) == 1) {
					statusMODE3_3 = INCREASE;
					AUTO_GREEN++;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON3) == 1) {
					AUTO_GREEN += 1;
					if (AUTO_GREEN > UPPER_BOUND)
						AUTO_GREEN = UPPER_BOUND;
				}
				if (isButtonPressed(BUTTON3) == 1) {
					statusMODE3_3 = SAVE;
				}
				break;
			case DECREASE:
				if (isButtonPressed(BUTTON4) == 1) {
					AUTO_GREEN -= 1;
					if (AUTO_GREEN < LOWER_BOUND) {
						AUTO_GREEN = LOWER_BOUND;
					}
				}
				if (isButtonPressed(BUTTON2) == 1) {
					statusMODE2_3 = SAVE;
				}
				break;

			case SAVE:
				if (AUTO_RED != (AUTO_GREEN + AUTO_YELLOW)) {
					time_traffic_base();
				}
				mode = MODE1;
				initVar();
				break;
			default:
				break;
			}

			// Continue to MODE3
			if (isButtonPressed(BUTTON1) == 1) {
				mode = MODE4;
			}
	}
}

// CONFIG YELLOW
void manMODE4_1_task() {
	if (mode == MODE4) {
		// Blinked LED
		switch (statusMODE4_1) {
			case INIT:
				statusMODE4_1 = TOGGLE;
				break;
			case TOGGLE:
				toggleYELLOW1();
				toggleYELLOW2();
				break;
			default:
				break;
		}
	}
}

void manMODE4_2_task() {
	if (mode == MODE4) {
	// DISPLAY CONFIG RED
		switch (statusMODE4_2) {
			case INIT:
				statusMODE4_2 = HIGH_DIGIT;
				break;
			case HIGH_DIGIT:
				statusMODE4_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME YELLOW: ");
				lcd_send_int(AUTO_YELLOW);
				break;
			case LOW_DIGIT:
				statusMODE4_2 = LOW_DIGIT;
				lcd_goto_XY(1, 0);
				lcd_send_string("TIME YELLOW: ");
				lcd_send_int(AUTO_YELLOW);
				break;
			default:
				break;
		}
	}
}

void manMODE4_3_task() {
	if (mode == MODE4) {
			// Change time for mode
			switch (statusMODE4_3) {
			case INIT:
				if (isButtonPressed(BUTTON3) == 1) {
					statusMODE4_3 = INCREASE;
					AUTO_YELLOW++;
				}
				break;
			case INCREASE:
				if (isButtonPressed(BUTTON3) == 1) {
					AUTO_YELLOW += 1;
					if (AUTO_YELLOW > UPPER_BOUND)
						AUTO_YELLOW = UPPER_BOUND;
				}
				if (isButtonPressed(BUTTON2) == 1) {
					statusMODE4_3 = SAVE;
				}
				break;
			case DECREASE:
				if (isButtonPressed(BUTTON4) == 1) {
					AUTO_YELLOW -= 1;
					if (AUTO_YELLOW < LOWER_BOUND) {
						AUTO_YELLOW = LOWER_BOUND;
					}
				}
				if (isButtonPressed(BUTTON2) == 1) {
					statusMODE2_3 = SAVE;
				}
				break;
			case SAVE:
				if (AUTO_RED != (AUTO_GREEN + AUTO_YELLOW)) {
					time_traffic_base();
				}
				mode = MODE1;
				initVar();
				break;
			default:
				break;
			}

			// Continue to MODE
			if (isButtonPressed(BUTTON1) == 1) {
				mode = MODE1;
				lcd_clear_display();
				if (AUTO_RED != (AUTO_GREEN + AUTO_YELLOW)) {
					time_traffic_base();
				}
			}
	}
}
