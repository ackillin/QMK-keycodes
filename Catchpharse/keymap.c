/*
This is the code of Jacob Conrady not sure if I get copyright or not so meh.
*/
#include QMK_KEYBOARD_H

const uint8_t PROGMEM RGBLED_RAINBOW_MOOD_INTERVALS[] = { 10, 25, 50 };

enum custom_keycodes {
    UNO = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            UNO
          )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   switch(keycode){
   case UNO:
        if(record->event.pressed) {
            //when keycode UNO is pressed
            SEND_STRING(":jgk tsfo ralk; ");
        } else {
            //when UNO is released
        }
        break;
   }
  return true;
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode(1);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
}
