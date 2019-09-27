// make ergodox_ez:joey
// run graphical teensy loader: https://www.pjrc.com/teensy/loader_mac.html

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define DBLQUOT LSFT(KC_QUOT)
#define LCURLY LSFT(KC_LBRC)
#define RCURLY LSFT(KC_RBRC)
#define LPAREN LSFT(KC_9)
#define RPAREN LSFT(KC_0)
#define UNDERSC LSFT(KC_MINS)
#define PLUS LSFT(KC_EQL)

enum custom_keycodes {
  ESCFN = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    // left hand
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
    ESCFN,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,
                                                 KC_MPRV, KC_MNXT,
                                                          KC_MPLY,
                                        KC_LGUI, MO(1),   KC_LCTL,

                                                                    // right hand
                                                                    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                                                                    KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                                                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
                                                                    KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                                                      KC_SPC,  _______, KC_LBRC, KC_RBRC, KC_QUOT,
                                                                    KC_VOLD, KC_VOLU,
                                                                    KC_MUTE,
                                                                    MO(2),   KC_RCTL, KC_SPC
  ),

  [1] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

                                                                    // right hand
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                    _______, PLUS,    UNDERSC, LCURLY,  RCURLY,  DBLQUOT, _______,
                                                                             KC_EQL,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, _______,
                                                                    _______, _______, _______, LPAREN,  RPAREN,  _______, KC_RSFT,
                                                                                      _______, _______, _______, _______, _______,
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______, _______
  ),

  [2] = LAYOUT_ergodox(
    // left hand
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
    ESCFN,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,
                                                 KC_MPRV, KC_MNXT,
                                                          KC_MPLY,
                                        KC_LGUI, KC_SPC,  KC_LCTL,

                                                                    // right hand
                                                                    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                                                                    KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                                                             KC_H,    KC_UP,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
                                                                    KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DOT,  KC_SLSH, KC_RSFT,
                                                                                      _______, _______, KC_LBRC, KC_RBRC, KC_QUOT,
                                                                    KC_VOLD, KC_VOLU,
                                                                    KC_MUTE,
                                                                    _______, _______,   KC_SPC
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
