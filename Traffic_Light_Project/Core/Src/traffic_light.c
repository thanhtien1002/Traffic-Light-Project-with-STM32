/*
 * traffic_light.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */
#include "main.h"
#include "traffic_light.h"
#include "scheduler.h"

uint8_t redState1 = 0;     // 0: ON, 1: OFF
uint8_t yellowState1 = 0;  // 0: ON, 1: OFF
uint8_t greenState1 = 0;   // 0: ON, 1: OFF
uint8_t redState2 = 1;     // 0: ON, 1: OFF
uint8_t yellowState2 = 1;  // 0: ON, 1: OFF
uint8_t greenState2 = 1;   // 0: ON, 1: OFF

void enableRed1(){
	HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, SET);
	HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, SET);
}

void enableYellow1(){
	HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, SET);
	HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, RESET);
}
void enableGreen1(){
	HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, RESET);
	HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, SET);
}

void enableRed2(){
	HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, SET);
	HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, SET);
}

void enableYellow2(){
	HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, SET);
	HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, RESET);
}
void enableGreen2(){
	HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, RESET);
	HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, SET);
}

void enableRed3(){
	HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, SET);
	HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, SET);
}

void enableYellow3(){
	HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, SET);
	HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, RESET);
}
void enableGreen3(){
	HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, RESET);
	HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, SET);
}

void enableRed4(){
	HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, SET);
	HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, SET);
}

void enableYellow4(){
	HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, SET);
	HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, RESET);
}
void enableGreen4(){
	HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, RESET);
	HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, SET);
}


void toggleRED1(){
	if (redState1 == 0) {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, SET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, SET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, SET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, SET);
		redState1 = 1;
	}
	else {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, RESET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, RESET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, RESET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, RESET);
		redState1 = 0;
	}
}

void toggleRED2(){
	if (redState2 == 0) {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, SET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, SET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, SET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, SET);
		redState2 = 1;
	}
	else {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, RESET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, RESET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, RESET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, RESET);
		redState2 = 0;
	}
}


void toggleGREEN1(){
	if (greenState1 == 0) {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, RESET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, SET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, RESET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, SET);
		greenState1 = 1;
	}
	else {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, RESET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, RESET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, RESET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, RESET);
		greenState1 = 0;
	}
}

void toggleGREEN2(){
	if (greenState2 == 0) {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, RESET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, SET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, RESET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, SET);
		greenState2 = 1;
	}
	else {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, RESET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, RESET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, RESET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, RESET);
		greenState2 = 0;
	}
}


void toggleYELLOW1(){
	if (yellowState1 == 0) {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, SET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, RESET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, SET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, RESET);
		yellowState1 = 1;
	}
	else {
		HAL_GPIO_WritePin(R1A_GPIO_Port, R1A_Pin, RESET);
		HAL_GPIO_WritePin(R1B_GPIO_Port, R1B_Pin, RESET);
		HAL_GPIO_WritePin(R3A_GPIO_Port, R3A_Pin, RESET);
		HAL_GPIO_WritePin(R3B_GPIO_Port, R3B_Pin, RESET);
		yellowState1 = 0;
	}
}

void toggleYELLOW2(){
	if (yellowState2 == 0) {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, SET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, RESET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, SET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, RESET);
		yellowState2 = 1;
	}
	else {
		HAL_GPIO_WritePin(R2A_GPIO_Port, R2A_Pin, RESET);
		HAL_GPIO_WritePin(R2B_GPIO_Port, R2B_Pin, RESET);
		HAL_GPIO_WritePin(R4A_GPIO_Port, R4A_Pin, RESET);
		HAL_GPIO_WritePin(R4B_GPIO_Port, R4B_Pin, RESET);
		yellowState2 = 0;
	}
}
