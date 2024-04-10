/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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
#define LeftButton_Pin GPIO_PIN_2
#define LeftButton_GPIO_Port GPIOF
#define Right_Button_Pin GPIO_PIN_3
#define Right_Button_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_11
#define LED2_GPIO_Port GPIOF
#define LED3_Pin GPIO_PIN_14
#define LED3_GPIO_Port GPIOF
#define RST_Pin GPIO_PIN_6
#define RST_GPIO_Port GPIOC
#define D_C_Pin GPIO_PIN_8
#define D_C_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */
#define I2C1_SCL_GPIO_PORT GPIOB
#define I2C1_SCL_PIN 6
#define I2C1_SDA_GPIO_PORT GPIOB
#define I2C1_SDA_PIN 7

#define SPI5_NSS_GPIO_Port GPIOF
#define SPI5_NSS_Pin 6
#define SPI5_SCK_GPIO_Port GPIOF
#define SPI5_SCK_Pin 7
#define SPI5_MOSI_GPIO_Port GPIOF
#define SPI5_MOSI_Pin 9

#define INT16_TO_FLOAT (1.0f / (32768.0f))
#define FLOAT_TO_INT16 (32768.0f)

#define AUDIOFX_SAMPLING_RATE 	48000.0f
#define AUDIOFX_BUFF_SIZE	 	4096
#define AUDIOFX_MAX_CHAIN 		5
#define AUDIOFX_CNTR_SIZE		400
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
