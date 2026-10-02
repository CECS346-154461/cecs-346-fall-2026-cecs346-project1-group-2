// LED_SW.h
// Course number: CECS346
// Term: Fall 2026
// Project number: 1
// Project description: FSM Traffic Light System
// Team #: 2
// Team members: Daniel Ghobriel, Rylan Cirilo, Orgil Boldbaatar

#ifndef LED_SW_H
#define LED_SW_H

#include <stdint.h>

void LED_SW_Init(void);

uint8_t LED_SW_ReadSensors(void);

void LED_SW_SetTraffic(uint32_t output);

void LED_SW_SetPedestrian(uint32_t output);

void LED_SW_AllOff(void);

#endif