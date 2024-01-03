/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                   100

#include "stdio.h"

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    DigitalOut vcc(P10_3);
    DigitalOut gnd(P10_0);
    AnalogIn therm(P10_1);
    printf("Testing\n");
    vcc = 1;
    gnd = 0;

    while (true) {
        led = !led;
        float temp = therm.read();
        printf("the voltage is: %f\n", temp );
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
