#include "tm4c123ghpm.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

int main()
{
  SYSCTL_RCGCGPIO_R |= (1U << 5);
  GPIO_PORTF_DIR_R  |= LED_RED | LED_BLUE | LED_GREEN;
  GPIO_PORTF_DEN_R  |= LED_RED | LED_BLUE | LED_GREEN;
  GPIO_PORTF_DATA_R |= LED_GREEN;
  while(1)
  {
   GPIO_PORTF_DATA_R |= LED_RED;
   int volatile counter = 0;
       while(counter < 1000000)
       {
         ++counter;
       }
   counter = 0;
   GPIO_PORTF_DATA_R &=~ (LED_RED);
       while(counter < 1000000)
       {
         ++counter;
       }
}
  return 0;
}
