# name of your application
APPLICATION = hello-world

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= ../../RIOT-OS/RIOT

EXTERNAL_BOARD_DIRS ?= ../boards

# If no BOARD is found in the environment, use this default:
BOARD ?= wyres-base

USEMODULE += periph_uart
USEMODULE += xtimer

FEATURES_REQUIRED +=  periph_uart periph_uart_modecfg

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

PORT ?= /dev/ttyACM0

# Force l'utilisation de l'OpenOCD système
OPENOCD = /usr/bin/openocd
# Force le ST-Link
OPENOCD_DEBUG_ADAPTER = stlink
# Force la config Reset qui marche pour ta carte
OPENOCD_RESET_FLAGS = -c "reset_config srst_only srst_nogate connect_assert_srst"

include $(RIOTBASE)/Makefile.include
