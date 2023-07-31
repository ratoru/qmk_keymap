#pragma once

// Prevent recursive dynamic macros that make the keyboard unresponsive.
#define DYNAMIC_MACRO_NO_NESTING

// For tri layer functionality used in OSM
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// ---- Home row mods settings ----
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
// "Timeless" config options
#define TAP_INTERVAL_MS 100 // Instant tap setting
// Bilateral hold options
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY



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

// #define IS_HOMEROW(r)        (r->event.key.row == 1 || r->event.key.row == 5)
// #define IS_MOD_TAP_SHIFT(kc) (QK_MOD_TAP_GET_MODS(kc) & (MOD_LSFT | MOD_RSFT))
//
// #define IS_UNILATERAL_TAP(r, n) ((r->event.key.col != n.event.key.col) && (    \
//     (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
//     (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) ))
//
// #define IS_BILATERAL_TAP(r, n) ( \
//     (r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || \
//     (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2) )
#endif
