PROGRAM=main
OBJECTS=main.o system_stm32f30x.o startup_stm32f30x.o

TARGET_FLAGS=\
	-mcpu=cortex-m4\
	-mthumb

CFLAGS=\
	-g -Wall -Wextra\
	-I/Users/Andrey/Documents/STM/STM32F3-Discovery_FW_V1.1.0/Libraries/CMSIS/Include\
	-I/Users/Andrey/Documents/STM/STM32F3-Discovery_FW_V1.1.0/Libraries/CMSIS/Device/ST/STM32F30x/Include\
	$(TARGET_FLAGS)

LDFLAGS=\
	$(TARGET_FLAGS)\
	-Wl,-lc,-lrdimon,-Tlinker.ld

%.o: %.c
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

%.o: %.s
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

$(PROGRAM): $(OBJECTS)
	arm-none-eabi-gcc $(LDFLAGS) -o $@ $(OBJECTS)

flash:
	openocd -f board/stm32f3discovery.cfg -c "program $(PROGRAM) verify reset exit"

debug:
	arm-none-eabi-gdb -ex "target remote localhost:4242" $(PROGRAM)

clean:
	rm *.o main

.PHONY: flash debug clean