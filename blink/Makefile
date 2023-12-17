SRC=blink
CXX=avr-gcc
DIR=/..

# Compiler config
MCU=-mmcu=atmega328p
CPU_SPEED=-DF_CPU=8000000UL
CFLAGS=$(MCU) $(CPU_SPEED) -Os -w -Wl,--gc-sections -ffunction-sections -fdata-sections

# Upload config
PORT=/dev/ttyACM0
AVRDUDE_MCU=m328p
AVRDUDE_PROG=pi_1
AVRDUDE_SPEED=115200
AVRDUDE_CONFIG=-C $(DIR)/avrdude.conf
AVRDUDE_FLAGS=-F

.PHONY:
default: upload

.PHONY:
build: $(SRC).hex

$(SRC).hex: $(SRC).elf
	avr-objcopy -O ihex $< $@

$(SRC).elf: $(SRC).c
	$(CXX) $(CFLAGS) $^ -o $@
	avr-size -C $(SRC).elf

.PHONY:
upload: $(SRC).hex
	avrdude $(AVRDUDE_FLAGS) -p $(AVRDUDE_MCU) -c $(AVRDUDE_PROG) -b $(AVRDUDE_SPEED) -P$(PORT) -Uflash:w:$(SRC).hex $(AVRDUDE_CONFIG)

.PHONY:
clean:
	@echo Cleaning...
	rm -f $(SRC).elf
	rm -f $(SRC).hex
	rm -f *.o
	@echo DONE