# name of your application
APPLICATION = testLoRa

# Absolute path to the RIOT base directory
RIOTBASE ?= $(HOME)/github/RIOT-OS/RIOT

# Path to custom boards
EXTERNAL_BOARD_DIRS ?= $(HOME)/github/campusiot/RIOT-wyres/boards

# Default board
BOARD ?= wyres-base

PORT ?= /dev/ttyACM0

INCLUDEPATHS += -I./include

# Quiet compilation by default
QUIET ?= 1

# Choose the test to compile
# Possible values: TEST_LORA_UTILS, TEST_LORA_COMM
TEST ?= no_test
ifeq ($(TEST), TEST_LORA_UTILS)
    CFLAGS += -DTEST_LORA_UTILS
else ifeq ($(TEST), TEST_LORA_COMM)
    CFLAGS += -DTEST_LORA_COMM
    MODE ?= sender  # Possible values: sender, receiver
    ifeq ($(MODE), sender)
        CFLAGS += -DMODE_SENDER
    else ifeq ($(MODE), receiver)
        CFLAGS += -DMODE_RECEIVER
    else
        $(error "Unknown MODE value: $(MODE). Possible values are sender, receiver")
    endif
else
    $(error "Unknown TEST value: $(TEST). Possible values are TEST_LORA_UTILS, TEST_LORA_COMM")
endif

# Include modules
USEMODULE += od
USEMODULE += ps
USEMODULE += shell
USEMODULE += shell_cmds_default
#USEMODULE += shell_commands
USEMODULE += fmt
USEMODULE += sx127x
USEMODULE += periph_common
USEMODULE += periph_spi
USEMODULE += fmt
USEMODULE += xtimer

DRIVER ?= sx1272
USEMODULE += $(DRIVER)

# Source files
SRC += ./src/utils_LoRa.c
SRC += ./src/LoRa.c
SRC += ./tests/testLoRa.c

# Add current directory to include path (optional)
CFLAGS += -I$(CURDIR)

include $(RIOTBASE)/Makefile.include