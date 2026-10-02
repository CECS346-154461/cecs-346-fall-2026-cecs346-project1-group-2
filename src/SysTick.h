// SysTick.h.c
// Course number: CECS346
// Term: Fall 2026
// Project number: 1
// Project description: FSM Traffic Light System
// Team #: 2
// Team members: Daniel Ghobriel, Rylan Cirilo, Orgil Boldbaatar

#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

void SysTick_Init(void);
void SysTick_Wait_QuarterSec(void);
void Wait_N_QuarterSec(uint32_t n_quarter_s);

#endif