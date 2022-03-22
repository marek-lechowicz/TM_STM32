/*
 * one_wire_lib.h
 *
 *  Created on: Jan 5, 2022
 *      Author: mlech
 */

#ifndef INC_ONE_WIRE_LIB_H_
#define INC_ONE_WIRE_LIB_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

void delay_us(uint32_t us);
HAL_StatusTypeDef wire_reset(void);
void write_bit(int value);
int read_bit(void);
void wire_write(uint8_t byte);
uint8_t wire_read(void);
uint8_t byte_crc(uint8_t crc, uint8_t byte);
uint8_t wire_crc(const uint8_t* data, int len);

#endif /* INC_ONE_WIRE_LIB_H_ */
