#include <stdint.h>

#include "LED_SW.h"
#include "SysTick.h"


int main(void) {
    uint8_t sensors;

    LED_SW_Init();
    SysTick_Init();

    while (1) {
        // Test South traffic LEDs
        LED_SW_SetTraffic(0x01);
        LED_SW_SetPedestrian(0x00);
        Wait_N_QuarterSec(2);

        LED_SW_SetTraffic(0x02);
        Wait_N_QuarterSec(2);

        LED_SW_SetTraffic(0x04);
        Wait_N_QuarterSec(2);

        // Test West traffic LEDs
        LED_SW_SetTraffic(0x08);
        Wait_N_QuarterSec(2);

        LED_SW_SetTraffic(0x10);
        Wait_N_QuarterSec(2);

        LED_SW_SetTraffic(0x20);
        Wait_N_QuarterSec(2);

        // Test pedestrian Walk LED
        LED_SW_SetTraffic(0x24);
        LED_SW_SetPedestrian(0x08);
        Wait_N_QuarterSec(4);

        // Test pedestrian Don't Walk LED
        LED_SW_SetPedestrian(0x02);
        Wait_N_QuarterSec(4);

        // Read the three switches
        sensors = LED_SW_ReadSensors();

        // Display PE2-PE0 switch values on PB2-PB0
        LED_SW_SetTraffic(sensors);
        LED_SW_SetPedestrian(0x02);

        Wait_N_QuarterSec(4);
    }
}