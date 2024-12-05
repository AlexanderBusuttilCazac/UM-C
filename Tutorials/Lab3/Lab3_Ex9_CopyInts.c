#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    FILE *input, *output; 
	
	input = fopen("input9.txt", "r");
	if(input == NULL){
		perror("Input file corrupted or not found");
		fclose(input);
		return 1;
	}
	output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }
	
	double num;
    char buffer[50];

    while (fscanf(input, "%49s", buffer) != EOF) {
        char *endptr;
        num = strtod(buffer, &endptr);

        // Check if the entire buffer was a valid number
        if (*endptr != '\0') {
            fprintf(stderr, "WARNING: '%s' is not a valid number.\n", buffer);
            continue;
        }

        // Check if number is within the specified range
        if (num >= 10 && num <= 100) {
            fprintf(output, "%.2f\n", num);  // Write to output file with 2 decimal places
        } else {
            fprintf(stderr, "WARNING: %f is out of range.\n", num);
        }
    }
	
	fclose(input);
}