/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW0_Pin GPIO_PIN_4
#define SW0_GPIO_Port GPIOE
#define SW1_Pin GPIO_PIN_5
#define SW1_GPIO_Port GPIOE
#define SW2_Pin GPIO_PIN_6
#define SW2_GPIO_Port GPIOE
#define LED0_Pin GPIO_PIN_13
#define LED0_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_14
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_15
#define LED2_GPIO_Port GPIOC
#define KEYPAD_R0_Pin GPIO_PIN_9
#define KEYPAD_R0_GPIO_Port GPIOE
#define KEYPAD_C0_Pin GPIO_PIN_10
#define KEYPAD_C0_GPIO_Port GPIOE
#define KEYPAD_R1_Pin GPIO_PIN_11
#define KEYPAD_R1_GPIO_Port GPIOE
#define KEYPAD_C1_Pin GPIO_PIN_12
#define KEYPAD_C1_GPIO_Port GPIOE
#define KEYPAD_R2_Pin GPIO_PIN_13
#define KEYPAD_R2_GPIO_Port GPIOE
#define KEYPAD_C2_Pin GPIO_PIN_14
#define KEYPAD_C2_GPIO_Port GPIOE
#define KEYPAD_R3_Pin GPIO_PIN_15
#define KEYPAD_R3_GPIO_Port GPIOE
#define KEYPAD_C3_Pin GPIO_PIN_10
#define KEYPAD_C3_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_10
#define LCD_RW_GPIO_Port GPIOD
#define LCD_RS_Pin GPIO_PIN_11
#define LCD_RS_GPIO_Port GPIOD
#define LCD_D7_Pin GPIO_PIN_12
#define LCD_D7_GPIO_Port GPIOD
#define LCD_D6_Pin GPIO_PIN_13
#define LCD_D6_GPIO_Port GPIOD
#define LCD_D5_Pin GPIO_PIN_14
#define LCD_D5_GPIO_Port GPIOD
#define LCD_D4_Pin GPIO_PIN_15
#define LCD_D4_GPIO_Port GPIOD
#define MOTOR_A_Pin GPIO_PIN_6
#define MOTOR_A_GPIO_Port GPIOC
#define MOTOR_B_Pin GPIO_PIN_7
#define MOTOR_B_GPIO_Port GPIOC
#define MOTOR_A_S1_Pin GPIO_PIN_8
#define MOTOR_A_S1_GPIO_Port GPIOC
#define MOTOR_A_S2_Pin GPIO_PIN_9
#define MOTOR_A_S2_GPIO_Port GPIOC
#define MOTOR_B_S1_Pin GPIO_PIN_8
#define MOTOR_B_S1_GPIO_Port GPIOA
#define MOTOR_B_S2_Pin GPIO_PIN_9
#define MOTOR_B_S2_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_7
#define LCD_EN_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
