#include "time_out.h"

uint8_t timeout_is_ok (uint32_t ms, time_out_enum_t func)
{
	static uint32_t last_time[MAX_TIMEOUT_NEED] = {0, 0};
	if((ms + last_time[func]) <= HAL_GetTick())
	{
		last_time[func] = HAL_GetTick();
		return 1;
	}
	else
	{
		return 0;
	}
}
