TARGET = Sorting_Array
CC = gcc

SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
HDR = $(addprefix -I, $(shell dirname $(shell find . -name "*.h")))

CHEK  = $(echo)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.c
	$(CC) $(HDR)  -c $< -o $@

c :
	rm $(TARGET) *.o

b: 
	open $(TARGET)