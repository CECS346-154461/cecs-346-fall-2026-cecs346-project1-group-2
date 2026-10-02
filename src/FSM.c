// FSM.c
// Course number: CECS346
// Term: Fall 2026
// Project number: 1
// Project description: FSM Traffic Light System
// Team #: 2
// Team members: Daniel Ghobriel, Rylan Cirilo, Orgil Boldbaatar

#include "FSM.h"


#define SOUTH_GREEN   0x01
#define SOUTH_YELLOW  0x02
#define SOUTH_RED     0x04

#define WEST_GREEN    0x08
#define WEST_YELLOW   0x10
#define WEST_RED      0x20


#define WALK          0x08
#define DONT_WALK     0x02
#define PED_OFF       0x00


/*
    Input order:

    PE2 PE1 PE0
     S   W   P

    Table columns:

    000, 001, 010, 011, 100, 101, 110, 111
*/


STyp FSM[9] = {

    // GoS
    {
        SOUTH_GREEN | WEST_RED,
        DONT_WALK,
        8,
        {
            GoS,     // 000
            WaitS,   // 001
            WaitS,   // 010
            WaitS,   // 011
            GoS,     // 100
            WaitS,   // 101
            WaitS,   // 110
            WaitS    // 111
        }
    },


    // WaitS
    {
        SOUTH_YELLOW | WEST_RED,
        DONT_WALK,
        4,
        {
            GoW,    
            GoP,
            GoW,
            GoW,
            GoP,
            GoP,   
            GoW, 
            GoP      
        }
    },


    // GoW
    {
        SOUTH_RED | WEST_GREEN,
        DONT_WALK,
        8,
        {
            GoW,
            WaitW,
            GoW,
            WaitW,
            WaitW,
            WaitW,
            WaitW,
            WaitW
        }
    },


    // WaitW
    {
        SOUTH_RED | WEST_YELLOW,
        DONT_WALK,
        4,
        {
            GoS,
            GoP,
            GoS,
            GoP,
            GoS,
            GoP,
            GoS,
            GoS  //111: All switches on, all lights cycle.
        }
    },


    // GoP
    {
        SOUTH_RED | WEST_RED,
        WALK,
        8,
        {
            GoP,
            GoP,
            WaitPOn1,
            WaitPOn1,
            WaitPOn1,
            WaitPOn1,
            WaitPOn1,
            WaitPOn1
        }
    },


    // WaitPOn1
    {
        SOUTH_RED | WEST_RED,
        DONT_WALK,
        1,
        {
            WaitPOff1,
            WaitPOff1,
            WaitPOff1,
            WaitPOff1,
            WaitPOff1,
            WaitPOff1,
            WaitPOff1,
            WaitPOff1
        }
    },


    // WaitPOff1
    {
        SOUTH_RED | WEST_RED,
        PED_OFF,
        1,
        {
            WaitPOn2,
            WaitPOn2,
            WaitPOn2,
            WaitPOn2,
            WaitPOn2,
            WaitPOn2,
            WaitPOn2,
            WaitPOn2 
        }
    },


    // WaitPOn2
    {
        SOUTH_RED | WEST_RED,
        DONT_WALK,
        1,
        {
            WaitPOff2,
            WaitPOff2,
            WaitPOff2,
            WaitPOff2,
            WaitPOff2,
            WaitPOff2,
            WaitPOff2,
            WaitPOff2
        }
    },


    // WaitPOff2
    {
        SOUTH_RED | WEST_RED,
        PED_OFF,
        1,
        {
            GoP,
            GoP,
            GoW,
            GoW,
            GoS,
            GoS,
            GoW,
            GoW          
        }
    }
};
