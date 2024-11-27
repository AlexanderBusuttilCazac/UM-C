#include <stdio.h>
#include <stdlib.h>

int* copyArray(const int* source, int size) {
    if (source == NULL || size == 0) {
        return NULL; // Return NULL for invalid inputs
    }
	
    // Allocate memory for the copy
    int* copy = (int*)malloc(size * sizeof(int));
    if (copy == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
	
    for (int i = 0; i < size; i++) {
        copy[i] = source[i];
    }
	
    return copy;
}

int main() {
    int original[] = {10, 20, 30, 40, 50};
    int size = sizeof(original) / sizeof(original[0]);
	
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");
	
    int* copiedArray = copyArray(original, size);
	
    printf("Copied array:   ");
    for (int i = 0; i < size; i++) {
        printf("%d ", copiedArray[i]);
    }
    printf("\n");
	
    free(copiedArray);
	
    return 0;
}