#include "tm4c123ghpm.h"
#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

unsigned fact(unsigned n);

void main()
{
  unsigned volatile x;
  x = fact(0U);
  x = 2U + 3U * fact(5U);
  (void)fact(5U);
  SYSCTL_RCGCGPIO_R |= (1U << 5);
  SYSCTL_GPIOHBCTL_R |= (1U << 5);
  GPIO_PORTF_AHB_DIR_R  |= LED_RED | LED_BLUE | LED_GREEN;
  GPIO_PORTF_AHB_DEN_R  |= LED_RED | LED_BLUE | LED_GREEN;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] |= LED_BLUE;
  while(1)
  {
   GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] |= LED_RED;
   delay(1000000);
   
   GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
   delay(4000000);
}
}


unsigned fact(unsigned n)
{
  
  if(n == 0U)
  {
    return 1U;
  }
  else
  {
    return n * fact(n - 1U);
  }
}

