#pragma once

// Prevent recursive dynamic macros that make the keyboard unresponsive.
#ifdef DYNAMIC_MARCO_ENABLE
#define DYNAMIC_MACRO_NO_NESTING
#endif

// Define layers for tri layer functionality. Used in OSM and Instant Tap.
#ifdef TRI_LAYER_ENABLE
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4
#endif

// ---- Home row mods settings ----
// Configure the global tapping term (default: 200ms)
// #define TAPPING_TERM 500
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define QUICK_TAP_TERM 0
// "Timeless" config options
// #define TAP_INTERVAL_MS 100 // Instant tap setting
// // Bilateral hold options
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Reduze size of firmware
#define LAYER_STATE_8BIT // Limit the number of layers to 8 to save firmware size.
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
                         
#ifndef __ASSEMBLER__
// Define all of custom keycodes. Needs to be protected.
#include "quantum/keycodes.h"
#define SELWORD QK_USER
#define UPDIR QK_USER + 1
#define LLOCK QK_USER + 2
#define SW_TAB QK_USER + 3
#define SW_CTAB QK_USER + 4
#define SW_BTICK QK_USER + 5
#define RGBT_NE QK_USER + 6

#define RGB_SPLIT
#define RGB_SLEEP
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_DISABLE_KEYCODES
#endif
