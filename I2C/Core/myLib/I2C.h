/*
 * I2C.h
 *
 *  Created on: Apr 9, 2025
 *      Author: NCPC
 */

#include "stdint.h"

#ifndef MYLIB_I2C_H_
#define MYLIB_I2C_H_

struct {
	uint32_t	I2C_CR1;
	uint32_t	I2C_CR2;
	uint32_t	I2C_OAR1;
	uint32_t	I2C_OAR2;
	uint32_t	I2C_DR;
	uint32_t	I2C_SR1;
	uint32_t	I2C_SR2;
	uint32_t	I2C_CCR;
	uint32_t	I2C_TRISE;
	uint32_t	I2C_FLTR;
}myI2C;

#define I2C1_BASE	0x40005400
#define I2C1		((myI2C*) I2C1_BASE)

#define I2C2_BASE	0x40005800
#define I2C2		((myI2C*) I2C2_BASE)



#endif /* MYLIB_I2C_H_ */
