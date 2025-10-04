#include <pico/stdlib.h>

#include "PicoKeyboard.hpp"
#include "KeyboardLayout.hpp"

PicoKeyboard keyboard;

uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen) { (void)itf; (void)report_id; (void)report_type; (void)buffer; (void)reqlen; return 0; }
void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) { (void)itf; (void)report_id; (void)report_type; (void)buffer; (void)bufsize; }

int main(){
    keyboard.begin();
    keyboard.set_layout(Layout::US);

    keyboard.task();

    keyboard.type("~");
    tusb_time_delay_ms_api(500);
    keyboard.type_line("firefox");
    tusb_time_delay_ms_api(1000);
    keyboard.type_line("");
    tusb_time_delay_ms_api(2000);
    keyboard.type_line("github.com/kakasten/AuthDuck");
    tusb_time_delay_ms_api(3000);
    for(int i = 0; i < 26; i++){
        keyboard.type("\t");
    }
    keyboard.type_line("");
    while (true) {
        keyboard.task();
    }

    return 0;
}