CFLAGS = -Wall -g
CC = gcc

src = $(wildcard *.c)
obj = $(patsubst %.c,%.o,$(src))

main:$(obj)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) $< -c
.PHONY : clean
clean:
	rm -rf *.o
	rm -rf main
