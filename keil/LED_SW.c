#include <stdint.h>
#include "LED_SW.h"


// System control register

#define SYSCTL_RCGC2_R       (*((volatile uint32_t *)0x400FE108))

#define SYSCTL_RCGC2_GPIOB  0x02
#define SYSCTL_RCGC2_GPIOE  0x10
#define SYSCTL_RCGC2_GPIOF  0x20


// Port B registers

#define GPIO_PORTB_BASE      0x40005000

#define GPIO_PORTB_DIR_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x400)))
#define GPIO_PORTB_AFSEL_R   (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x420)))
#define GPIO_PORTB_DEN_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x51C)))
#define GPIO_PORTB_AMSEL_R   (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x528)))
#define GPIO_PORTB_PCTL_R    (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x52C)))


// Port E registers

#define GPIO_PORTE_BASE      0x40024000

#define GPIO_PORTE_DIR_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x400)))
#define GPIO_PORTE_AFSEL_R   (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x420)))
#define GPIO_PORTE_DEN_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x51C)))
#define GPIO_PORTE_AMSEL_R   (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x528)))
#define GPIO_PORTE_PCTL_R    (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x52C)))
#define GPIO_PORTE_PDR_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x514)))


// Port F registers

#define GPIO_PORTF_BASE      0x40025000

#define GPIO_PORTF_DIR_R     (*((volatile uint32_t *)(GPIO_PORTF_BASE + 0x400)))
#define GPIO_PORTF_AFSEL_R   (*((volatile uint32_t *)(GPIO_PORTF_BASE + 0x420)))
#define GPIO_PORTF_DEN_R     (*((volatile uint32_t *)(GPIO_PORTF_BASE + 0x51C)))
#define GPIO_PORTF_AMSEL_R   (*((volatile uint32_t *)(GPIO_PORTF_BASE + 0x528)))
#define GPIO_PORTF_PCTL_R    (*((volatile uint32_t *)(GPIO_PORTF_BASE + 0x52C)))


// Bit-specific GPIO addresses

// PB5-PB0: traffic LEDs
#define T_LIGHTS \
    (*((volatile uint32_t *)(GPIO_PORTB_BASE + (0x3F << 2))))

// PE2-PE0: sensors
#define SENSORS \
    (*((volatile uint32_t *)(GPIO_PORTE_BASE + (0x07 << 2))))

// PF3 and PF1: pedestrian LEDs
#define P_LIGHTS \
    (*((volatile uint32_t *)(GPIO_PORTF_BASE + (0x0A << 2))))


// Masks

#define TRAFFIC_MASK      0x3F
#define SENSOR_MASK       0x07
#define PEDESTRIAN_MASK   0x0A


void LED_SW_Init(void) {
    volatile uint32_t delay;

    // Enable Ports B, E, and F
    SYSCTL_RCGC2_R |=
        SYSCTL_RCGC2_GPIOB |
        SYSCTL_RCGC2_GPIOE |
        SYSCTL_RCGC2_GPIOF;

    // Allow clocks to stabilize
    delay = SYSCTL_RCGC2_R;
    (void)delay;


    // Configure PB5-PB0 as digital outputs

    GPIO_PORTB_AMSEL_R &= ~TRAFFIC_MASK;
    GPIO_PORTB_PCTL_R  &= ~0x00FFFFFF;
    GPIO_PORTB_AFSEL_R &= ~TRAFFIC_MASK;
    GPIO_PORTB_DIR_R   |= TRAFFIC_MASK;
    GPIO_PORTB_DEN_R   |= TRAFFIC_MASK;


    // Configure PE2-PE0 as digital inputs

    GPIO_PORTE_AMSEL_R &= ~SENSOR_MASK;
    GPIO_PORTE_PCTL_R  &= ~0x00000FFF;
    GPIO_PORTE_AFSEL_R &= ~SENSOR_MASK;
    GPIO_PORTE_DIR_R   &= ~SENSOR_MASK;
    GPIO_PORTE_DEN_R   |= SENSOR_MASK;

    // Positive logic: inactive switches read 0
    GPIO_PORTE_PDR_R |= SENSOR_MASK;


    // Configure PF3 and PF1 as digital outputs

    GPIO_PORTF_AMSEL_R &= ~PEDESTRIAN_MASK;
    GPIO_PORTF_PCTL_R  &= ~0x0000F0F0;
    GPIO_PORTF_AFSEL_R &= ~PEDESTRIAN_MASK;
    GPIO_PORTF_DIR_R   |= PEDESTRIAN_MASK;
    GPIO_PORTF_DEN_R   |= PEDESTRIAN_MASK;


    // Start with all LEDs off
    T_LIGHTS = 0;
    P_LIGHTS = 0;
}


uint8_t LED_SW_ReadSensors(void) {
    return (uint8_t)(SENSORS & SENSOR_MASK);
}


void LED_SW_SetTraffic(uint32_t output) {
    T_LIGHTS = output & TRAFFIC_MASK;
}


void LED_SW_SetPedestrian(uint32_t output) {
    P_LIGHTS = output & PEDESTRIAN_MASK;
}


void LED_SW_AllOff(void) {
    T_LIGHTS = 0;
    P_LIGHTS = 0;
}