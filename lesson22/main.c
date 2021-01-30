#include <stdint.h>
#include "bsp.h"

/* background code: sequential with blocking version */
uint32_t stack_blinky1[40];
uint32_t *sp_blinky1 = &stack_blinky1[40];
int main_blinky1() {
    BSP_init();
    while (1) {
        BSP_ledGreenOn();
        BSP_delay(BSP_TICKS_PER_SEC / 4U);
        BSP_ledGreenOff();
        BSP_delay(BSP_TICKS_PER_SEC * 3U / 4U);
    }

}
uint32_t stack_blinky2[40];
uint32_t *sp_blinky2 = &stack_blinky2[40];
int main_blinky2() {
    BSP_init();
    while (1) {
        BSP_ledRedOn();
        BSP_delay(BSP_TICKS_PER_SEC / 4U);
        BSP_ledRedOff();
        BSP_delay(BSP_TICKS_PER_SEC * 3U / 4U);
    }

}

int main()
{
	
	uint32_t volatile run = 0U;
	BSP_init();
	*(--sp_blinky1) = (1U << 24);
	*(--sp_blinky1) = (uint32_t)&main_blinky1;
	*(--sp_blinky1) = 0x0000000EU;
	*(--sp_blinky1) = 0x0000000CU;
	*(--sp_blinky1) = 0x00000003U;
	*(--sp_blinky1) = 0x00000002U;
	*(--sp_blinky1) = 0x00000001U;
	*(--sp_blinky1) = 0x00000000U;
	
		*(--sp_blinky2) = (1U << 24);
	*(--sp_blinky2) = (uint32_t)&main_blinky2;
	*(--sp_blinky2) = 0x0000000EU;
	*(--sp_blinky2) = 0x0000000CU;
	*(--sp_blinky2) = 0x00000003U;
	*(--sp_blinky2) = 0x00000002U;
	*(--sp_blinky2) = 0x00000001U;
	*(--sp_blinky2) = 0x00000000U;
}

