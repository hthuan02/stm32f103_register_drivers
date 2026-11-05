/*
 * timer.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */


#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include "../../../Inc/stm32_timer.h"

void timer2_init(void);
void delay_ms(uint32_t ms);

#endif  /* TIMER_H */ 
