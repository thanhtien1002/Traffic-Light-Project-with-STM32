#include "scheduler.h"

static sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {
	for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
}


uint8_t SCH_Add_Task(void (*pFunction)(void), const uint32_t DELAY,
		const uint32_t PERIOD) {
	uint8_t index = 0;
	while ((index < SCH_MAX_TASKS) && (SCH_tasks_G[index].pTask != 0)) {
		index++;
	}

	if (index == SCH_MAX_TASKS) {
		return 0;
	}

	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY / TICK_MS;
	SCH_tasks_G[index].Period = (PERIOD > 0) ? (PERIOD / TICK_MS) : 0;
	SCH_tasks_G[index].Runme = 0;
	SCH_tasks_G[index].TaskID = index + 1;

	return 1;
}

void SCH_Delete_Task(const uint8_t TASK_INDEX) {
	if (TASK_INDEX < SCH_MAX_TASKS) {
		SCH_tasks_G[TASK_INDEX].pTask = 0;
		SCH_tasks_G[TASK_INDEX].Delay = 0;
		SCH_tasks_G[TASK_INDEX].Period = 0;
		SCH_tasks_G[TASK_INDEX].Runme = 0;
		SCH_tasks_G[TASK_INDEX].TaskID = 0;
	}
}

void SCH_Update(void) {
	for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].pTask != 0) {
			if (SCH_tasks_G[index].Delay > 0) {
				SCH_tasks_G[index].Delay--;
			} else {
				SCH_tasks_G[index].Runme = 1;
				if (SCH_tasks_G[index].Period > 0) {
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period; // Reset delay cho nhiệm vụ định kỳ
				}
			}
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].Runme > 0) {
			SCH_tasks_G[index].Runme--; // Reset cờ Runme


			if (SCH_tasks_G[index].pTask) {
				(*SCH_tasks_G[index].pTask)();
			}

			if (SCH_tasks_G[index].Period == 0) {
				SCH_Delete_Task(index);
			}
		}
	}
}
