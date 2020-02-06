// make kbdfans/kbdpad/mk1:joey
// (disconnect pad and reconnect while holding down 0)
// bootloadHID -r kbdfans_kbdpad_mk1_joey.hex
//
// see readme for instructions on setting up dependencies

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    _______, LT(3, KC_BSPC),
    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,
    KC_P0,   KC_PDOT, KC_PENT),

  [1] = LAYOUT(
    _______, LT(3, KC_BSPC),
    KC_NLCK,   KC_SLSH, KC_ASTR, KC_MINS,
    KC_7,    KC_8,    KC_9,
    KC_4,    KC_5,    KC_6,    KC_PLUS,
    KC_1,    KC_2,    KC_3,
    KC_0,    KC_DOT,  KC_ENT),

  [2] = LAYOUT(
    _______, LT(3, KC_BSPC),
    KC_NLCK, KC_SLSH, KC_ASTR, KC_MINS,
    KC_7,    KC_UP,   KC_9,
    KC_LEFT, KC_5,    KC_RGHT, KC_PLUS,
    KC_1,    KC_DOWN, KC_3,
    KC_0,    KC_DOT,  KC_ENT),

  [3] = LAYOUT(
    _______, LT(3, KC_BSPC),
    _______, _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______, _______,
    DF(0),   DF(1),   DF(2),
    _______, _______, _______)
};
