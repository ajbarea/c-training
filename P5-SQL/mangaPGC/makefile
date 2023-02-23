CC := gcc
PSQLFLAGS := -I/usr/include/postgresql

.PHONY: all clean

all: manga

# gcc -I/usr/include/postgresql -o manga manga.c -lecpg
manga: manga.c
	$(CC) $(PSQLFLAGS) -o $@  $^ -lecpg

# ecpg manga.pgc
manga.c: manga.pgc
	ecpg $^

clean: 
	rm -f manga manga.c
