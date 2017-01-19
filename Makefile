.SUFFIXES : .c .o

CC = gcc

INC = ./INCLUDE
LIB = libjsmn.a
OBJ = cia.o
SRC = cia.c

CFLAGS = -W -Wall -Wformat=2 -Wstrict-aliasing=2 -O2 -I $(INC)
LFLAGS =
TARGET = cia

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIB)

module: 

clean : 
	rm $(OBJ) $(TARGET)
