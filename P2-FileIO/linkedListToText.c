Here is a possible C program that prints out a linked list to a text file:

// A simple C program to print out a linked list to a text file
#include <stdio.h>
#include <stdlib.h>

// A node of the linked list
struct Node {
  int data; // Data field
  struct Node* next; // Pointer to the next node
};

// A function to create a new node with a given data
struct Node* newNode(int data) {
  // Allocate memory for the node
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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
void printList(struct Node* head, char* filename) {
  // Open the file in write mode
  FILE* file = fopen(filename, "w");
  // Check if the file opening was successful
  if (file == NULL) {
    printf("File opening failed\n");
    exit(1);
  }
  // Traverse the linked list and print each node's data to the file
  struct Node* temp = head;
  while (temp != NULL) {
    fprintf(file, "%d\n", temp->data);
    temp = temp->next;
  }
  // Close the file
  fclose(file);
}

// A function to free the memory allocated for the linked list
void freeList(struct Node* head) {
  // Traverse the linked list and free each node
  struct Node* temp = head;
  while (temp != NULL) {
    struct Node* next = temp->next;
    free(temp);
    temp = next;
  }
}

// A main function to test the program
int main() {
  // Create a sample linked list
  struct Node* head = newNode(10);
  head->next = newNode(20);
  head->next->next = newNode(30);
  head->next->next->next = newNode(40);
  // Print the linked list to a text file
  printList(head, "list.txt");
  // Free the memory allocated for the linked list
  freeList(head);
  // Return 0 to indicate successful execution
  return 0;
}