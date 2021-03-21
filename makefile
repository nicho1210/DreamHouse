CC = gcc

INC = -I ./include
LIB = -l wiringPi
OBJ = motor.OBJ light_detect.OBJ outsidebrightness.OBJ PCF8591.OBJ

# define any compile-time flags
CFLAGS = -Wall $(OBJ) -g -O

.PHONY: clean

all: dreamhouse $(OBJ)

dreamhouse : dreamhouse.c $(OBJ)
	$(CC) -Wall $(OBJ) -o $@ $< $(LIB)

motor.OBJ: motor.c
	$(CC) -Wall -c -o $@ $< $(LIB)

light_detect.OBJ: light_detect.c
	$(CC) -Wall -c -o $@ $< $(LIB)

outsidebrightness.OBJ: outsidebrightness.c
	$(CC) -Wall -c -o $@ $< $(LIB)

PCF8591.OBJ: PCF8591.c
	$(CC) -Wall -c -o $@ $< $(LIB)

clean:
	rm -f dreamhouse $(OBJ)
