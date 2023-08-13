#pragma once
#include QMK_KEYBOARD_H

#ifdef TAPPING_TERM
#define IS_HOMEROW(r)        (r->event.key.row == 1 || r->event.key.row == 5)

#define IS_UNILATERAL_TAP(r, n) ((r->event.key.col != n.event.key.col) && (    \
    (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
    (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) ))

#define IS_BILATERAL_TAP(r, n) ( \
    (r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || \
    (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2) )
#endif

#ifdef COMBO_ENABLE
#include "combos.h"
#endif
