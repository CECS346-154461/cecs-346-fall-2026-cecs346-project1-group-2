#ifndef FSM_H
#define FSM_H

#include <stdint.h>

enum FSMStates {
    GoS,
    WaitS,
    GoW,
    WaitW,
    GoP,
    WaitPOn1,
    WaitPOff1,
    WaitPOn2,
    WaitPOff2
};

struct State {
    uint32_t TrafficOut;
    uint32_t PedestrianOut;
    uint8_t Time;
    uint8_t Next[8];
};

typedef const struct State STyp;

extern STyp FSM[9];

#endif
