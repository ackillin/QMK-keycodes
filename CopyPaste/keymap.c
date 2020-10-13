/*
This is the code of Jacob Conrady not sure if I get copyright or not so meh.
*/
#include QMK_KEYBOARD_H
//static uint16_t pressTimer = 0xFFFF;
#define CUSTOM_LONGPRESS 150
#define CUSTOM_LONGERPRESS 500

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
            //MT((MOD_LCTL | KC_I) ,  (KC_DOT));
            //MT(MOD_LCTL|MOD_LSFT,KC_ESC);
            //when keycode UNO is pressed
            /*register_code(KC_RCTL);
            register_code(KC_I);*/
            if(MT(MOD_LCTL | KC_C , MOD_LCTL | KC_V))
            SEND_STRING(" ");
        }
        else {
        //when uno is released
            /*unregister_code(KC_RCTL);
            unregister_code(KC_I);*/
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
    rgblight_sethsv_noeeprom(255, 255, 255);
    rgblight_mode(1);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
}
