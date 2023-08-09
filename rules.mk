# Uncomment this and remove introspection if you are not using combos or "timeless" hrm.
SRC += source.c
SRC += features/select_word.c
SRC += features/layer_lock.c
# Swapper does not play well with instant tap.
SRC += features/swapper.c

# Enable used features 
CAPS_WORD_ENABLE = yes
# REPEAT_KEY_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
# Uncomment below to use tri-layers. Used in my OSM and Instant Tap layouts.
TRI_LAYER_ENABLE = yes
# RGB (underglow) lighting for Liatris
RGBLIGHT_ENABLE = yes
# WS2812_DRIVER = vendor

# Uncomment below to use "timeless" homerow mods.
# COMBO_ENABLE = yes
# Look here for definitions of combos.
# INTROSPECTION_KEYMAP_C = source.c

# Reduce size
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no

# Convert from Elite-C to Liatris (did not work)
# CONVERT_TO=liatris
