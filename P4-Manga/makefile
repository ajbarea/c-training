CC := gcc
CFLAGS := -Wall -g

.PHONY: all clean run

all: manga

manga: mangaReader.o
	$(CC) $(CFLAGS) -o $@ $^        
# @ = manga 
# ^ = mangaReader.o

mangaReader.o: mangaReader.c
	$(CC) $(CFLAGS) -c $<

run: manga 
	./manga

clean: 
	rm -vf manga mangaReader.o
