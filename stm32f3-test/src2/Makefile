TARGET = main

# Define linker script location and chip architecture
LD_SCRIPT = linker.ld
MCU_SPEC = cortex-m4

# Define extra include directories
INC = -I/Users/Andrey/Documents/GitHub/stm/stm32f3-test/src2/include

# Toolchain deffinitions
TOOLCHAIN = /Users/Andrey/Documents/GitHub/stm/gcc-arm-none-eabi-10-2020-q4-major
CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-as
LD = $(TOOLCHAIN)/bin/arm-none-eabi-ld
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size
DB = $(TOOLCHAIN)/bin/arm-none-eabi-gdb
NM = $(TOOLCHAIN)/bin/arm-none-eabi-nm

# Assembly directives
ASFLAGS += -c
ASFLAGS += -mcpu=$(MCU_SPEC)
ASFLAGS += -mthumb
ASFLAGS += -Wall

# C compiler directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += $(INC)
CFLAGS += -g
# Set system to ignore semihosted calls
CFLAGS += --specs=nosys.specs

# Linker directives
LSCRIPT = ./$(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T$(LSCRIPT)

AS_SRC = ./startup_stm32f30x.s
SYS_SRC = ./system_stm32f30x.c
C_SRC = ./main.c

# Vecor table and startup
OBJS = $(AS_SRC:.s=.o)
OBJS += $(SYS_SRC:.c=.o)
OBJS += $(C_SRC:.c=.o)

.PHONY: all
all: $(TARGET).bin

%.o: %.S
	$(CC) -x assembler-with-cpp $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET).elf