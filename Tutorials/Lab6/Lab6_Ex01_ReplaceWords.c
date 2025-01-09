#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main(){
	FILE *input = fopen("replace.txt", "r+");
	if (input == NULL){
		perror("Input file corrupted or not found.");
		fclose(input);
		return 1;
	}
	
	
}