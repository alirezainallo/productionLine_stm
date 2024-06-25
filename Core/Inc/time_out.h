
#ifndef __TIME_OUT_H
#define __TIME_OUT_H

#include "main.h"

#define MAX_TIMEOUT_NEED 4


typedef enum time_out_enum_tag
{
	JOY_FUNC,
	KEY_FUNC,
	BLINK_FUNC,
	HEART_BEAT,
}time_out_enum_t;

uint8_t timeout_is_ok (uint32_t ms, time_out_enum_t func);


#endif //__TIME_OUT_H
