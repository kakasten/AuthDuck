#ifndef KEYBOARD_LAYOUT_HPP
#define KEYBOARD_LAYOUT_HPP

#include <cstdint>
#include <unordered_map>
#include "tusb.h" 

enum class Layout {
    US,
    ABNT2
};

struct KeyInfo {
    uint8_t keycode;
    uint8_t modifier;
};

class KeyboardLayout {
public:
    KeyboardLayout(Layout initial_layout = Layout::US);
    void set_layout(Layout new_layout);

    KeyInfo get_key_info(char c);

private:
    Layout _current_layout;
};

#endif // KEYBOARD_LAYOUT_HPP
