#ifndef _MYHALFLASH_H
#define _MYHALFLASH_H

#include "stm32f4xx_hal.h"

void hal_eeprom_init (void);
HAL_StatusTypeDef FLASH_EraseSector(uint8_t page_id, uint8_t voltage_range);
HAL_StatusTypeDef FLASH_ProgramHalfWord(uint32_t pAddress, uint16_t data);

#endif //_MYHALFLASH_H
