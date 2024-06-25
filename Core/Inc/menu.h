

#ifndef _MENU_H
#define _MENU_H

#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "stdio.h"
#include "LCD.h"
#include "motor_dc.h"


typedef enum
{
	CH_PRODUCT_NUM,
	CH_CURRENT_PF,
	CH_ENTERED_PF 
}desplay_req_status_t;

typedef struct
{
	uint8_t  current_PF;
	uint8_t  entered_PF;
	uint32_t product_num;
	desplay_req_status_t rq_status;
}menu_MessageQueue_t;

typedef enum
{
	MENU_MAIN_PAGE,
	MENU_CHANGE_PF,
	MENU_VIEW_DETALES,
	MENU_RESET_PRODUCTS_NUM,
}menu_state_t;



extern menu_state_t g_menu_state;
extern menu_MessageQueue_t TrsQueMes;

extern uint8_t need_res_prod_num; //for reset product num func


void menu_init (void);
void menu_process (menu_MessageQueue_t * RecQuseMes);
void menu_page_init (menu_state_t menu_state);


#endif //_MENU_H
