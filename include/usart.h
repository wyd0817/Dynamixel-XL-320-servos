#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f10x.h"


#define USART_REC_LEN_2  			200  	//¶šÒå×îŽóœÓÊÕ×ÖœÚÊý 200
#define USART_REC_LEN  			200  	//¶šÒå×îŽóœÓÊÕ×ÖœÚÊý 200
#define EN_USART1_RX 			1		//Ê¹ÄÜ£š1£©/œûÖ¹£š0£©Ž®¿Ú1œÓÊÕ
	  	


void uart_init(u32 bound);
void USART1_SendData(u8 temp);
void USART1_SendString(u8 *s);
void uart2_init(u32 bound);
void USART2_SendData(u8 temp);
void USART2_SendString(u8 *s);


#endif


