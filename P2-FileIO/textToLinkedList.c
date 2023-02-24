// A simple C program to read a text file and store the data in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
struct node {
  char name[20]; // To store the name
  int age; // To store the age
  struct node *next; // To store the pointer to the next node
};

// A function to create a new node and return its pointer
struct node *createNode(char *name, int age) {
  // Allocate memory for the new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  // Check if the memory allocation was successful
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  // Copy the name and age to the new node
  strcpy(newNode->name, name);
  newNode->age = age;
  // Set the next pointer to NULL
  newNode->next = NULL;
  // Return the pointer to the new node
  return newNode;
}

// A function to insert a node at the end of the linked list and return the head pointer
struct node *appendNode(struct node *head, struct node *newNode) {
  // Check if the linked list is empty
  if (head == NULL) {
    // Set the new node as the head
    head = newNode;
  } else {
    // Find the tail node of the linked list
    struct node *tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    // Set the next pointer of the tail node to the new node
    tail->next = newNode;
  }
  // Return the head pointer
  return head;
}

// A function to print the linked list
void printList(struct node *head) {
  // Check if the linked list is empty
  if (head == NULL) {
    printf("The list is empty.\n");
  } else {
    // Traverse the linked list and print the name and age for each node
    struct node *current = head;
    while (current != NULL) {
      printf("%s, %d\n", current->name, current->age);
      current = current->next;
    }
  }
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

// The main function
int main() {
  // Declare a pointer to the head of the linked list
  struct node *head = NULL;
  // Declare a pointer to a new node
  struct node *newNode;
  // Declare a file pointer
  FILE *file;
  // Declare variables to store the name and age
  char name[20];
  int age;
  // Open the text file in read mode
  file = fopen("data.txt", "r");
  // Check if the file opening was successful
  if (file == NULL) {
    printf("File opening failed.\n");
    exit(1);
  }
  // Read the file line by line until the end of file
  while (fscanf(file, "%[^,], %d\n", name, &age) != EOF) {
    // Create a new node with the name and age
    newNode = createNode(name, age);
    // Insert the new node at the end of the linked list
    head = appendNode(head, newNode);
  }
  // Close the file
  fclose(file);
  // Print the linked list
  printList(head);
  // Free the memory allocated for the linked list
  freeList(head);
  // Return 0 to indicate successful execution
  return 0;
}
