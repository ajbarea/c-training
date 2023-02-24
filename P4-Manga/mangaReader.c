/*
This program reads data from a file called manga.txt and creates a linked list of Manga structs. 
Each Manga struct contains the title, author and year of publication of a manga series. The program 
prints out the data from the file and from the linked list, and then frees the memory allocated 
for each Manga struct.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Manga {
	char* title;
	char* author;
	int year;
	struct Manga* next;
};

// printList prints out the linked list of Mangas
void printList(struct Manga* m) {
	int counter = 0;
	while (m != NULL) {
		printf("%d. %s - %s - %d\n",++counter, m->title, m->author, m->year);
		m = m->next;
	}
}

// freeManga is used to free memory allocated for a Manga
void freeManga(struct Manga* m) {
	free(m->title);
	free(m->author);
	free(m);
}

int main() {
	struct Manga* head = NULL; // pointer to first manga node
	struct Manga* tail = NULL; // pointer to last manga node

	FILE * file;

	// open manga.txt for reading and check success
	file = fopen("manga.txt", "r");
	if(file == NULL) {
		printf(">> ERROR file creation fopen");
		return -1;
	}
	
	// buffers for manga data
	char manga[100];
	char author[100];
	int year;
	int counter = 0;

	// read manga title, author, and year from manga.txt until EOF
	printf("\n>> MANGA.TXT\n");
	while(fscanf(file, "%[^,],%[^,],%d\n", manga, author, &year) == 3) {
		counter++;
		printf("%d. %s,%s,%d\n", counter, manga, author, year); // debug print

		// allocate memory for new manga node
		struct Manga* newManga = (struct Manga*)malloc(sizeof(struct Manga));
		newManga->title = strdup(manga); // copy string values into manga
		if(newManga->title == NULL) { // check if strdup failed
			printf(">> ERROR string duplication newManga->title\n");
			freeManga(newManga); // free partially allocated manga node
			return -1;
		}
		newManga->author = strdup(author);
		if(newManga->author == NULL) { // check if strdup failed
			printf(">> ERROR string duplication newManga->author\n");
			freeManga(newManga); // free partially allocated manga node
			return -1;
		}
		newManga->year = year;
		newManga->next = NULL;

		// check if linked list is empty
		if(head == NULL) {
			head = newManga; // set head and tail as newly created manga
			tail = head; 
			continue;
		}
		tail->next = newManga; // append new manga to linked list
		tail = tail->next; // update tail pointer
	}

	printf("\n>> LINKED LIST\n");
	
	printList(head); // print linked list

	// iterate through linked list to free allocated memory
	struct Manga* currentManga = head;
	struct Manga* nextManga = NULL;
	while(currentManga != NULL) {
		nextManga = currentManga->next;
		freeManga(currentManga);
		currentManga = nextManga;
	}

	fclose(file); // close file

	return 0;
}
