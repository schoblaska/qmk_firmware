// make ergodox_ez:joey
// run graphical teensy loader: https://www.pjrc.com/teensy/loader_mac.html

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define CMD_SPC LGUI(KC_SPC)
#define CMD_A   LGUI(KC_A)
#define CMD_C   LGUI(KC_C)
#define CMD_F   LGUI(KC_F)
#define CMD_N   LGUI(KC_N)
#define CMD_Q   LGUI(KC_Q)
#define CMD_R   LGUI(KC_R)
#define CMD_S   LGUI(KC_S)
#define CMD__T  LGUI(KC_T)
#define CMD_V   LGUI(KC_V)
#define CMD_W   LGUI(KC_W)
#define CTL_A   LCTL(KC_A)

enum custom_keycodes {
  ESCFN = SAFE_RANGE,
  LANG_TG,
  CTRL_A,
  SH_HOME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
    ESCFN,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_LGUI,
                                                 TG(3),   LANG_TG,
                                                          _______,
                                        MO(1),   CTL_A,   _______,
                                                                    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                                                                    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                                                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
                                                                    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                                                      KC_DOWN, KC_UP,   KC_RGUI, KC_RALT, KC_RCTL,
                                                                    KC_LEFT, KC_RGHT,
                                                                    _______,
                                                                    MO(2),   KC_RCTL, KC_SPC
  ),

  [1] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CMD__T,  _______,
    _______, _______, _______, _______, _______, SH_HOME,
    _______, _______, _______, CMD_C,   CMD_V,   _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
                                                                    _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_DEL,
                                                                    _______, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_DQUO, KC_PGUP,
                                                                             KC_EQL,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, KC_PGDN,
                                                                    _______, _______, _______, _______, _______, KC_UP,   _______,
                                                                                      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______, _______
  ),

  [2] = LAYOUT_ergodox(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
                                                                    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                                                                    _______, _______, _______, _______, _______, _______, KC_F12,
                                                                             _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                                      _______, _______, _______, _______, _______,
                                                                    _______, RESET,
                                                                    _______,
                                                                    _______, _______, _______
  ),

  [3] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_SPC,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                             _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                                      _______, _______, _______, _______, _______,
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______,  _______
  ),
};

int escfn_down = 0;
int escfn_mod_pressed = 0;
int modded_h_pressed = 0;
int modded_j_pressed = 0;
int modded_k_pressed = 0;
int modded_l_pressed = 0;
int modded_spc_pressed = 0;

void modded_key_press(keyrecord_t *record, uint16_t orig, uint16_t modded, int *mod_pressed) {
  if (record->event.pressed) {
    if (escfn_down == 1) {
      escfn_mod_pressed = 1;
      *mod_pressed = 1;
      register_code(modded);
    } else {
      register_code(orig);
    }
  } else {
    if (*mod_pressed == 1) {
      unregister_code(modded);
    } else {
      unregister_code(orig);
    }
    *mod_pressed = 0;
  }
}

void modded_macro_press(keyrecord_t *record, uint16_t orig, char* macro, int *mod_pressed) {
  if (record->event.pressed) {
    if (escfn_down == 1) {
      escfn_mod_pressed = 1;
      *mod_pressed = 1;
      send_string(macro);
    } else {
      register_code(orig);
    }
  } else {
    if (*mod_pressed == 0) {
      unregister_code(orig);
    }
    *mod_pressed = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case ESCFN:
      if (record->event.pressed) {
        escfn_down = 1;
      } else {
        if (escfn_mod_pressed == 0) {
          SEND_STRING(SS_TAP(X_ESCAPE));
        }
        escfn_down = 0;
      }
      escfn_mod_pressed = 0;
      return false;

    case KC_H:
      modded_key_press(record, KC_H, KC_LEFT, &modded_h_pressed);
      return false;

    case KC_J:
      modded_key_press(record, KC_J, KC_DOWN, &modded_j_pressed);
      return false;

    case KC_K:
      modded_key_press(record, KC_K, KC_UP, &modded_k_pressed);
      return false;

    case KC_L:
      modded_key_press(record, KC_L, KC_RIGHT, &modded_l_pressed);
      return false;

    case KC_SPC:
      modded_macro_press(record, KC_SPC, SS_LCTRL("a") SS_DELAY(100) "o", &modded_spc_pressed);
      return false;

    case LANG_TG:
      if (record->event.pressed) {
        send_string(SS_LGUI(SS_LALT(" ")));
      } else {
        // key released
      }
      return false;

    case SH_HOME:
      if (record->event.pressed) {
        send_string("~/");
      } else {
        // key released
      }
      return false;
  }

  return true;
};

void matrix_scan_user(void) {
  if (escfn_down == 1) {
    ergodox_led_all_on();
    ergodox_led_all_set(20);
  } else {
    ergodox_led_all_off();

    if (IS_LAYER_ON(1)) {
      ergodox_right_led_3_on();
      ergodox_right_led_3_set(20);
    }

    if (IS_LAYER_ON(2)) {
      ergodox_right_led_2_on();
      ergodox_right_led_2_set(20);
    }

    if (IS_LAYER_ON(3)) {
      ergodox_right_led_2_on();
      ergodox_right_led_2_set(20);
      ergodox_right_led_3_on();
      ergodox_right_led_3_set(20);
    }

    if (IS_LAYER_ON(4)) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set(20);
    }

    if (IS_LAYER_ON(5)) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set(20);
      ergodox_right_led_3_on();
      ergodox_right_led_3_set(20);
    }

    if (IS_LAYER_ON(6)) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set(20);
      ergodox_right_led_2_on();
      ergodox_right_led_2_set(20);
    }
  }
};
