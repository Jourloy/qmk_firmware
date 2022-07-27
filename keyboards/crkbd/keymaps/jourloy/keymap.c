#include QMK_KEYBOARD_H
#include <stdio.h>

// Layers types
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Tap dance types
enum {
  A_TD = 0,
  R_TD,
  S_TD,
  T_TD,
  N_TD,
  E_TD,
  I_TD,
  O_TD,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [A_TD] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_LGUI),
  [R_TD] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_LALT),
  [S_TD] = ACTION_TAP_DANCE_DOUBLE(KC_S, KC_LCTRL),
  [T_TD] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_LSHIFT),
  [N_TD] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_RSHIFT),
  [E_TD] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_RCTRL),
  [I_TD] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_RALT),
  [O_TD] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_RGUI),
};


// Buttons
// ⌘  command
// ⌥  option
// ⌃  control
// ⇧/ shift
// ⇥  tab
// ⌫  backspace
// ⎋  escape
// ↩  enter
// ␣  space

// Brightness
// ☼↑ brightness up
// ☼↓ brightness down
// ☼x brightness off

// System
// ⥀  change language

// Keys
// ⇨  right
// ⇦  left
// ⇩  down
// ⇧  up

// Music
// ↞  previous track
// ↠  next track
// ▶  pause/play

// Volume
// ♫↑ volume up
// ♫↓ volume down
// ♫x volume mute

// Layers
// 1/ layer one
// 2/ layer two
// 3/ layer three

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |  ♫↑   |   Q   |   W   |   F   |   P   |   B   | |   J   |   L   |   U   |   Y   |   '   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |  ♫↓   |  ⌘/A  |  ⌥/R  |  ⌃/S  |  ⇧/T  |   G   | |   M   |  ⇧/N  |  ⌃/E  |  ⌥/I  |  ⌘/O  |   ;   |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |  ♫x   |   Z   |   X   |   C   |   D   |   V   | |   K   |   H   |   ,   |   .   |   /   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |   ⇥   |   ␣   |   ↩   | |  3/↩  |  2/⌫  |  1/⎋  |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
     KC_VOLU, KC_Q, KC_W, KC_F, KC_P, KC_B,    KC_J, KC_L, KC_U, KC_Y, KC_QUOTE, XXXXXXX,
     KC_MUTE, TD(A_TD), TD(R_TD), TD(S_TD), TD(T_TD), KC_G,    KC_M, TD(N_TD), TD(E_TD), TD(I_TD), TD(O_TD), KC_SCOLON,
     KC_VOLD, KC_Z, KC_X, KC_C, KC_D, KC_V,    KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLSH, XXXXXXX,
     KC_TAB, KC_SPACE, KC_ENT,     LT(3, KC_ENT), LT(2, KC_BSPACE), LT(1, KC_ESCAPE)
  ),

/* LOWER
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |   7   |   8   |   9   |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |   4   |   5   |   6   |   =   | |       |   ⇧   |   ⌃   |   ⌥   |   ⌘   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |   1   |   2   |   3   |   -   | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |   0   |       | |       |       |       |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_LOWER] = LAYOUT_split_3x6_3(
     XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_EQL,     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_MINS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, KC_0, XXXXXXX,    KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* RAISE
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |   [   |   ]   |   (   |   )   |       | |       |   ⇧   |   ⌃   |   ⌥   |   ⌘   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |   $   |   \   |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |   `   |       | |       |       |       |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_RAISE] = LAYOUT_split_3x6_3(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_LBRC, KC_RBRC, S(KC_9), S(KC_0), XXXXXXX,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, S(KC_4), KC_BSLS, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, KC_GRV, XXXXXXX,    KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* ADJUST
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |  ☼↑   |       |       |   ⇧   |       |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |   ⇦   |   ⇩   |   ⇨   |       | |       |   ↞   |   ▶   |   ↠   |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |  ☼↓   |       |       |       |       |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |   ⥀   |       | |       |       |       |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_ADJUST] = LAYOUT_split_3x6_3(
     KC_BRMU, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
     KC_BRMD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, CTL_T(KC_SPACE), XXXXXXX,    KC_TRNS, KC_TRNS, KC_TRNS
  )
};

// RGB

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_RED}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CYAN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    lower_layer,
    raise_layer,
    adjust_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}

// OLED

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_main(void) {

    // Layer
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // WPM
    char buf[30];
    uint8_t wpm = get_current_wpm();
    sprintf(buf, "%u \n", wpm);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(buf, false);
}

void oled_second(void) {
    oled_write_ln_P(PSTR("\nAuthor: Jourloy"), false);
    oled_write_ln_P(PSTR("Love: Nastya"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_main();
    } else {
        oled_second();
    }

    return true;
}
