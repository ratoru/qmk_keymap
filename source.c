#include "source.h"
#include "features/select_word.h"
#include "features/layer_lock.h"
#include "features/swapper.h"

bool sw_tab_active = false;
bool sw_control_tab_active = false;
bool sw_backtick_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

  // Adds functionality to switch apps and windows.
  update_swapper(
      &sw_tab_active, KC_LGUI, KC_TAB, SW_TAB,
      keycode, record
  );
   update_swapper(
      &sw_tab_active, KC_LCTL, KC_TAB, SW_CTAB,
      keycode, record
  ); 
  update_swapper(
      &sw_backtick_active, KC_LGUI, KC_GRAVE, SW_BTICK,
      keycode, record
  );

  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;
  }
  return true;
}

// ---- Home Row Mods "Timeless" Config ----
// #if defined (PERMISSIVE_HOLD_PER_KEY) || defined (HOLD_ON_OTHER_KEY_PRESS_PER_KEY) || defined (TAP_INTERVAL_MS)
static uint16_t    next_keycode;
static keyrecord_t next_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Instant Tap Config
    static uint16_t prev_keycode;
    if (record->event.pressed) {
        // Store the previous keycode for instant tap decision
        prev_keycode = next_keycode;
        // Cache the next input for mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    // Match home row mod-tap keys when it is not preceded by a Layer key
    if (IS_HOMEROW(record) && IS_QK_MOD_TAP(keycode) && !IS_QK_LAYER_TAP(prev_keycode)) {
        // Tap the mod-tap key instantly when it follows a short interval
        if (record->event.pressed && last_input_activity_elapsed() < TAP_INTERVAL_MS) {
            record->keycode = keycode & 0xff;
            action_tapping_process(*record);
            return false;
        } else { // Send the base keycode key up event
            keyrecord_t base_record   = *record;
            base_record.keycode       = keycode & 0xff;
            base_record.event.pressed = false;
            action_tapping_process(base_record);
        }
    }
    return true;
}
// #endif

// #ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold Control and Shift with a nested key tap on the opposite hand
    return IS_BILATERAL_TAP(record, next_record);
}
// #endif


// #ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Replace the mod-tap key with its base keycode when
    // tapped with another non-Shift key on the same hand
    // if (IS_UNILATERAL_TAP(record, next_record) && !IS_MOD_TAP_SHIFT(next_keycode)) {
    if (IS_UNILATERAL_TAP(record, next_record)) {
        record->keycode = keycode & 0xff;
        process_record(record);
        record->event.pressed = false;
        process_record(record);
        return true;
    }
    // Hold layer with another key press
    else if (IS_QK_LAYER_TAP(keycode) && QK_LAYER_TAP_GET_LAYER(keycode)) {
        return true;
    }
    return false;
}
// #endif

