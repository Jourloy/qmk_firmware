#pragma once

#define EE_HANDS

#define TAPPING_TERM 175

#ifdef OLED_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/gotham/glcdfont.c"
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_OLED_ENABLE
#    undef  OLED_TIMEOUT
        //  due to timer_read() for render_prompt(), we have own implementation of oled time out
#    define OLED_KEY_TIMEOUT 30000
#endif

#define RGBLIGHT_SLEEP

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLED_NUM 6
#    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_HUE_STEP 16
#    define RGBLIGHT_SAT_STEP 32
#    define RGBLIGHT_VAL_STEP 32
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES                // reacts to keypresses
#    define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150    // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 32
#    define RGB_MATRIX_SAT_STEP 64
#    define RGB_MATRIX_VAL_STEP 64
#    define RGB_MATRIX_SPD_STEP 20
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#endif


