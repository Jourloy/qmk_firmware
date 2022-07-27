#pragma once

// Hand configuration
#define MASTER_LEFT

// Utils
#define USE_SERIAL_PD2

// Tap dance
#define TAPPING_TERM 185

// WPN
#define SPLIT_WPM_ENABLE

// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// RGB
#ifdef RGBLIGHT_ENABLE
#   undef RGBLED_NUM
#   define RGBLED_NUM 27
#   define RGBLIGHT_SPLIT
#   define RGBLIGHT_LIMIT_VAL 155
#   define RGBLIGHT_HUE_STEP 10
#   define RGBLIGHT_SAT_STEP 17
#   define RGBLIGHT_VAL_STEP 17
#endif

// Optimisation
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
