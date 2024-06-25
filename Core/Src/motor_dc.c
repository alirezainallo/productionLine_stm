#include "motor_dc.h"

void motor_dc_init (void)
{
	HAL_TIM_PWM_Start(&htim8, MOTOR_A);
	__HAL_TIM_SET_COMPARE(&htim8, MOTOR_A, 101);
	motor_dc_set_status(MOTOR_A, DIR_RIGHT);
	HAL_TIM_PWM_Start(&htim8, MOTOR_B);
	__HAL_TIM_SET_COMPARE(&htim8, MOTOR_B, 101);
	motor_dc_set_status(MOTOR_B, DIR_RIGHT);
}
void motor_dc_set_pf (dc_motor_name_t motor_name, uint8_t pf)
{
	__HAL_TIM_SET_COMPARE(&htim8, (uint32_t)motor_name, (pf + 1));  //35-101  naheye car hastesh :)
}
uint32_t motor_dc_get_pf (dc_motor_name_t motor_name)  //for asking pf
{
	return (__HAL_TIM_GET_COMPARE(&htim8, (uint32_t)motor_name) - 1);
}
void motor_dc_set_status (dc_motor_name_t motor_name, dc_motor_status_t dir)
{
	switch(dir)
	{
		case DIR_RIGHT:
				switch(motor_name)
				{
					case MOTOR_A:
						HAL_GPIO_WritePin(MOTOR_A_S2_GPIO_Port, MOTOR_A_S2_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_A_S1_GPIO_Port, MOTOR_A_S1_Pin, GPIO_PIN_SET);
					break;
					case MOTOR_B:
						HAL_GPIO_WritePin(MOTOR_B_S2_GPIO_Port, MOTOR_B_S2_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_B_S1_GPIO_Port, MOTOR_B_S1_Pin, GPIO_PIN_SET);
					break;
					default:
					break;
				}
		break;
				
		case DIR_LEFT:
				switch(motor_name)
				{
					case MOTOR_A:
						HAL_GPIO_WritePin(MOTOR_A_S1_GPIO_Port, MOTOR_A_S1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_A_S2_GPIO_Port, MOTOR_A_S2_Pin, GPIO_PIN_SET);
					break;
					case MOTOR_B:
						HAL_GPIO_WritePin(MOTOR_B_S1_GPIO_Port, MOTOR_B_S1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_B_S2_GPIO_Port, MOTOR_B_S2_Pin, GPIO_PIN_SET);
					break;
					default:
					break;
				}
		break;
				
		case DIR_STOP:
				switch(motor_name)
				{
					case MOTOR_A:
						HAL_GPIO_WritePin(MOTOR_A_S1_GPIO_Port, MOTOR_A_S1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_A_S2_GPIO_Port, MOTOR_A_S2_Pin, GPIO_PIN_SET);
					break;
					case MOTOR_B:
						HAL_GPIO_WritePin(MOTOR_B_S1_GPIO_Port, MOTOR_B_S1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(MOTOR_B_S2_GPIO_Port, MOTOR_B_S2_Pin, GPIO_PIN_SET);
					break;
					default:
					break;
				}
		break;
				
		case DIR_IDLE:
				switch(motor_name)
				{
					case MOTOR_A:
						HAL_GPIO_WritePin(MOTOR_A_S1_GPIO_Port, MOTOR_A_S1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_A_S2_GPIO_Port, MOTOR_A_S2_Pin, GPIO_PIN_RESET);
					break;
					case MOTOR_B:
						HAL_GPIO_WritePin(MOTOR_B_S1_GPIO_Port, MOTOR_B_S1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(MOTOR_B_S2_GPIO_Port, MOTOR_B_S2_Pin, GPIO_PIN_RESET);
					break;
					default:
					break;
				}
		break;		
		default:
		break;
	}
	
}
