
#include QMK_KEYBOARD_H
// #include "g/keymap_combo.h"

#include "jona.h"
#include "unicode_map.h"

const uint16_t NONE = KC_NO;

enum custom_keycodes {
    ESC_MOV = SAFE_RANGE
};

const uint16_t PROGMEM shift_combo[] = {KC_D, KC_F, COMBO_END};
combo_t key_combos[] = {
    COMBO(shift_combo, KC_LSFT),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_MOV:
            if (record->event.pressed) {
                // when keycode LYR_F13 is pressed
                tap_code(KC_ESC);  // press the F13 key
                layer_on(MOV);          // turn on the _FN layer
            } else {
                // when keycode LYR_F13 is released
                layer_off(MOV);           // turn off the _FN layer
            }
            break;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RALT,
        ESC_MOV, KC_A, KC_S, KC_D, KC_F, KC_G,           KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
       KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(MOV),
                   KC_LGUI, KC_BSPC, OSM(MOD_RSFT),           OSL(SYM), KC_SPC, KC_ENT
    ),

    [SYM] = LAYOUT_split_3x6_3(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_PERC,
        KC_TILD, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL, KC_HASH,                KC_ASTR, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_DLR,
        TO(BASE), KC_LSFT, KC_PIPE, KC_BSLS, KC_EXLM, KC_AT,        KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, KC_SLSH, TO(MOV),
                         KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [MOV] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS
    )

    // [MOV] = LAYOUT_split_3x6_3(
    //     QK_BOOT, KC_NO, KC_COPY, KC_MS_U, KC_PSTE, KC_BRIU,        KC_WBAK, KC_WH_D, KC_WH_U, KC_WFWD, RCTL(KC_MINS), RCTL(KC_EQL),
    //     KC_TRNS, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_VOLU,
    //     TO(BASE), KC_NO, RALT(KC_Z), RALT(KC_L), RALT(KC_W),        KC_PSCR, KC_NO, KC_BTN1, KC_BTN2, KC_BTN3, KC_MUTE, TO(MOV),
    //                            KC_TRNS, KC_TRNS, TO(BASE),        OSL(SYM), KC_TRNS, KC_TRNS
    // )
};

