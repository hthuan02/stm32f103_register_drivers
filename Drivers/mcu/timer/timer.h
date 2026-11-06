/*
 * timer.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */


#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include "../../../Inc/stm32_timer.h"

void timer2_init(void);
void delay_ms(uint32_t ms);

#endif  /* TIMER_H_ */
