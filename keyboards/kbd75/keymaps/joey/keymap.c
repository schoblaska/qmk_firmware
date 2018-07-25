// press key combo for RESET
// make kbd75:joey:dfu

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

enum custom_keycodes {
  ESCFN = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(1),    KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    ESCFN,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LALT, KC_LGUI,                       KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
};

int escfn_down = 0;
int escfn_mod_pressed = 0;
int modded_h_pressed = 0;
int modded_j_pressed = 0;
int modded_k_pressed = 0;
int modded_l_pressed = 0;
int modded_o_pressed = 0;
int modded_sc_pressed = 0;

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

    case KC_O:
      modded_macro_press(record, KC_O, SS_LCTRL("a")"o", &modded_o_pressed);
      return false;

    case KC_SCLN:
      modded_macro_press(record, KC_SCLN, SS_LCTRL("a")";", &modded_sc_pressed);
      return false;
  }

  return true;
};
