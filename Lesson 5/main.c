#include "tm4c123ghpm.h"


int main()
{
  SYSCTL_RCGCGPIO_R = 0x20U;
  GPIO_PORTF_DIR_R  = 0x0EU;
  GPIO_PORTF_DEN_R  = 0x0EU;
  
  while(1)
  {
   GPIO_PORTF_DATA_R = 0x02U;
   int counter = 0;
   while(counter < 1000000)
   {
     ++counter;
   }
   counter = 0;
   GPIO_PORTF_DATA_R = 0x00U;
   while(counter < 1000000)
   {
     ++counter;
   }
}
  return 0;
}