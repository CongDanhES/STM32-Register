#include "Flash.h"
#include "stm32f4xx.h"  // Direct register definitions

uint32_t GetSector(uint32_t Address)
{
    if((Address >= 0x08000000) && (Address < 0x08004000)) return 0;
    else if((Address < 0x08008000)) return 1;
    else if((Address < 0x0800C000)) return 2;
    else if((Address < 0x08010000)) return 3;
    else if((Address < 0x08020000)) return 4;
    else if((Address < 0x08040000)) return 5;
    else if((Address < 0x08060000)) return 6;
    else if((Address < 0x08080000)) return 7;
    else return 0; // Invalid, fallback to sector 0
}

void Flash_Unlock(void)
{
    if (FLASH->CR & FLASH_CR_LOCK)
    {
        FLASH->KEYR = 0x45670123;
        FLASH->KEYR = 0xCDEF89AB;
    }
}

void Flash_Lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK;
}

void Flash_SectorErase(uint32_t Address)
{
    uint32_t sector = GetSector(Address);

    while (FLASH->SR & FLASH_SR_BSY);

    Flash_Unlock();

    FLASH->CR &= ~FLASH_CR_SNB;
    FLASH->CR |= (sector << FLASH_CR_SNB_Pos);
    FLASH->CR |= FLASH_CR_SER;
    FLASH->CR |= FLASH_CR_STRT;

    while (FLASH->SR & FLASH_SR_BSY);

    FLASH->CR &= ~FLASH_CR_SER;
    Flash_Lock();
}

void Flash_WriteWord(uint32_t Address, uint32_t Data)
{
    while (FLASH->SR & FLASH_SR_BSY);

    Flash_Unlock();

    FLASH->CR &= ~FLASH_CR_PSIZE;
    FLASH->CR |= FLASH_CR_PSIZE_1;  // 32-bit program
    FLASH->CR |= FLASH_CR_PG;

    *(volatile uint32_t*)Address = Data;

    while (FLASH->SR & FLASH_SR_BSY);

    FLASH->CR &= ~FLASH_CR_PG;
    Flash_Lock();
}

void Flash_Write_Data(uint32_t Address, uint32_t* Data, uint16_t size)
{
    for (uint16_t i = 0; i < size; ++i)
    {
        Flash_WriteWord(Address + i * 4, Data[i]);
    }
}
