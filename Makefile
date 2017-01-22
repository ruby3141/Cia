.SUFFIXES : .c .o

CC = gcc

INC = ./INCLUDE
LIB = libjsmn.a
OBJ = cia.o confparse.c
SRC = cia.c confparse.c

CFLAGS = -W -Wall -Wformat=2 -Wstrict-aliasing=2 -O0 -g -I $(INC)
LFLAGS =
TARGET = cia

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIB)

module: 

clean : 
	rm $(OBJ) $(TARGET)
