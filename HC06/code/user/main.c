#include "stm32f10x.h"
#include "open.h"


/********************************************************************************
*函数名：void RobotMove(uint8_t time, uint8_t command)
*函数功能：使小车运动
*函数参数说明：time小车运行时间, command小车运行方式0-左拐;1-前进;2-后退;3-右拐;
*函数返回值：无
********************************************************************************/
void RobotMove(uint8_t time, uint8_t command);
uint16_t pulse_duration[] = { 1100, 1700 };

int main( )
{
	Open_Init();
	while(1) {
		if ( USART_GetFlagStatus(USART1, USART_IT_RXNE)==SET ) {
			switch(USART_ReceiveData(USART1))
			{
				case '2' :
					RobotMove(0x10, 0x01);
					break;
				case '4' :
					RobotMove(0x10, 0x00);
					break;
				case '6' :
					RobotMove(0x10, 0x03);
					break;
				case '8' :
					RobotMove(0x10, 0x02);
					break;
				default :
					break;
			}
		}
	}
}

void RobotMove(uint8_t time, uint8_t command) {
	int Counter;
	for(Counter = 0; Counter <= time; Counter++) {
		GPIO_SetBits( GPIOE,GPIO_Pin_3 );
		delay_nus( pulse_duration[command&0x01] );
		GPIO_ResetBits( GPIOE,GPIO_Pin_3 );
		GPIO_SetBits( GPIOE,GPIO_Pin_10 );
		delay_nus( pulse_duration[(command>>0x01)&0x01] );
		GPIO_ResetBits( GPIOE,GPIO_Pin_10 );
		delay_nms( 20 );
	}
}
