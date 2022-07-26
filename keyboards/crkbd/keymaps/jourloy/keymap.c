#include QMK_KEYBOARD_H
#include "keycodes.h"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

enum {
  A_CMD = 0
};


int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_VOLU,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                         KC_J,    KC_L,    KC_U,    KC_O,  KC_QUOTE, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFT_MUTE, KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                         KC_M,    KC_N,    KC_E,    KC_L,    KC_I, KC_SCOLON,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_VOLD,  KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,                         KC_K,    KC_H,  KC_COMMA, KC_DOT, KC_SLSH,  ADJ_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                     LT(1, KC_TAB), LT(2, KC_SPACE), LT(3, KC_ENT),     LT(3, KC_ENT), LT(2, KC_BSPACE), LT(1, KC_ESCAPE)
                                      //|--------------------------|  |--------------------------|


  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_ANGL, KC_ANGR, KC_LPRN, KC_RPRN, KC_PGUP,                      KC_MINS, KC_LEFT, KC_UP,   KC_RIGHT,KC_PLUS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PGDOWN,                    KC_UNDS, KC_HOME, KC_DOWN, KC_END,  XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, LOW_DEL, _______
                                      //|--------------------------|  |--------------------------|
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_PIPE, KC_EXLM, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, XXXXXXX,                      XXXXXXX, KC_UNDS, KC_EQL,  KC_ANGL, KC_ANGR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, XXXXXXX,                      XXXXXXX, KC_MINS, KC_PLUS, XXXXXXX, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //|--------------------------|  |--------------------------|
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, CK_RST,  CK_DOWN, CK_UP,   CK_TOGG, RGB_TOG,                       MU_TOG, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                       MU_MOD, KC_F11,  KC_F4,   KC_F5,   KC_F6,   RESET,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGBRST,                        AU_TOG, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, KC_VOLD, KC_VOLU \
                                      //|--------------------------|  |--------------------------|
  )
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

// https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md

// A and GUI

static tap atap_state = {
  .is_press_action = true,
  .state = 0
};

void a_finished (qk_tap_dance_state_t *state, void *user_data) {
  atap_state.state = cur_dance(state);
    switch (atap_state.state) {
      case SINGLE_TAP: register_code(KC_A); break;
      case SINGLE_HOLD: register_code(KC_LGUI); break;
    }
}

void a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (atap_state.state) {
    case SINGLE_TAP: unregister_code(KC_A); break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
  }
  atap_state.state = 0;
}

// R and ALT

static tap rtap_state = {
  .is_press_action = true,
  .state = 0
};

void r_finished (qk_tap_dance_state_t *state, void *user_data) {
  rtap_state.state = cur_dance(state);
    switch (rtap_state.state) {
      case SINGLE_TAP: register_code(KC_R); break;
      case SINGLE_HOLD: register_code(KC_LALT); break;
    }
}

void r_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (rtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_R); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
  }
  rtap_state.state = 0;
}

// S and CTRL

static tap stap_state = {
  .is_press_action = true,
  .state = 0
};

void s_finished (qk_tap_dance_state_t *state, void *user_data) {
  stap_state.state = cur_dance(state);
    switch (stap_state.state) {
      case SINGLE_TAP: register_code(KC_S); break;
      case SINGLE_HOLD: register_code(KC_LCTRL); break;
    }
}

void s_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (stap_state.state) {
    case SINGLE_TAP: unregister_code(KC_S); break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
  }
  stap_state.state = 0;
}

// T and SHIFT

static tap ttap_state = {
  .is_press_action = true,
  .state = 0
};

void t_finished (qk_tap_dance_state_t *state, void *user_data) {
  ttap_state.state = cur_dance(state);
    switch (ttap_state.state) {
      case SINGLE_TAP: register_code(KC_T); break;
      case SINGLE_HOLD: register_code(KC_LSHIFT); break;
    }
}

void t_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ttap_state.state) {
    case SINGLE_TAP: unregister_code(KC_T); break;
    case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
  }
  ttap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [A_CMD]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,a_finished, a_reset),
  [R_ALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,r_finished, r_reset),
  [S_CTRL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s_finished, s_reset),
  [T_SHIFT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,t_finished, t_reset)
};

// clang-format off

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
layer_state_t layer_state_set_user(layer_state_t state) {
    /* For any layer other than default, save current RGB state and switch to layer-based RGB */
    if (layer_state_cmp(state, 0)) {
        restore_rgb_config();
    } else {
        uint8_t layer = get_highest_layer(state);
        if (layer_state_cmp(layer_state, 0)) save_rgb_config();
        rgb_by_layer(layer);
    }
    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
        add_keylog(keycode);
    }
#endif

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_MOD:
        case RGB_TOG:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            /* Override layer-based RGB and resume RGB effect to be able to preview changes */
            if (record->event.pressed) {
                restore_rgb_config();
                process_rgb(keycode, record);
                save_rgb_config();
            }
            return false;
        case RGBRST:
            if (record->event.pressed) {
#    ifdef RGBLIGHT_ENABLE
                eeconfig_update_rgblight_default();
                rgblight_enable();
#    elif RGB_MATRIX_ENABLE
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
#    endif
                save_rgb_config();
            }
            return false;
#endif
    }
    return true;
}

