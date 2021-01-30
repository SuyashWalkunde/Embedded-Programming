#include "tm4c123ghpm.h"
#include "tm4c_cmsis.h"
#include <stdint.h>
#include "bsp.h"



void main()
{
  SYSCTL_RCGCGPIO_R |= (1U << 5);
  SYSCTL_GPIOHBCTL_R |= (1U << 5);
  GPIO_PORTF_AHB_DIR_R  |= LED_RED | LED_BLUE | LED_GREEN;
  GPIO_PORTF_AHB_DEN_R  |= LED_RED | LED_BLUE | LED_GREEN;

  SysTick -> LOAD = (SYSCLK_HZ / 4U) - 1U;
  SysTick -> VAL = 0U;
  SysTick -> CTRL = (1U << 1) | (1U << 2) | 1U;
    
  __enable_interrupt();
  while(1)
  {
   
  }
}

