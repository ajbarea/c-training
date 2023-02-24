#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
	char* product;
	char* user;
	int userId;
	double balance;
	double price;
	double tax;
	char* region;
	char* category;
	double margin;
	struct Order* next;
};

// print linked list
void printList(struct Order* o) {
	int counter = 0;
	while (o != NULL) {
		printf("  --Order %d--\n%d | %s | %lf | %s %s | %lf | %s\n\n", 
		++counter, o->userId, o->user, o->balance, o->region, o->product, o->price, o->category);
		o = o->next;
	}
}

// free memory allocated for strdup and order nodes
void freeOrder(struct Order* o) {
	free(o->product);
	free(o->user);
	free(o->region);
	free(o->category);
	free(o);
}

// free all memory allocated
void freeList(struct Order* head) {
	struct Order* curr = head;
	struct Order* next = NULL;

	while(curr != NULL) {
		next = curr->next;
		freeOrder(curr);
		curr = next;
	}
}

int main() {
	struct Order* head = NULL;
	struct Order* tail = NULL;

	FILE* file;

	file = fopen("50000_Orders_TXT.txt", "r");
	if(file == NULL) {
		printf(">> ERROR file creation fopen");
		return -1;
	}
	
	char product[100];
	char user[100];
	int userId;
	double balance;
	double price;
	double tax;
	char region[100];
	char category[100];
	double margin;

	while(fscanf(file, "%[^,],%[^,],%d,%lf,%lf,%lf,%[^,],%[^,],%lf", product , user, &userId, &balance, &price, &tax, region, category, &margin) == 9) {
		struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
		
		newOrder->product = strdup(product);
		newOrder->user = strdup(user);
		newOrder->userId = userId;
		newOrder->balance = balance;
		newOrder->price = price;
		newOrder->tax = tax;
		newOrder->region = strdup(region);
		newOrder->category = strdup(category);
		newOrder->margin = margin;
		newOrder->next = NULL;

		if(head == NULL) {
			head = newOrder;
			tail = head;
			continue;
		}
		tail->next = newOrder;
		tail = tail->next;
	}

	// print linked list
	printList(head);
	
	// free allocated memory
	freeList(head);
	
	// close file
	fclose(file);

	return 0;
}
