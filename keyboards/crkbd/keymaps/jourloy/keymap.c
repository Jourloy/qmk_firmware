#include QMK_KEYBOARD_H
#include <stdio.h>

// Layers types
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
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
 * |  1/   |   Q   |   W   |   F   |   P   |   B   | |   J   |   L   |   U   |   Y   |   '   |   ♫↑  |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |   ⇥   |   A   |   R   |   S   |   T   |   G   | |   M   |   N   |   E   |   I   |   O   |   ♫x  |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |   ⌥   |   Z   |   X   |   C   |   D   |   V   | |   K   |   H   |   ,   |   .   |   /   |   ♫↓  |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |   ⌘   |   ␣   |   ⇧/  | |   ↩   |   ⌫   |   ⌃   |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
     MO(1),   KC_Q, KC_W, KC_F,    KC_P,     KC_B,           KC_J,   KC_L,      KC_U,     KC_Y,   KC_QUOTE, KC_KB_VOLUME_UP,
     KC_TAB,  KC_A, KC_R, KC_S,    KC_T,     KC_G,           KC_M,   KC_N,      KC_E,     KC_I,   KC_O,     KC_KB_MUTE,
     KC_LALT, KC_Z, KC_X, KC_C,    KC_D,     KC_V,           KC_K,   KC_H,      KC_COMMA, KC_DOT, KC_SLSH,  KC_KB_VOLUME_DOWN,
                          KC_LGUI, KC_SPACE, KC_LSHIFT,      KC_ENT, KC_BSPACE, KC_LCTRL
  ),

/* LOWER
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |   2/  |   3/  |       |       |       | |       |   1   |   2   |   3   |   \   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |   4   |   5   |   6   |   ;   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |   7   |   8   |   9   |   `   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |   ⇧/  |       | |       |   0   |       |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_LOWER] = LAYOUT_split_3x6_3(
     KC_TRNS, MO(2),   MO(3),   XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_SCLN, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, KC_GRV,  XXXXXXX,
                       XXXXXXX, KC_LSHIFT,  XXXXXXX,       XXXXXXX, KC_0,    XXXXXXX
  ),

/* RAISE
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |   3/  |       |       |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |   [   |   ]   |   (   |   )   |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |   ⇧/  |       | |       |       |       |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_RAISE] = LAYOUT_split_3x6_3(
     KC_TRNS, KC_TRNS, MO(3),   XXXXXXX, XXXXXXX,   XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,       XXXXXXX, KC_LBRC, KC_RBRC, LSFT(KC_9), LSFT(KC_0), XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                XXXXXXX, KC_LSHIFT, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* ADJUST
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |       |   ⇧   |       |       |   ☼↑  |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |   ⇦   |   ⇩   |   ⇨   |       |       |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       | |       |       |       |       |       |   ☼↓  |
 * +-------+-------+-------+-------+-------+-------+ +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       | |   ↞   |   ▶   |   ↠   |
 *                         +-------+-------+-------+ +-------+-------+-------+
 */
  [_ADJUST] = LAYOUT_split_3x6_3(
     KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BRMU,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD,
                                XXXXXXX, XXXXXXX, XXXXXXX,      KC_MPRV, KC_MPLY, KC_MNXT
  )
};

// RGB

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED},
    {6, 21, HSV_AZURE},
    {27, 6, HSV_RED},
    {33, 21, HSV_AZURE}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_RED},
    {6, 21, HSV_PURPLE},
    {27, 6, HSV_RED},
    {33, 21, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_RED},
    {6, 21, HSV_YELLOW},
    {27, 6, HSV_RED},
    {33, 21, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 6, HSV_RED},
    {6, 21, HSV_GREEN},
    {27, 6, HSV_RED},
    {33, 21, HSV_GREEN}
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
  return OLED_ROTATION_270;
}

void oled_main(void) {

    // Layer
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("qwr\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("lwr\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("rse\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Ukw"), false);
    }

    oled_write_ln_P(PSTR("-----"), false);

    // WPM
    char buf[30];
    uint8_t wpm = get_current_wpm();
    sprintf(buf, "%u \n", wpm);
    oled_write_ln_P(PSTR("WPM"), false);
    oled_write(buf, false);
}

void oled_second(void) {
    oled_write_ln_P(PSTR("JRLY"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_main();
    } else {
        oled_second();
    }

    return true;
}
