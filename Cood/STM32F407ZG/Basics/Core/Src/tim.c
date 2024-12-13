/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.c
 * @brief   This file provides code for the configuration
 *          of the TIM instances.
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
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim9;

/* TIM7 init function */
void MX_TIM7_Init(void)
{

	/* USER CODE BEGIN TIM7_Init 0 */

	/* USER CODE END TIM7_Init 0 */

	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM7_Init 1 */

	/* USER CODE END TIM7_Init 1 */
	htim7.Instance = TIM7;
	htim7.Init.Prescaler = 84 - 1;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = 1;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM7_Init 2 */

	/* USER CODE END TIM7_Init 2 */
}
/* TIM9 init function */
void MX_TIM9_Init(void)
{

	/* USER CODE BEGIN TIM9_Init 0 */

	/* USER CODE END TIM9_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};

	/* USER CODE BEGIN TIM9_Init 1 */

	/* USER CODE END TIM9_Init 1 */
	htim9.Instance = TIM9;
	htim9.Init.Prescaler = 84 - 1;
	htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim9.Init.Period = 50000 - 1;
	htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim9.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim9) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim9, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM9_Init 2 */

	/* USER CODE END TIM9_Init 2 */
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *tim_baseHandle)
{

	if (tim_baseHandle->Instance == TIM7)
	{
		/* USER CODE BEGIN TIM7_MspInit 0 */

		/* USER CODE END TIM7_MspInit 0 */
		/* TIM7 clock enable */
		__HAL_RCC_TIM7_CLK_ENABLE();
		/* USER CODE BEGIN TIM7_MspInit 1 */

		/* USER CODE END TIM7_MspInit 1 */
	}
	else if (tim_baseHandle->Instance == TIM9)
	{
		/* USER CODE BEGIN TIM9_MspInit 0 */

		/* USER CODE END TIM9_MspInit 0 */
		/* TIM9 clock enable */
		__HAL_RCC_TIM9_CLK_ENABLE();

		/* TIM9 interrupt Init */
		HAL_NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, 6, 0);
		HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
		/* USER CODE BEGIN TIM9_MspInit 1 */

		/* USER CODE END TIM9_MspInit 1 */
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *tim_baseHandle)
{

	if (tim_baseHandle->Instance == TIM7)
	{
		/* USER CODE BEGIN TIM7_MspDeInit 0 */

		/* USER CODE END TIM7_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM7_CLK_DISABLE();
		/* USER CODE BEGIN TIM7_MspDeInit 1 */

		/* USER CODE END TIM7_MspDeInit 1 */
	}
	else if (tim_baseHandle->Instance == TIM9)
	{
		/* USER CODE BEGIN TIM9_MspDeInit 0 */

		/* USER CODE END TIM9_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM9_CLK_DISABLE();

		/* TIM9 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM1_BRK_TIM9_IRQn);
		/* USER CODE BEGIN TIM9_MspDeInit 1 */

		/* USER CODE END TIM9_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */
void delay_us(uint16_t us)
{
	uint16_t differ = 0xffff - us - 5;

	HAL_TIM_Base_Start(&htim7);
	__HAL_TIM_SetCounter(&htim7, differ);
	while (differ < 0xffff - 5)
	{
		differ = __HAL_TIM_GetCounter(&htim7);
	}
	HAL_TIM_Base_Stop(&htim7);

	// __HAL_TIM_SET_COUNTER(&htim7, 0);
	// __HAL_TIM_ENABLE(&htim7);
	// while (__HAL_TIM_GET_COUNTER(&htim7) < us)
	// {
	// }
	// __HAL_TIM_DISABLE(&htim7);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM7) // 1us
	{
	}
	if (htim->Instance == TIM9) // 50ms
	{
	}
}

/* USER CODE END 1 */
