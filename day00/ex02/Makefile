# Fréquence du microcontrôleur
# The macro F_CPU specifies the CPU frequency to be considered by the delay macros. 
# The line "F_CPU = 16000000UL" sets the value of the CPU clock frequency to 16 MHz (megaHertz), which is the clock speed of the ATmega328P microcontroller. This value is used later in the makefile when compiling the program using avr-gcc.

F_CPU = 16000000UL

RM = rm -rf

# Nom du fichier source et des fichiers générés			
SRCS =	main.c
BIN =	${SRCS:.c=.bin}
HEX = 	${SRCS:.c=.hex}

# The "all" rule specifies that the makefile should first create the hex file by compiling the source code using avr-gcc and converting the binary output to Intel Hex format using avr-objcopy.
all: hex flash

hex: ${SRCS}
	avr-gcc -mmcu=atmega328p -DF_CPU=${F_CPU} -Os ${SRCS} -o ${BIN}
	avr-objcopy -O ihex ${BIN} ${HEX}

flash:
	avrdude -c arduino -p atmega328p -b 115200 -U flash:w:${HEX}:i -P${shell ls /dev/ttyUSB0}

clean:
	${RM} ${HEX} ${BIN}