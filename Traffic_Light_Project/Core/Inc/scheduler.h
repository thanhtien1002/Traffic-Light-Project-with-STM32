#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include <stdint.h>

#define SCH_MAX_TASKS    40
#define NO_TASK_ID       0
#define TICK_MS          10

typedef struct {
	void (*pTask)(void);      // Con trỏ tới hàm nhiệm vụ
	uint32_t Delay;           // Thời gian chờ trước khi chạy nhiệm vụ
	uint32_t Period;          // Chu kỳ của nhiệm vụ (0 nếu không định kỳ)
	uint8_t Runme;            // Cờ để đánh dấu nhiệm vụ cần chạy
	uint8_t TaskID;           // ID của nhiệm vụ (có thể sử dụng nếu cần)
} sTask;

void SCH_Init(void);
void SCH_Delete_Task(const uint8_t TASK_INDEX);
uint8_t SCH_Add_Task(void (*pFunction)(void), const uint32_t DELAY,
		const uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */
