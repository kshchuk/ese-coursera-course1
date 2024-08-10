#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#
#------------------------------------------------------------------------------
include sources.mk

TARGET ?= c1m2

# Platform Overrides
PLATFORM ?= HOST

# Architectures Specific Flags
LINKER_FILE = $(if $(filter $(PLATFORM), HOST), ld, ../msp432p401r.lds)
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
OBJDUMP = $(if $(filter $(PLATFORM), HOST), objdump, arm-none-eabi-objdump)

# Compiler Flags and Defines
CC = $(if $(filter $(PLATFORM), HOST), gcc, arm-none-eabi-gcc)
LD = $(if $(filter $(PLATFORM), HOST), ld, arm-none-eabi-ld)
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = $(if $(filter $(PLATFORM), HOST), \
			-std=c99 -g -O0 -Wall, \
			-std=c99 -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -g -O0)
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)

# Define source and object files
SRCS = $(SOURCES)
OBJS = $(SRCS:.c=.o)

# Define build rules
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) -o $@

%.disasm : %.out
	$(OBJDUMP) -D $< > $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET).out $(TARGET).map $(OBJS) $(SRCS:.c=.i) $(SRCS:.c=.asm) $(SRCS:.c=.disasm)
