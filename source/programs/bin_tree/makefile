CC=gcc
CFLAGS=-W -Wall -ansi -std=c99
LDFLAGS=
EXEC=bintree
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

bintree: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: bintree.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o *.exe


