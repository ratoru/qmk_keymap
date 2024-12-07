/* 
Define combos here.

COMB(name, keycode_shortcut, combo_sequence...)
SSTR(name, "string to send", combo_sequence...)
ACTN(name, function_call(),  combo_sequence...)

Use the COMB macro for simple keycode shortcuts
Example: COMB(vol_up, KC_VOLU, KC_Y, KC_U).

Use the SSTR macro for sending strings
Example: SSTR(which, "which ", KC_W, KC_H).

Use the ACTN macro for function callbacks
Example: ACTN(rgb_tog, rgb_matrix_toggle(), KC_Z, KC_X)
*/

// Macros
SSTR(vi_quit,  ":wq",    KC_Q,    KC_W)
SSTR(vi_save,  ":q!",    KC_Q,    KC_F)

// Simple keycodes
//   name      result           chord keys
COMB(O_LSHIFT,  OSM(MOD_LSFT),   KC_T, KC_G)
COMB(O_RSHIFT,  OSM(MOD_RSFT),   KC_N, KC_M)
COMB(IDX_ESC,  KC_ESC,          KC_D, KC_H)
COMB(CMD_SPC,  LGUI(KC_SPC),    KC_G, KC_M)
