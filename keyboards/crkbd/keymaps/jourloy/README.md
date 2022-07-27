# Jourloy's layout

**Master hand:** left

**Size:** 25946/28672 (90%, 2726 bytes free)

## How to flash
1. Compile `qmk compile -kb crkbd -km jourloy`
2. Flash `qmk flash -kb crkbd -km jourloy ` (need to flash each keyboard)

## Layers
- QWERTY - [miryoku](https://github.com/manna-harbour/miryoku/tree/master/docs/reference) layout
- LOWER - numbers, `-` and `=`
- RAISE - symbols for programming
- ADJUST - system keys

## RGB
RGB change color on each layer
- QWERTY - RED
- LOWER - CYAN
- RAISE - PURPLE
- ADJUST - GREEN

## OLED
Left oled contain information about current layer and WPM

Right oled contain user's text
