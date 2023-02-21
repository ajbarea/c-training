#include <stdio.h>

// number of fruits to be written to fruit.txt
#define FRUIT_COUNT 5

int main() {
	FILE* file;

	// open fruit.txt in write mode and check success
	file = fopen("fruit.txt", "w");
	if(file == NULL) {
		printf(">> ERROR: file creation fopen");
		return -1;
	}
	
	// arrays for fruit names, colors, and weights (grams)
	char* fruits[] = {"apple", "banana", "orange", "grape", "strawberry"};
	char* colors[] = {"red", "yellow", "orange", "purple", "red"};
	int weights[] = {100, 120, 150, 5, 10};

	// populate fruits.txt in csv format using array details
	for(int i = 0; i < FRUIT_COUNT; i++) {
		fprintf(file, "%s,%s,%d\n", fruits[i], colors[i], weights[i]);
    	
		// check for errors during file write
		if(ferror(file)){
			printf(">> ERROR: file write fprintf");
			return -1;
		}
	}

	fclose(file); // close file
  
	return 0;
}
