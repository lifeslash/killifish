// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    MDIA,
};

enum custom_keycodes {
    LAYER_KEY,
};

#define LAYER_CYCLE_START BASE
#define LAYER_CYCLE_END   MDIA

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------.
     * |LAYER| MCTL|
     * |-----+-----+-----------,
     * | CALC| DEL |  /  |  *  |
     * |-----+-----+-----+-----|
     * |  7  |  8  |  9  |  -  |
     * |-----+-----+-----+-----|
     * |  4  |  5  |  6  |     |
     * |-----+-----+-----+  +  |
     * |  1  |  2  |  3  |-----|
     * |-----+-----+-----+     |
     * |  0  |  .  |  =  | ENT |
     * `-----------------------'
     */
    [BASE] = LAYOUT(
        LAYER_KEY,KC_MCTL,
        KC_CALC, KC_DEL,  KC_PSLS, KC_PAST,
        KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_PDOT, KC_PEQL 
    ),

    /*
     * ,-----------.
     * | TRNS| TRNS|
     * |-----+-----+-----------,
     * | UNDO| CUT | COPY| PSTE|
     * |-----+-----+-----+-----|
     * | LEFT| DOWN|  UP | RGHT|
     * |-----+-----+-----+-----|
     * | HOME| MSUP| END |     |
     * |-----+-----+-----+ WHLU|
     * | MSLF| MSDN| MSRG|-----|
     * |-----+-----+-----+     |
     * | BT1 | BT3 | BT2 | WHLD|
     * `-----------------------'
     */
    [MDIA] = LAYOUT(
        KC_TRNS, KC_TRNS,
        KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_HOME, MS_UP,   KC_END,  MS_WHLU,
        MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,
        KC_BTN1, KC_BTN3, KC_BTN2
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_UP,   KC_DOWN),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(LCTL(KC_LEFT), LCTL(KC_RIGHT)) },
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case LAYER_KEY:
        return false;
    }
  } else {
    switch (keycode) {
      case LAYER_KEY:
        {
          uint8_t current_layer = get_highest_layer(layer_state);
          if(current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
            return false;
          }
          uint8_t next_layer = current_layer + 1;
          if(next_layer > LAYER_CYCLE_END) {
            next_layer = LAYER_CYCLE_START;
          }
          layer_move(next_layer);
        }
        return false;
    }
  }
  return true;
}

