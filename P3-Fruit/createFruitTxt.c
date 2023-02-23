/*
This program creates a file named fruit.txt and writes the details of five fruits in 
comma-separated values (csv) format. The details include the name, color, and weight 
of each fruit. The program checks for errors during opening and writing the file and 
returns -1 if any error occurs.
*/

#include <stdio.h>

// define a constant for the number of fruits
#define FRUIT_COUNT 5

int main() {
	FILE* file; // declare a file pointer

	// open fruit.txt in write mode and check success
	file = fopen("fruit.txt", "w");
	if(file == NULL) {
		printf(">> ERROR: file creation fopen");
		return -1;
	}
	
	// declare arrays for fruit names, colors, and weights (in grams)
	char* fruits[] = {"apple", "banana", "orange", "grape", "strawberry"};
	char* colors[] = {"red", "yellow", "orange", "purple", "red"};
	int weights[] = {100, 120, 150, 5, 10};

	// write the fruit details to fruit.txt in csv format
	for(int i = 0; i < FRUIT_COUNT; i++) {
		fprintf(file, "%s,%s,%d\n", fruits[i], colors[i], weights[i]);
    	
		// check for errors during writing
		if(ferror(file)){
			printf(">> ERROR: file write fprintf");
			return -1;
		}
	}

	fclose(file); // close file
  
	return 0;
}
