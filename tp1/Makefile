CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
LDFLAGS =
LDLIBS = 

.PHONY: all clean

all: bin/trieList

clean:
	$(RM) -f bin/* obj/*

bin/trieList: obj/trieList.o src/test.c

bin/%: obj/%.o
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

