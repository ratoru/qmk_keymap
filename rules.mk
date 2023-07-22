SRC += source.c
SRC += features/select_word.c
SRC += features/layer_lock.c

# Enable used features 
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# Reduce size
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no

# Convert from Elite-C to Liatris
CONVERT_TO=liatris

# look here for layout while compiling (not needed)
# INTROSPECTION_KEYMAP_C = source.c 
