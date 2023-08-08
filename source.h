#pragma once
#include QMK_KEYBOARD_H

#define IS_HOMEROW(r)        (r->event.key.row == 1 || r->event.key.row == 5)

#define IS_UNILATERAL_TAP(r, n) ((r->event.key.col != n.event.key.col) && (    \
    (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
    (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) ))

#define IS_BILATERAL_TAP(r, n) ( \
    (r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || \
    (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2) )


#ifdef COMBO_ENABLE
// Define combos here. Currently a dummy for instant tap to compile.
#define C_ENUM(name, val, ...) name,
#define C_DATA(name, val, ...) uint16_t const name##_combo[] PROGMEM = {__VA_ARGS__, COMBO_END};
#define C_TYPE(name, val, ...) [name] = COMBO(name##_combo, val),
#define UNUSED(...)

#define COMB C_ENUM
enum combos {
    COMB(oshift,  OSM(KC_LSFT), KC_SPC, KC_BSPC)
};

#undef COMB
#define COMB C_DATA
COMB(oshift,  OSM(KC_LSFT), KC_SPC, KC_BSPC)

#undef COMB
#define COMB C_TYPE
combo_t key_combos[] = {
    COMB(oshift,  OSM(KC_LSFT), KC_SPC, KC_BSPC)
};

#endif
