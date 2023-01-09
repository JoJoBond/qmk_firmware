/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#ifdef BLUETOOTH_ENABLE
#include "iton_bt.h"
#include "outputselect.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN,
    FN2,
};

enum custom_keycodes {
    KC_MISSION_CONTROL = K5_SAFE_RANGE,
    KC_LAUNCHPAD
};

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_MCTL KC_MISSION_CONTROL  // Mission Control
#define KC_LPAD KC_LAUNCHPAD        // Launchpad

#define BT_PRO1 BT_PROFILE1
#define BT_PRO2 BT_PROFILE2
#define BT_PRO3 BT_PROFILE3

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_CORT LGUI(KC_C)          // Windows Cortana voice prompt
#define KC_SNIP LGUI(LSFT(KC_S))    // Windows snip tool
#define KC_W_FN MO(WIN_FN)          // Windows Fn

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool
#define KC_SIRI LGUI(KC_SPC)        // Mac Siri voice prompt
#define KC_M_FN MO(MAC_FN)          // Mac Fn


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Windows layout
    +-----------------------------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|CORT| BL |                     |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP| |NLCK| P/ | P* | P- |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN| | P7 | P8 | P9 |    |
    +--------------------------------------------------------------------------+ +--------------+ +--------------+ P+ |
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                  | P4 | P5 | P6 |    |
    +--------------------------------------------------------------------------+      +----+      +-------------------+
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |      | P1 | P2 | P3 |    |
    +--------------------------------------------------------------------------+ +--------------+ +---------------PRET|
    |LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT | |   P0    | .  |    |
    +-----------------------------------------------------------------------------------------------------------------+
    */

    [WIN_BASE] = LAYOUT_fullsize_ansi( \
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_CORT,  RGB_MOD,                                     \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                KC_P4,   KC_P5,   KC_P6,            \
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  KC_W_FN,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT           \
    ),

    [WIN_FN] = LAYOUT_fullsize_ansi( \
        QK_BOOT,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,   BL_INC,   BL_DEC,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNIP,  _______,  RGB_TOG,                                        \
        BT_PAIR,  BT_PRO1,  BT_PRO2,  BT_PRO3,  BT_PAIR,  _______,  _______,  _______,  _______,  _______,  BT_PAIR,  _______,  _______,  _______,  _______,  RGB_M_P,  RGB_SPI, _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD, _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                               _______,  _______,  _______,           \
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            RGB_SAI,           _______,  _______,  _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  RGB_HUD,  RGB_SAD,  RGB_HUI, _______,            _______            \
    ),

    /*  Mac layout
    +-----------------------------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|SIRI| BL |                     |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP| |NLCK| P/ | P* | P- |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN| | P7 | P8 | P9 |    |
    +--------------------------------------------------------------------------+ +--------------+ +--------------+ P+ |
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                  | P4 | P5 | P6 |    |
    +--------------------------------------------------------------------------+      +----+      +-------------------+
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |      | P1 | P2 | P3 |    |
    +--------------------------------------------------------------------------+ +--------------+ +---------------PRET|
    |LCTRL| LALT| LGUI |            SPACE            | RGUI| RALT | FN | RCTRL | |LFT |DWN |RGT | |   P0    | .  |    |
    +-----------------------------------------------------------------------------------------------------------------+
    */

    [MAC_BASE] = LAYOUT_fullsize_ansi( \
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MSCR,  KC_SIRI,  BL_STEP,                                     \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                KC_P4,   KC_P5,   KC_P6,            \
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  KC_RALT,  KC_M_FN,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT           \
    ),

    [MAC_FN] = LAYOUT_fullsize_ansi( \
        QK_BOOT,            KC_BRID,  KC_BRIU,  KC_MSSN,  KC_FIND,   BL_INC,   BL_DEC,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MSNP,  _______,  BL_TOGG,                                        \
        _______,  BT_PRO1,  BT_PRO2,  BT_PRO3,  BT_PAIR,  _______,  _______,  _______,  _______,  _______,  BT_PAIR,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                               _______,  _______,  _______,           \
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,           _______,  _______,  _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,            _______            \
    )
};

void iton_bt_connection_successful() {
    set_output(OUTPUT_BLUETOOTH);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: // macos/windows togggle
            if (active) { //macos
                layer_move(MAC_BASE);
            } else { //windows
                layer_move(WIN_BASE);
            }
            break;

        case 1:
            #ifdef BLUETOOTH_ENABLE
            if (active) {
                set_output(OUTPUT_USB);
            } else {
                set_output(OUTPUT_NONE);
            }
            #endif
        break;
    }
    return true;
}

