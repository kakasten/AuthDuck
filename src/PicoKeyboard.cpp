#include "PicoKeyboard.hpp"

static bool pending_release = false;

PicoKeyboard::PicoKeyboard() {
}

void PicoKeyboard::begin() {
    tusb_init();
}

void PicoKeyboard::task() {
    tud_task();
}

void PicoKeyboard::type(const char* text) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        send_char(text[i]);
    }
}

void PicoKeyboard::type_line(const char* text) {
    type(text);       
    send_char('\n');  
}

void PicoKeyboard::send_char(char c) {
    while (!tud_hid_ready()) {
        task(); 
    }

    KeyInfo info = _layout.get_key_info(c);
    if (info.keycode == 0) return; 

    uint8_t keycode[6] = { info.keycode, 0, 0, 0, 0, 0 };
    uint8_t modifier = info.modifier;

    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, modifier, keycode);

    while (!tud_hid_ready()) task();

    pending_release = true;
}

void PicoKeyboard::set_layout(Layout layout) {
    _layout.set_layout(layout);
}

extern "C" void tud_hid_report_complete_cb(uint8_t instance, uint8_t const* report, uint16_t len) {
    (void) instance;
    (void) report;
    (void) len;

    if (pending_release) {
        // Libera a tecla no próximo ciclo USB
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, nullptr);
        pending_release = false;
    }
}
