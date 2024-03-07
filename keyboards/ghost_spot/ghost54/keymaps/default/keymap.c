/*
 * Copyright 2024 João Silva @https://github.com/Ghost-Spot
 *
 * This is an adaptation of several pieces of code
 * I found online, starting from a copy of a sofle,
 * as it as the same layout (minus 2 thumb keys),
 * an OLED and an encoder, on each half.
 *
 * Use this at your own discretion!
 *
 */

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"

// Assign names to the layers
enum layer_names {
    _WIN_DEFAULT,
    _WIN_NUMPAD,
    _WIN_SYMBOLS,
    _WIN_FKEYS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Pscr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ç  |  ~   |
 * |------+------+------+------+------+------|WIN+TAB|    |  Play |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |  º   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | Enter|Space | /TO(1)  /       \ TO(2)\  |Bcksp | Del  |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */

[0] = LAYOUT(
  MT(QK_BOOT, KC_ESC),KC_1,KC_2,KC_3, KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    PT_ACUT,
  KC_LSFT,LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,      KC_H,RSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(PT_CCED), PT_TILD,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    PT_COMM, PT_DOT,  PT_MINS, PT_MORD,
                    KC_ENT,  KC_SPC,  TO(1),   LGUI(KC_TAB),             KC_MPLY, TO(2),   KC_BSPC, KC_DEL
),
/*
 * NUMPAD + Navigation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |NUMLCK|   /  |   *  |   ^  |                    |      |      |      |      |      | Pscr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   €  |   7  |   8  |   9  |   -  |                    |      | PGUP |  UP  | PGDN |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   0  |   4  |   5  |   6  |   +  |-------.    ,-------|      | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------|WIN+TAB|    |  Play |------+------+------+------+------+------|
 * | Ctrl |      |   1  |   2  |   3  |   .  |-------|    |-------|      | HOME | INSRT|  END |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | Enter|Space | /TO(0)  /       \ TO(2)\  |Bcksp | Del  |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */

[1] = LAYOUT(
  KC_ESC,   _______,KC_NUM,  KC_PSLS, KC_PAST, S(PT_TILD),               _______,  _______, _______,  _______, _______, KC_PSCR,
  KC_TAB,   PT_EURO,KC_P7,   KC_P8,   KC_P9,   KC_MINS,                  _______,  KC_PGUP, KC_UP,    KC_PGDN, _______, _______,
  KC_LSFT,LGUI_T(KC_P0),LALT_T(KC_P4),LCTL_T(KC_P5),LSFT_T(KC_P6),PT_PLUS,                  _______,  KC_LEFT, KC_DOWN,  KC_RIGHT,_______, _______,
  KC_LCTL,  _______,KC_P1,   KC_P2,   KC_P3,   PT_DOT,                   _______,  KC_HOME, KC_INSERT,KC_END,  _______, _______,
                    KC_ENT,  KC_SPC,  TO(0),   LGUI(KC_TAB),             KC_MPLY,  TO(2),   KC_BSPC,  KC_DEL
),
/* Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Pscr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |   «  |   \  |  [   |                    |   ]  |   /  |   »  |   ¨  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   #  |   @  |   <  |   !  |  (   |-------.    ,-------|   )  |   ?  |   >  |   =  |  |   |      |
 * |------+------+------+------+------+------|WIN+TAB|    |  Play |------+------+------+------+------+------|
 * | Ctrl |      |      |   -  |   "  |  {   |-------|    |-------|   }  |   '  |   _  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | Enter|Space | /TO(1)  /       \ TO(0)\  |Bcksp | Del  |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[2] = LAYOUT(
  KC_ESC,    _______,   _______,_______, _______, _______,               _______,   _______,    _______,    _______,      _______,   KC_PSCR,
  KC_TAB,    _______,   _______,PT_LDAQ, PT_BSLS, ALGR(PT_8),            ALGR(PT_9),S(PT_7),    S(PT_LDAQ), ALGR(PT_PLUS),_______,   _______,
  KC_LSFT,LGUI_T(S(PT_3)),LALT_T(ALGR(PT_2)),LCTL_T(PT_LABK), LSFT_T(S(PT_1)), S(PT_8),       S(PT_9),RSFT_T(S(PT_QUOT)),LCTL_T(S(PT_LABK)),LALT_T(S(PT_0)),LGUI_T(S(PT_BSLS)),_______,
  KC_LCTL,   _______,   _______,KC_MINS, S(PT_2), ALGR(PT_7),            ALGR(PT_0),PT_QUOT,    S(PT_MINS), _______,      _______,   _______,
                     KC_ENT,  KC_SPC,    TO(1),   LGUI(KC_TAB),          KC_MPLY,   TO(0),      KC_BSPC,    KC_DEL
),
/* F Keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |  F10 |  F11 |  F12 |      |                    |      |  F22 |  F23 |  F24 |      | Pscr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |  F7  |  F8  |  F9  |      |                    |      |  F19 |  F20 |  F21 |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |  F4  |  F5  |  F6  |      |-------.    ,-------|      |  F16 |  F17 |  F18 |      |      |
 * |------+------+------+------+------+------|WIN+TAB|    |  Play |------+------+------+------+------+------|
 * | Ctrl |      |  F1  |  F2  |  F3  |      |-------|    |-------|      |  F13 |  F14 |  F15 |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | Enter|Space | /TO(1)  /       \ TO(0)\  |Bcksp | Del  |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[3] = LAYOUT(
  KC_ESC,  _______,   KC_F10, KC_F11, KC_F12,_______,              _______, KC_F22, KC_F23, KC_F24, _______, KC_PSCR,
  KC_TAB,  _______,   KC_F7,  KC_F8,  KC_F9, _______,              _______, KC_F19, KC_F20, KC_F21, _______, _______,
  KC_LSFT, LGUI_T(_______),   LALT_T(KC_F4),  LCTL_T(KC_F5),  LSFT_T(KC_F6), _______,              _______, RSFT_T(KC_F16), LCTL_T(KC_F17), LALT_T(KC_F18), LGUI_T(_______), _______,
  KC_LCTL, _______,   KC_F1,  KC_F2,  KC_F3, _______,              _______, KC_F13, KC_F14, KC_F15, _______, _______,
                      KC_ENT,  KC_SPC, TO(1),  LGUI(KC_TAB),        KC_MPLY, TO(0),  KC_BSPC,KC_DEL
)
};


// Combos

const uint16_t PROGMEM layer0to3[] = {TO(1), MO(2), COMBO_END};
const uint16_t PROGMEM layer1to3[] = {TO(0), MO(2), COMBO_END};
const uint16_t PROGMEM layer2to3[] = {TO(1), TO(0), COMBO_END};
combo_t key_combos[] = {
    COMBO(layer0to3, TO(3)),
    COMBO(layer1to3, TO(3)),
    COMBO(layer2to3, TO(3)),
};


#ifdef OLED_ENABLE
// Draw to OLED
bool oled_task_user(void) {
    //set cursor position
    oled_set_cursor(0,1);

    // Write to OLED
    oled_write("Hello World!", false);


    return false;
}
#endif
