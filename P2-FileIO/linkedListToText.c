// A simple C program to print out a linked list to a text file
#include <stdio.h>
#include <stdlib.h>

// A node of the linked list
struct node {
  int data; // Data field
  struct node* next; // Pointer to the next node
};

// A function to create a new node with a given data
struct node* newNode(int data) {
  // Allocate memory for the node
  struct node* node = (struct node*)malloc(sizeof(struct node));
  // Check if the memory allocation was successful
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  // Assign the data and the next pointer
  node->data = data;
  node->next = NULL;
  // Return the node
  return node;
}

// A function to print out a linked list to a text file
void printList(struct node* head, char* filename) {
  // Open the file in write mode
  FILE* file = fopen(filename, "w");
  // Check if the file opening was successful
  if (file == NULL) {
    printf("File opening failed\n");
    exit(1);
  }
  // Traverse the linked list and print each node's data to the file
  struct node* temp = head;
  while (temp != NULL) {
    fprintf(file, "%d\n", temp->data);
    temp = temp->next;
  }
  // Close the file
  fclose(file);
}

// A function to free the memory allocated for the linked list
void freeList(struct node *head) {
  // Check if the linked list is empty
  if (head == NULL) {
    return;
  } else {
    // Traverse the linked list and free the memory of each node
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
    }
  }
}

// A main function to test the program
int main() {
  // Create a sample linked list
  struct node* head = newNode(10);
  head->next = newNode(20);
  head->next->next = newNode(30);
  head->next->next->next = newNode(40);
  // Print the linked list to a text file
  printList(head, "data.txt");
  // Free the memory allocated for the linked list
  freeList(head);
  // Return 0 to indicate successful execution
  return 0;
}
