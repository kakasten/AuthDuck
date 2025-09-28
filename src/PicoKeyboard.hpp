#ifndef PICO_KEYBOARD_HPP
#define PICO_KEYBOARD_HPP

#include <pico/stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bsp/rp2040/board.h"
#include <tusb.h>

#include "usb_descriptors.h"
#include "KeyboardLayout.hpp"

class PicoKeyboard {
public:
    PicoKeyboard();
    void begin();
    void task();
    void type(const char* text);
    void type_line(const char* text);
    void send_char(char c);

    void set_layout(Layout layout); 

private:
    KeyboardLayout _layout {Layout::US};
};

#endif // PICO_KEYBOARD_HPP

