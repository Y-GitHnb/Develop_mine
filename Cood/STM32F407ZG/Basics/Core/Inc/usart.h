/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usart.h
 * @brief   This file contains all the function prototypes for
 *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

	/* USER CODE BEGIN Includes */

	/* USER CODE END Includes */

	extern UART_HandleTypeDef huart1;

	extern UART_HandleTypeDef huart2;

	/* USER CODE BEGIN Private defines */

	extern UART_HandleTypeDef *current_huart;

#define printf_usart1(...)       \
	do                           \
	{                            \
		current_huart = &huart1; \
		printf(__VA_ARGS__);     \
	} while (0)

#define printf_usart2(...)       \
	do                           \
	{                            \
		current_huart = &huart2; \
		printf(__VA_ARGS__);     \
	} while (0)

#define REC_LENGTH 1
#define UART_TX_COUNT 64
#define UART_Rx_COUNT 200

	typedef struct
	{
		uint8_t rx_data;				/* ֡���ջ��� */
		uint8_t rx_buf[UART_Rx_COUNT];	/* ֡�������� */
		uint8_t collect[UART_Rx_COUNT]; /* �������� */
		struct
		{
			uint16_t len : 15;	/* ֡���ճ��ȣ�sta[14:0] */
			uint16_t finsh : 1; /* ֡������ɱ�־��sta[15] */
		} sta;					/* ֡״̬��Ϣ */

		uint8_t tx_buf[UART_TX_COUNT]; /* ֡���ͻ��� */
	} usart_frame;					   /* UART ֡������Ϣ�ṹ�� */

	extern usart_frame uart1_rx_frame;
	extern usart_frame uart2_rx_frame;

	/* USER CODE END Private defines */

	void MX_USART1_UART_Init(void);
	void MX_USART2_UART_Init(void);

	/* USER CODE BEGIN Prototypes */

	/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */
