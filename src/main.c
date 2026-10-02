// main.c
// Course number: CECS346
// Term: Fall 2026
// Project number: 1
// Project description: FSM Traffic Light System
// Team #: 2
// Team members: Daniel Ghobriel, Rylan Cirilo, Orgil Boldbaatar

#include <stdint.h>

#include "LED_SW.h"
#include "SysTick.h"
#include "FSM.h"


void System_Init(void);


int main(void) {
    uint8_t state;
    uint8_t input;

    System_Init();

    //reset condition
    state = GoS;

    while (1) {
        LED_SW_SetTraffic(FSM[state].TrafficOut);
        LED_SW_SetPedestrian(FSM[state].PedestrianOut);

        Wait_N_QuarterSec(FSM[state].Time);

        input = LED_SW_ReadSensors();

        state = FSM[state].Next[input & 0x07];
    }
}


void System_Init(void) {
    LED_SW_Init();
    SysTick_Init();
}