#include "KeyboardLayout.hpp"

// --- Tabelas de mapeamento por layout ---
static const std::unordered_map<char, KeyInfo> US_MAP = {
    {'!', {HID_KEY_1, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'@', {HID_KEY_2, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'.', {HID_KEY_PERIOD, 0}},
    {';', {HID_KEY_SEMICOLON, 0}},
    {':', {HID_KEY_SEMICOLON, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'/', {HID_KEY_SLASH, 0}},
    {'?', {HID_KEY_SLASH, KEYBOARD_MODIFIER_LEFTSHIFT}},
};

static const std::unordered_map<char, KeyInfo> ABNT2_MAP = {
    {'!', {HID_KEY_1, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'@', {HID_KEY_2, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'.', {HID_KEY_SLASH, 0}},
    {';', {HID_KEY_PERIOD, 0}},
    {':', {HID_KEY_PERIOD, KEYBOARD_MODIFIER_LEFTSHIFT}},
    {'/', {HID_KEY_Q, KEYBOARD_MODIFIER_RIGHTALT}}, // AltGr + Q
    {'?', {HID_KEY_W, KEYBOARD_MODIFIER_RIGHTALT}}, // AltGr + W
};

KeyboardLayout::KeyboardLayout(Layout initial_layout) : _current_layout(initial_layout) {}

void KeyboardLayout::set_layout(Layout new_layout) {
    _current_layout = new_layout;
}

static inline KeyInfo universal_map(char c) {
    KeyInfo info = {0, 0};

    if (c >= 'a' && c <= 'z') {
        info.keycode = HID_KEY_A + (c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
        info.modifier = KEYBOARD_MODIFIER_LEFTSHIFT;
        info.keycode = HID_KEY_A + (c - 'A');
    } else if (c >= '1' && c <= '9') {
        info.keycode = HID_KEY_1 + (c - '1');
    } else if (c == '0') {
        info.keycode = HID_KEY_0;
    } else if (c == ' ') {
        info.keycode = HID_KEY_SPACE;
    } else if (c == '\n') {
        info.keycode = HID_KEY_ENTER;
    } else if (c == '\t') {
        info.keycode = HID_KEY_TAB;
    } else if (c == '~') {
        info.keycode = HID_KEY_GUI_LEFT;
    }

    return info;
}

KeyInfo KeyboardLayout::get_key_info(char c) {
    KeyInfo info = universal_map(c);
    if (info.keycode != 0) return info;

    const std::unordered_map<char, KeyInfo>* table = nullptr;
    switch (_current_layout) {
        case Layout::US:    table = &US_MAP; break;
        case Layout::ABNT2: table = &ABNT2_MAP; break;
    }

    if (table) {
        auto it = table->find(c);
        if (it != table->end()) return it->second;
    }

    return {0, 0};
}
