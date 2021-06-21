Issues:

1. Have to run following line before compiling - fix?

export PATH=/Users/Andrey/Documents/STM/gcc-arm-none-eabi-10-2020-q4-major/bin:$

Compile

1. Example 1

arm-none-eabi-gcc -x assembler-with-cpp -c -O0 -mcpu=cortex-m0 -mthumb -Wall core.S -o core.o

arm-none-eabi-gcc core.o -mcpu=cortex-m0 -mthumb -Wall --specs=nosys.specs -nostdlib -lgcc -T./linker.ld -o main.elf

Flash

1. Example 1

st-util <-- from Terminal
arm-none-eabi-gdb main.elf
target extended-remote :4242
load
continue
info registers

2. Example 2
make
st-util <-- from Terminal
arm-none-eabi-gdb main.elf
target extended-remote :4242
load
continue
p val

