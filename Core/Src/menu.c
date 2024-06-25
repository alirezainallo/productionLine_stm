#include "menu.h"

extern uint16_t products_num; //from "reertos.c"


menu_state_t g_menu_state;

uint8_t need_res_prod_num = 0;



void menu_init (void)
{
	g_menu_state = MENU_MAIN_PAGE;
	LCD_Puts(0, 0, "Starting...");
	osDelay(1000);
	LCD_Clear();
}


extern uint32_t number; //from "keypad_4x4.c" :)

void menu_page_init (menu_state_t menu_state)
{
char lcd_buffer[17] = {0};	

	g_menu_state = menu_state;

	switch(menu_state)
	{
		case MENU_MAIN_PAGE:
			LCD_Clear();
			LCD_Puts(0, 0, "A.CH_PF");       //ta 6 poreh   //kp 10
			LCD_Puts(10, 0, "B.View");       //ta 13 poreh  //kp 11
			LCD_Puts(0, 1, "C.Res_det");     //ta 10 poreh  //kp 12
		break;
		case MENU_CHANGE_PF:
			LCD_Clear();
			LCD_Puts(0, 0, "Enter new %PF:");
			number = 0;
		break;
		case MENU_VIEW_DETALES:
			LCD_Clear();
			sprintf(lcd_buffer, "Produc = %d", TrsQueMes.product_num);
			LCD_Puts(0, 0, lcd_buffer);
			TrsQueMes.current_PF = motor_dc_get_pf(MOTOR_A);
			sprintf(lcd_buffer, "PF = %d", TrsQueMes.current_PF);
			LCD_Puts(0, 1, lcd_buffer);
		break;
		case MENU_RESET_PRODUCTS_NUM:
			need_res_prod_num = 1;
			LCD_Clear();
			LCD_Puts(0, 0, "detales reset");
			LCD_Puts(0, 1, "successfully.");
			osDelay(1000);
			menu_page_init(MENU_MAIN_PAGE);
		break;
		
	}
	
}
void menu_process (menu_MessageQueue_t * RecQuseMes)
{
char lcd_buffer[8] = {0};

	switch(RecQuseMes->rq_status)
	{
		case CH_PRODUCT_NUM:

			switch(g_menu_state)
			{
				case MENU_MAIN_PAGE:
				break;
				case MENU_CHANGE_PF:
				break;
				case MENU_VIEW_DETALES:
					LCD_Puts(9, 0, "       ");
					sprintf(lcd_buffer, "%d", RecQuseMes->product_num);
					LCD_Puts(9, 0, lcd_buffer);
				break;
				case MENU_RESET_PRODUCTS_NUM:
				break;
			}
			
		break;
		case CH_CURRENT_PF:
			
			switch(g_menu_state)
			{
				case MENU_MAIN_PAGE:
				break;
				case MENU_CHANGE_PF:
					LCD_Clear();
					LCD_Puts(0, 0, "motor PF set");
					LCD_Puts(0, 1, "successfully.");
				break;
				case MENU_VIEW_DETALES:
				break;
				case MENU_RESET_PRODUCTS_NUM:
				break;
			}

		break;
		case CH_ENTERED_PF:
						
			switch(g_menu_state)
			{
				case MENU_MAIN_PAGE:
				break;
				case MENU_CHANGE_PF:
					LCD_Puts(0, 1, "   ");
					sprintf(lcd_buffer, "%d", RecQuseMes->entered_PF);
					LCD_Puts(0, 1, lcd_buffer);
				break;
				case MENU_VIEW_DETALES:
				break;
				case MENU_RESET_PRODUCTS_NUM:
				break;
			}
			
		break;
		default:
		break;
	}
	
}
