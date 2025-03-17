# MCU
MCU = cortex-m0plus
ARMV = 6
USE_FPU = no
MCU_FAMILY = HT32
MCU_SERIES = HT32F523xx
MCU_LDSCRIPT = HT32F52342_ANNEPRO2
MCU_STARTUP = ht32f523xx

BOARD = ANNEPRO2_C18

# Bootloader selection
BOOTLOADER = custom
PROGRAM_CMD = annepro2_tools --boot $(BUILD_DIR)/$(TARGET).bin

# Anne Pro 2
SRC = \
	annepro2_ble.c \
	ap2_led.c \
	protocol.c \
	rgb_driver.c \


# Custom rules for my keymap
TAP_DANCE_ENABLE = yes  # Tap-hold
MOUSEKEY_ENABLE = yes  # Mouse implementation
NKRO_ENABLE = yes    # Enabling All keys to work
EXTRAKEY_ENABLE = yes  # Audio control and System control
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
AUTOCORRECT_ENABLE = yes   # Autocorrect
SEND_STRING_ENABLE = yes  # Macrosses can send strings
CAPS_WORD_ENABLE = yes    # Activating CAPS for 5 second
