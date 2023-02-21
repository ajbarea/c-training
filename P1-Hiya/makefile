CC := gcc
CFLAGS := -Wall -g

.PHONY: all clean

all: hiya

hiya: hello.o
	$(CC) $(CFLAGS) -o $@ $^

hello.o: hello.h

clean: 
	rm -f $@ hiya hello.o

# -------------------------------------------
# .PHONY: all clean
# all: hiya
# hiya: hello.o gcc -Wall -g -o hiya hello.o
# hello.o: hello.h gcc -Wall -g -c hello.c
# clean: rm -f clean hiya hello.o
