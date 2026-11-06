/*
 * i2c.h
 *
 *  Created on: Nov 5, 2026
 *      Author: huynhthuan
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "stm32_i2c.h"

void i2c_pins_init(void);
void i2c_config(void);

void i2c_start(void);
void i2c_stop(void);
void i2c_write_address (uint8_t data_bit, uint8_t rw_bit);
void i2c_write_data(uint8_t data);
uint8_t i2c_read_data (void);

#endif /* I2C_H_ */
