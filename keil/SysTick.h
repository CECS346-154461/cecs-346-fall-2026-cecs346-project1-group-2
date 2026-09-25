#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

void SysTick_Init(void);
void SysTick_Wait_QuarterSec(void);
void Wait_N_QuarterSec(uint32_t n_quarter_s);

#endif