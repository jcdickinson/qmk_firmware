// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum sporeboard_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_FN,
    LAYER_SET
};

#define TO_BASE TO(LAYER_BASE)
#define TO_NUM TO(LAYER_NUM)
#define TO_FN TO(LAYER_FN)
#define TO_SET TO(LAYER_SET)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ W │ L │ Y │ P │ B │       │ Z │ F │ O │ U │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ C │ R │ S │ T │ G │       │ M │ N │ E │ I │ A │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Q │ J │ V │ D │ K │       │ X │ H │ / │ , │ . │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Sft├───┐           ┌───┤Bsp│
      *           └───┤Ctl├───┐   ┌───┤Spc├───┘
      *               └───┤Alt│   │Num├───┘
      *                   └───┘   └───┘
      */
    [LAYER_BASE] = LAYOUT_split_3x5_3(
        KC_W,         KC_L,         KC_Y,         KC_P,    KC_B,                         KC_Z,   KC_F, KC_O,         KC_U,         KC_QUOTE,
        LGUI_T(KC_C), LCTL_T(KC_R), LALT_T(KC_S), KC_T,    KC_G,                         KC_M,   KC_N, RALT_T(KC_E), RCTL_T(KC_I), RGUI_T(KC_A),
        KC_Q,         KC_J,         KC_V,         KC_D,    KC_K,                         KC_X,   KC_H, KC_SLSH,      KC_COMM,      KC_DOT,
                                                  KC_LSFT, KC_LCTL, KC_LALT,     TO_NUM, KC_SPC, KC_BSPC
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│ ( │ ) │ < │ > │       │ - │ 7 │ 8 │ 9 │ + │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Tab│ [ │ ] │ \ │ | │       │ = │ 4 │ 5 │ 6 │ / │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Ent│ { │ } │ _ │ ; │       │ 0 │ 1 │ 2 │ 3 │ * │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Sft├───┐           ┌───┤Bsp│
      *           └───┤Alt├───┐   ┌───┤Bas├───┘
      *               └───┤Ctr│   │Fn ├───┘
      *                   └───┘   └───┘
      */
    [LAYER_NUM] = LAYOUT_split_3x5_3(
        KC_ESC,         KC_LPRN,         KC_RPRN,         KC_LT,   KC_GT,                       KC_PMNS, KC_7, KC_8,         KC_9,         KC_PPLS,
        LGUI_T(KC_TAB), LCTL_T(KC_LBRC), LALT_T(KC_RBRC), KC_BSLS, KC_PIPE,                     KC_EQL,  KC_4, RALT_T(KC_5), RCTL_T(KC_6), RGUI_T(KC_PSLS),
        KC_ENT,         KC_LCBR,         KC_RCBR,         KC_UNDS, KC_SCLN,                     KC_0,    KC_1, KC_2,         KC_3,         KC_PAST,
                                                          KC_TRNS, KC_TRNS, KC_TRNS,     TO_FN, TO_BASE, KC_BSPC
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│Pgu│ Up│Hme│Ins│       │Nxt│F7 │F8 │F9 │F12│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Tab│Lft│   │Rgt│Scr│       │Ply│F4 │F5 │F6 │F11│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Ent│Pgd│Dwn│End│Del│       │Prv│F1 │F2 │F3 │F10│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Sft├───┐           ┌───┤Bsp│
      *           └───┤Alt├───┐   ┌───┤Bas├───┘
      *               └───┤Ctr│   │Set├───┘
      *                   └───┘   └───┘
      */
    [LAYER_FN] = LAYOUT_split_3x5_3(
        KC_ESC,         KC_PGUP,         KC_UP,         KC_HOME,  KC_INS,                        KC_MNXT, KC_F7, KC_F8,         KC_F9,         KC_F12,
        LGUI_T(KC_TAB), LCTL_T(KC_LEFT), LALT_T(KC_NO), KC_RIGHT, KC_SCRL,                       KC_MPLY, KC_F4, RALT_T(KC_F5), RCTL_T(KC_F6), RGUI_T(KC_F11),
        KC_ENT,         KC_PGDN,         KC_DOWN,       KC_END,   KC_DEL,                        KC_MPRV, KC_F1, KC_F2,         KC_F3,         KC_F10,
                                                        KC_TRNS,  KC_TRNS, KC_TRNS,      TO_SET, TO_BASE, KC_BSPC
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │Bot│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │   │   │   │RGB│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │   │   │   │Clr│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤Bas├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [LAYER_SET] = LAYOUT_split_3x5_3(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, QK_CLEAR_EEPROM,
                              KC_NO, KC_NO, KC_NO,            KC_NO,  TO_BASE, KC_NO
    )
};

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
      case LAYER_NUM:
        rgb_matrix_set_color(00, RGB_WHITE);
        rgb_matrix_set_color(18, RGB_WHITE);
        break;
      case LAYER_FN:
        rgb_matrix_set_color(01, RGB_WHITE);
        rgb_matrix_set_color(19, RGB_WHITE);
        break;
      case LAYER_SET:
        rgb_matrix_set_color(02, RGB_WHITE);
        rgb_matrix_set_color(20, RGB_WHITE);
        break;
    }
    return true;
}
