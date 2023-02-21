Here is a simple C program that does what you asked:

// A simple C program to read a text file and store the data in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
struct node {
  char name[20]; // To store the name
  int data; // To store the data
  struct node *next; // To store the pointer to the next node
};

// A function to create a new node and return its pointer
struct node *create_node(char *name, int data) {
  // Allocate memory for the new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  // Check if the memory allocation was successful
  if (new_node == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  // Copy the name and data to the new node
  strcpy(new_node->name, name);
  new_node->data = data;
  // Set the next pointer to NULL
  new_node->next = NULL;
  // Return the pointer to the new node
  return new_node;
}

// A function to insert a node at the end of the linked list and return the head pointer
struct node *insert_node(struct node *head, struct node *new_node) {
  // Check if the linked list is empty
  if (head == NULL) {
    // Set the new node as the head
    head = new_node;
  } else {
    // Find the last node of the linked list
    struct node *last = head;
    while (last->next != NULL) {
      last = last->next;
    }
    // Set the next pointer of the last node to the new node
    last->next = new_node;
  }
  // Return the head pointer
  return head;
}

// A function to print the linked list
void print_list(struct node *head) {
  // Check if the linked list is empty
  if (head == NULL) {
    printf("The list is empty.\n");
  } else {
    // Traverse the linked list and print the name and data of each node
    struct node *current = head;
    while (current != NULL) {
      printf("%s, %d\n", current->name, current->data);
      current = current->next;
    }
  }
}

// A function to free the memory allocated for the linked list
void free_list(struct node *head) {
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
  struct node *new_node;
  // Declare a file pointer
  FILE *fp;
  // Declare variables to store the name and data
  char name[20];
  int data;
  // Open the text file in read mode
  fp = fopen("data.txt", "r");
  // Check if the file opening was successful
  if (fp == NULL) {
    printf("File opening failed.\n");
    exit(1);
  }
  // Read the file line by line until the end of file
  while (fscanf(fp, "%[^,], %d\n", name, &data) != EOF) {
    // Create a new node with the name and data
    new_node = create_node(name, data);
    // Insert the new node at the end of the linked list
    head = insert_node(head, new_node);
  }
  // Close the file
  fclose(fp);
  // Print the linked list
  print_list(head);
  // Free the memory allocated for the linked list
  free_list(head);
  // Return 0 to indicate successful execution
  return 0;
}