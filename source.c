#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/layer_lock.h"

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  SELWORD,
  LLOCK
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;
  }
  return true;
}
