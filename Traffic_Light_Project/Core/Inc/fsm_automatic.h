/*
 * fsm_automatic.h
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"
#include "global.h"
#include "scheduler.h"

void fsm_automatic(void);
void autoMODE1_task(void);
void autoMODE2_task(void);
void autoMODE3_task(void);
void autoMODE4_task(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
