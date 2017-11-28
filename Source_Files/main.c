#include "include.h"

int init_finish;

int main(void)
{
	u8 key_flag=0;
	u8 dis_time[40];//存放运行时间字符串
	init_finish = all_init();//初始化函数
	LCD_Clear(BLACK);
	POINT_COLOR=YELLOW;	//显示屏设置黄色字体

	while(1)
	{
		if(key_scan(0)==1&&key_flag==0)
		{
			key_flag = 1;
			LED0=!LED0;
			AT24CXX_Write(0, (u8*)run_time, 4);
		}
		if(key_scan(0)==2&&key_flag==0)
		{
			key_flag = 1;
			LED1=!LED1;
			AT24CXX_Read(0,run_time,4);
		}
		if(key_scan(0)==0) key_flag = 0;//按键标志位清零
		
		if(time_dis_en)
		{
			time_dis_en = 0;
			LCD_Fill(124,303,240,319,BLACK);	//清除显示数字区域
			sprintf((char*)dis_time,"system run time:%dD-%d:%d:%d",run_time[3],run_time[2],run_time[1],run_time[0]);
			LCD_ShowString(5,303,240,16,16,dis_time);
		}
	}
}
