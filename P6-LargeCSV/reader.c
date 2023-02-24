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

// printList prints out the linked list of Orders
void printList(struct Order* o) {
	while (o != NULL) {
		printf("%s - %s - %lf\n",o->product, o->user, o->price);
		o = o->next;
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

	printf("> LINKED LIST\n");

	printList(head);

	fclose(file);

	return 0;
}
