#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	FILE *input; 
	
	input = fopen("input8.txt", "r");
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
	
	int countErrors, wordBeginningIndex, previousWordBeginningIndex;
	bool firstCharIsAlpha = 1, hasHyphen = 0, hasUpper = 0, punctAfterSpace = 0, repeatedSpace = 0;
	
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
			if(punctAfterSpace){
				printf("\nWARNING: There is punctuation right after a space within: \"");
				for(int j=0; j<(i-previousWordBeginningIndex); j++) printf("%c", text[j+previousWordBeginningIndex]);
				printf("\".");
				punctAfterSpace = 0;
				countErrors++;	
			}
			if(repeatedSpace){
				printf("\nWARNING: There is at least one extra space within: \"");
				for(int j=0; j<(i-previousWordBeginningIndex); j++) printf("%c", text[j+previousWordBeginningIndex]);
				printf("\".");
				repeatedSpace = 0;
				countErrors++;	
			}
			
			firstCharIsAlpha = 1;
			hasUpper = 0;
			hasHyphen = 0;
			previousWordBeginningIndex = wordBeginningIndex;
			wordBeginningIndex = i+1;
			
		}else{
			if(i == wordBeginningIndex && !isalpha(text[i])) firstCharIsAlpha = 0;
			if(i != wordBeginningIndex && isupper(text[i])) hasUpper = 1;
			if(text[i] == '-') hasHyphen = 1;
			if(i == wordBeginningIndex && text[i] == ('.' || ',' || '!' || '?')) punctAfterSpace = 1;
			if(text[i-1] == ' ' && text[i] == ' ') repeatedSpace = 1;
		}
	}
	
	if(countErrors == 0) printf("\n\nThe text file has 0 errors.");
	if(countErrors == 1) printf("\n\nThe text file has 1 error.");
	if(countErrors > 1) printf("\n\nThe text file has %i errors.", countErrors);
}