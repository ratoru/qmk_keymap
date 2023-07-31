#include QMK_KEYBOARD_H
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
