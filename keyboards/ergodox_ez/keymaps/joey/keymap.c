// make ergodox_ez:joey
// run graphical teensy loader: https://www.pjrc.com/teensy/loader_mac.html

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define DBLQUOT LSFT(KC_QUOT)
#define LCURLY LSFT(KC_LBRC)
#define RCURLY LSFT(KC_RBRC)
#define LPAREN LSFT(KC_9)
#define RPAREN LSFT(KC_0)
#define UNDRSC LSFT(KC_MINS)
#define PLUS LSFT(KC_EQL)
#define CTRL_A LCTL(KC_A)

enum custom_keycodes {
  ESCFN = SAFE_RANGE,
  LANG_TG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
    ESCFN,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,
                                                 TG(3),   LANG_TG,
                                                          _______,
                                        KC_LGUI, MO(1),   KC_LCTL,
                                                                    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                                                                    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                                                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
                                                                    KC_B, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                                                      _______, _______, _______, _______, _______,
                                                                    _______, _______,
                                                                    _______,
                                                                    MO(2),   KC_RCTL, KC_SPC
  ),

  [1] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
                                                                    _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
                                                                    _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP,
                                                                             _______, _______, _______, _______, KC_QUOT, KC_PGDN,
                                                                    _______, _______, _______, _______, _______, KC_UP,   _______,
                                                                                      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______, _______
  ),

  [2] = LAYOUT_ergodox(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
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
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______, _______
  ),

  [3] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        KC_SPC,  _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                             _______, _______, _______, _______, _______, _______,
                                                                    _______, _______, _______, _______, _______, _______, _______,
                                                                                      _______, _______, _______, _______, _______,
                                                                    _______, _______,
                                                                    _______,
                                                                    _______, _______, _______
  ),
};

int escfn_down = 0;
int escfn_mod_pressed = 0;
int modded_h_pressed = 0;
int modded_j_pressed = 0;
int modded_k_pressed = 0;
int modded_l_pressed = 0;
int modded_spc_pressed = 0;
int modded_9_pressed = 0;
int modded_0_pressed = 0;
int modded_o_pressed = 0;
int modded_p_pressed = 0;
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

    case KC_SPC:
      modded_macro_press(record, KC_SPC, SS_LCTRL("a")"o", &modded_spc_pressed);
      return false;

    case KC_9:
      modded_key_press(record, KC_9, UNDRSC, &modded_9_pressed);
      return false;

    case KC_0:
      modded_key_press(record, KC_0, PLUS, &modded_0_pressed);
      return false;

    case KC_O:
      modded_key_press(record, KC_O, LCURLY, &modded_o_pressed);
      return false;

    case KC_P:
      modded_key_press(record, KC_P, RCURLY, &modded_p_pressed);
      return false;

    case KC_SCLN:
      modded_key_press(record, KC_SCLN, DBLQUOT, &modded_sc_pressed);
      return false;

    case LANG_TG:
      if (record->event.pressed) {
        send_string(SS_LGUI(SS_LALT(" ")));
      } else {
        // key released
      }
      return false;
  }

  return true;
};
