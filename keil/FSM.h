#include <stdint.h>

#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))
#define NVIC_ST_CTRL_COUNT      (0x00010000)  
#define NVIC_ST_CTRL_CLK_SRC    (0x00000004)  
#define NVIC_ST_CTRL_ENABLE     (0x00000001)  
#define QUARTER_SEC (3999999)


void SysTick_Init(void){
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_CLK_SRC;
	NVIC_ST_RELOAD_R = QUARTER_SEC;
	NVIC_ST_CURRENT_R = 0; 
	
}

void SysTick_Wait_QuarterSec(void){
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE;
	
	while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0) {} 
		
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_CLK_SRC;
	
}

void Wait_N_QuarterSec(uint32_t n_quarter_s) {
	uint32_t i;
	for(i = 0; i < n_quarter_s; i++) {
		SysTick_Wait_QuarterSec();
	}
}