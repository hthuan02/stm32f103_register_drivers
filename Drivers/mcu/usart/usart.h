/*
 * usart.h
 *
 *  Created on: Oct 30, 2026
 *      Author: huynhthuan
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>						/* Thư viện dùng kiểu dữ liệu định nghĩa sẵn */
#include <stddef.h>						/* Thư viện định nghĩa NULL */
#include "../../../Inc/stm32_usart.h"

/**
 *  @brief USART function prototype
 */
void usart2_init (void);
void usart2_frame_config (void);

/* Transmit & Receive char */
void usart2_transmit_char(uint32_t data);
uint32_t usart2_receive_char(void);

/* Transmit & Receive string */
void usart2_transmit_string(const char *str);

#endif /* USART_H_ */
