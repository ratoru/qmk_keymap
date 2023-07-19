SRC += ratoru.c
SRC += features/select_word.c
SRC += features/layer_lock.c

CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# Reduce size
LTO_ENABLE = yes
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
# MOUSEKEY_ENABLE = no
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no 
# MAGIC_ENABLE = no

# look here for custom source codes while compiling
# INTROSPECTION_KEYMAP_C = ratoru.c 
