CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
LDFLAGS =
LDLIBS = 

.PHONY: all clean

all:

clean:

bin/%: obj/%.o
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

