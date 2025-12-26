# name of your application
APPLICATION = minitel

# Absolute path to the RIOT base directory
RIOTBASE ?= ../../RIOT-OS/RIOT

# Path to custom boards
EXTERNAL_BOARD_DIRS ?= ../../campusiot/RIOT-wyres/boards

# Default board
BOARD ?= wyres-base

PORT ?= /dev/ttyACM0

# Development helpers (enable checks, useful during dev)
DEVELHELP ?= 1

# Quiet compilation by default
QUIET ?= 1

# Include modules
USEMODULE += xtimer       # for delays
USEMODULE += periph_uart  # generic UART interface

# IMPORTANT: Désactiver stdio_uart pour libérer UART0
# On n'aura plus de console série, mais l'UART sera libre pour le Minitel
# USEMODULE += stdio      # COMMENTÉ - pas de console

# Alternative: utiliser les LEDs pour le debug
USEMODULE += periph_gpio

# pour avoir le uart_mode()
USEMODULE += periph_uart_modecfg

# Add current directory to include path (optional)
CFLAGS += -I$(CURDIR)

include $(RIOTBASE)/Makefile.include

myflash:
	/usr/bin/openocd -f interface/stlink.cfg -f target/stm32l1.cfg \
	-c "reset_config srst_only srst_nogate connect_assert_srst" \
	-c "program $(ELFFILE) verify reset exit"