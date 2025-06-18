/*
 * Flash.h
 *
 *  Created on: Jun 18, 2025
 *      Author: NCPC
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include <stdint.h>
#include "stm32f4xx.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t GetSector(uint32_t Address);
void Flash_Unlock(void);
void Flash_Lock(void);
void Flash_SectorErase(uint32_t address);
void Flash_WriteWord(uint32_t Address, uint32_t Data);
void Flash_Write_Data(uint32_t Address, uint32_t *Data, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* INC_FLASH_H_ */
