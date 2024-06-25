/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD.h"
#include "keypad_4x4.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "motor_dc.h"
#include "menu.h"
#include "eeprom.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticQueue_t osStaticMessageQDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for DesplayTask */
osThreadId_t DesplayTaskHandle;
uint32_t StartTaskBuffer[ 128 ];
osStaticThreadDef_t StartTaskControlBlock;
const osThreadAttr_t DesplayTask_attributes = {
  .name = "DesplayTask",
  .cb_mem = &StartTaskControlBlock,
  .cb_size = sizeof(StartTaskControlBlock),
  .stack_mem = &StartTaskBuffer[0],
  .stack_size = sizeof(StartTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for KeypadTask */
osThreadId_t KeypadTaskHandle;
uint32_t KeypadTaskBuffer[ 128 ];
osStaticThreadDef_t KeypadTaskControlBlock;
const osThreadAttr_t KeypadTask_attributes = {
  .name = "KeypadTask",
  .cb_mem = &KeypadTaskControlBlock,
  .cb_size = sizeof(KeypadTaskControlBlock),
  .stack_mem = &KeypadTaskBuffer[0],
  .stack_size = sizeof(KeypadTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for SensorTask */
osThreadId_t SensorTaskHandle;
uint32_t SensorTaskBuffer[ 128 ];
osStaticThreadDef_t SensorTaskControlBlock;
const osThreadAttr_t SensorTask_attributes = {
  .name = "SensorTask",
  .cb_mem = &SensorTaskControlBlock,
  .cb_size = sizeof(SensorTaskControlBlock),
  .stack_mem = &SensorTaskBuffer[0],
  .stack_size = sizeof(SensorTaskBuffer),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for lcdQueue */
osMessageQueueId_t lcdQueueHandle;
uint8_t lcdQueueBuffer[ 16 * 12 ];
osStaticMessageQDef_t lcdQueueControlBlock;
const osMessageQueueAttr_t lcdQueue_attributes = {
  .name = "lcdQueue",
  .cb_mem = &lcdQueueControlBlock,
  .cb_size = sizeof(lcdQueueControlBlock),
  .mq_mem = &lcdQueueBuffer,
  .mq_size = sizeof(lcdQueueBuffer)
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void DesplayDefaultTask(void *argument);
void KeypadDefaultTask(void *argument);
void SensorDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of lcdQueue */
  lcdQueueHandle = osMessageQueueNew (16, 12, &lcdQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of DesplayTask */
  DesplayTaskHandle = osThreadNew(DesplayDefaultTask, NULL, &DesplayTask_attributes);


  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_DesplayDefaultTask */
/**
  * @brief  Function implementing the DesplayTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_DesplayDefaultTask */
void DesplayDefaultTask(void *argument)
{
  /* USER CODE BEGIN DesplayDefaultTask */
	
	menu_MessageQueue_t RecQueMes = {0};

	
	LCD_Init();
	osDelay(2);
	menu_init();
	menu_page_init(MENU_MAIN_PAGE);
	
  /* creation of KeypadTask */
  KeypadTaskHandle = osThreadNew(KeypadDefaultTask, NULL, &KeypadTask_attributes);
	
  /* Infinite loop */
  while(1)
  {
		
		osMessageQueueGet(lcdQueueHandle, &RecQueMes, 0, osWaitForever);
    // LastQueMes = &RecQueMes;
		menu_process(&RecQueMes);
		
    //osDelay(100);
  }
  /* USER CODE END DesplayDefaultTask */
}

/* USER CODE BEGIN Header_KeypadDefaultTask */
/**
* @brief Function implementing the KeypadTask thread.
* @param argument: Not used
* @retval None
*/



/* USER CODE END Header_KeypadDefaultTask */
void KeypadDefaultTask(void *argument)
{
  /* USER CODE BEGIN KeypadDefaultTask */



//	LastQueMes = &TrsQueMes;
	
	
	keypad_init(FALLING_EDGE);
	
	/* creation of SensorTask */
  SensorTaskHandle = osThreadNew(SensorDefaultTask, NULL, &SensorTask_attributes);
	
	osDelay(100);
	
	/* Infinite loop */
  while(1)
  {
		keypad_process();
		
		
		static uint8_t hart_beat = 0;
		if(hart_beat++ >= 5)
		{
			hart_beat = 0;
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		}
    osDelay(100);
  }
  /* USER CODE END KeypadDefaultTask */
}

/* USER CODE BEGIN Header_SensorDefaultTask */
/**
* @brief Function implementing the SensorTask thread.
* @param argument: Not used
* @retval None
*/
menu_MessageQueue_t TrsQueMes;
/* USER CODE END Header_SensorDefaultTask */
void SensorDefaultTask(void *argument)
{
  /* USER CODE BEGIN SensorDefaultTask */
	TrsQueMes.current_PF = motor_dc_get_pf(MOTOR_A);
	TrsQueMes.product_num = 0;

	motor_dc_init();
	osDelay(100);

  /* Infinite loop */
  while(1)
  {
		
		if(need_res_prod_num)
		{
			need_res_prod_num = 0;
			TrsQueMes.product_num = 0;
		}

		if(HAL_GPIO_ReadPin(SW0_GPIO_Port, SW0_Pin) == GPIO_PIN_RESET) //por shod sensor :)
		{
			TrsQueMes.rq_status = CH_PRODUCT_NUM;
			TrsQueMes.product_num++;
			osMessageQueuePut(lcdQueueHandle, &TrsQueMes, NULL, 50);
			
			
			motor_dc_set_status(MOTOR_B, DIR_STOP);
			osDelay(200);
			motor_dc_set_status(MOTOR_A, DIR_RIGHT);
		
		}
		else if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_RESET) //resid sensor :)
		{		
			motor_dc_set_status(MOTOR_A, DIR_STOP);
			osDelay(200);
			motor_dc_set_status(MOTOR_B, DIR_RIGHT);
			
		}
		else if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin) == GPIO_PIN_RESET) //debug :)
		{
			//osDelay(100);
		}
		else
		{
		}
		
    osDelay(100);
  }
  /* USER CODE END SensorDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

