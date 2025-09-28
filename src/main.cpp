#include <pico/stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsp/rp2040/board.h>
#include <tusb.h>

#include "usb_descriptors.h"

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
