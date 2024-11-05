#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	FILE *input; 
	
	input = fopen("input.txt", "r");
	if(input == NULL){
		perror("Input file corrupted or not found");
		fclose(input);
		return 1;
	}
	
	int endOfArray;
	char text[128];
	for(int i=0; i<128; i++){
		if((text[i] = fgetc(input)) != EOF){
			printf("%c", text[i]);
		}else{
			endOfArray = i;
			break;
		}
		endOfArray = 128;
	}
	fclose(input);
	
	int countErrors;
	int wordBeginningIndex;
	bool firstCharIsAlpha = true;
	bool hasHyphen = false;
	bool hasUpper = false;
	
	for(int i=0; i<endOfArray; i++){
		if(text[i] == ' '){
			if(!firstCharIsAlpha){
				printf("\nWARNING: The first character in \"");
				for(int j=0; j<(i - wordBeginningIndex); j++) printf("%c", text[j+wordBeginningIndex]);
				printf("\" is not in the alphabet.");
				countErrors++;
			}
			if(hasUpper){
				printf("\nWARNING: A character past the first character in \"");
				for(int j=0; j<(i-wordBeginningIndex); j++) printf("%c", text[j+wordBeginningIndex]);
				printf("\" is not a lowercase character.");
				countErrors++;
			}
			if(!hasHyphen){
				if(((i) - wordBeginningIndex) > 10){
					printf("\nWARNING: \"");
					for(int j=0; j<(i-wordBeginningIndex); j++) printf("%c", text[j+wordBeginningIndex]);
					printf("\" is larger than 10 characters and does not include a hyphen.");
					countErrors++;	
				}
			}
			firstCharIsAlpha = true;
			hasUpper = false;
			hasHyphen = false;
			wordBeginningIndex = i+1;
		}else{
			if(i == wordBeginningIndex && !isalpha(text[i])) firstCharIsAlpha = false;
			if(i != wordBeginningIndex && isupper(text[i])) hasUpper = true;
			if(text[i] == '-') hasHyphen = true;
		}
	}
	
	if(countErrors == 0) printf("\n\nThe text file has 0 errors.");
	if(countErrors == 1) printf("\n\nThe text file has 1 error.");
	if(countErrors > 1) printf("\n\nThe text file has %i errors.", countErrors);
}