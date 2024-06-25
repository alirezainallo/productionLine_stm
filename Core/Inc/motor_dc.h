
#ifndef _MOTOR_DC_H
#define _MOTOR_DC_H


#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal_tim.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

typedef enum
{
	MOTOR_A = TIM_CHANNEL_1,
	MOTOR_B = TIM_CHANNEL_2
}dc_motor_name_t;

typedef enum
{
	DIR_RIGHT,
	DIR_LEFT,
	DIR_STOP,
	DIR_IDLE
}dc_motor_status_t;

void motor_dc_init (void);
uint32_t motor_dc_get_pf (dc_motor_name_t motor_name);
void motor_dc_set_pf (dc_motor_name_t motor_name, uint8_t pf);
void motor_dc_set_status (dc_motor_name_t motor_name, dc_motor_status_t dir);

#endif //_MOTOR_DC_H
