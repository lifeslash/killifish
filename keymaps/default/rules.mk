# reduce the fiemware size
LTO_ENABLE = yes # enable link time optimization

CONSOLE_ENABLE = no # disable output debug infos
COMMAND_ENABLE = no # disable boot magic keycode
MOUSEKEY_ENABLE = yes # mouse keys
EXTRAKEY_ENABLE = no # media keys
SPACE_CADET_ENABLE = no # shift when held, ( when tapped
GRAVE_ESC_ENABLE = no # escape when pressed, ` when shift or gui are held
MAGIC_ENABLE = no # GUI and ALT/CTRL swapping feature
AVR_USE_MINIMAL_PRINTF = yes # sprintf and snprintf function optimization

# for keyboard custom settings
# RGBLIGHT_ENABLE = no
# RGB_MATRIX_ENABLE = yes
# DYNAMIC_MACRO_ENABLE = yes
# CAPS_WORD_ENABLE = yes
# TAP_DANCE_ENABLE = yes
# DYNAMIC_TAPPING_TERM_ENABLE = yes
# KEY_LOCK_ENABLE = yes


# for more tips for reducing firmware size, see this
# /docs/squeezing_avr.md