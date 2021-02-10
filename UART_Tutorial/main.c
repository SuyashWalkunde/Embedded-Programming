#include <arm_math.h>
#include "stm32f4xx.h"                  // Device header
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void USART2_Init(void);
void USART_write(char a);
void msDelay(int delay);

char buffer[50] = "Suaysh Sanjay Walkunde \r\n";
uint8_t i = 0;
char new_buffer[50];
char data;

int main()
{
	
	USART2_Init();
	for (i = 0; i < strlen(buffer); i++)
	{
	USART_write(buffer[i]);
	}
	
  while(1)
 {
	sprintf(new_buffer, "%d\r\n", 2323232);
	for (i = 0; i < strlen(new_buffer); i++)
	{
	USART_write((char)new_buffer[i]);
	}
 }

}
void USART2_Init(void)
{

RCC->APB1ENR |= 0x20000;
RCC->AHB1ENR |= 1;
GPIOA->AFR[0] = 0x0700;
GPIOA->MODER |= 0x0020; //set PA2to  alternate function

USART2->BRR  = 0x683;  //9600@16MHZ
USART2->CR1  = 0x0008; //enable tx
USART2->CR1 |= 0x2000;  //USART ENABLE



}

void USART_write(char a)
{
//wait while TX buffer is empty
while(!(USART2->SR & 0x0080)){}

USART2->DR =(a & 0xFF);

}

void msDelay(int delay)
{
int i;
for(;delay>0;delay--)
{
for(i=0;i<3195;i++);
}
}
