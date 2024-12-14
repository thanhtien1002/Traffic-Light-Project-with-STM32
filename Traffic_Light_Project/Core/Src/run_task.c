/*
 * run_task.c
 *
 *  Created on: Dec 8, 2024
 *      Author: ASUS
 */

#include "run_task.h"

void run_task() {
	initWaitingTime();
	initVar();
	SCH_Init();

	SCH_Add_Task(autoMODE1_task, 10, 1000);
	SCH_Add_Task(autoMODE2_task, 20, 1000);
	SCH_Add_Task(autoMODE3_task, 30, 1000);
	SCH_Add_Task(autoMODE4_task, 40, 1000);
	SCH_Add_Task(manMODE2_1_task, 50, 500);
	SCH_Add_Task(manMODE2_2_task, 1000, 100);
	SCH_Add_Task(manMODE2_3_task, 60, 100);
	SCH_Add_Task(manMODE3_1_task, 70, 500);
	SCH_Add_Task(manMODE3_2_task, 1000, 100);
	SCH_Add_Task(manMODE3_3_task, 80, 100);
	SCH_Add_Task(manMODE4_1_task, 90, 500);
	SCH_Add_Task(manMODE4_2_task, 1000, 100);
	SCH_Add_Task(manMODE4_3_task, 100, 100);
	SCH_Add_Task(getKeyInput, 30, 20);
}
