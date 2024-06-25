#include "myhalflash.h"
#include "eeprom.h"


void hal_eeprom_init (void)
{
	HAL_FLASH_Unlock();
}
HAL_StatusTypeDef FLASH_EraseSector(uint8_t page_id, uint8_t voltage_range)
{
	uint32_t SectorError;
	HAL_StatusTypeDef out_res;
	FLASH_EraseInitTypeDef infoToErase;
	infoToErase.Banks        = FLASH_BANK_1;
	infoToErase.NbSectors    = 1;
	infoToErase.Sector       = page_id;
	infoToErase.TypeErase    = FLASH_TYPEERASE_SECTORS;
	infoToErase.VoltageRange = voltage_range;
	
	out_res = HAL_FLASHEx_Erase(&infoToErase, &SectorError);
	
	return out_res;
}
HAL_StatusTypeDef FLASH_ProgramHalfWord(uint32_t pAddress, uint16_t data)
{
	HAL_StatusTypeDef out_res;
	
	out_res = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, pAddress, (uint64_t)data);
	
	return out_res;
}
