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
	bool firstCharIsAlpha = true, hasHyphen = false, hasUpper = false, punctAfterSpace = false, repeatedSpace = false;
	
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
				punctAfterSpace = false;
				countErrors++;	
			}
			if(repeatedSpace){
				printf("\nWARNING: There is at least one extra space within: \"");
				for(int j=0; j<(i-previousWordBeginningIndex); j++) printf("%c", text[j+previousWordBeginningIndex]);
				printf("\".");
				repeatedSpace = false;
				countErrors++;	
			}
			
			firstCharIsAlpha = true;
			hasUpper = false;
			hasHyphen = false;
			previousWordBeginningIndex = wordBeginningIndex;
			wordBeginningIndex = i+1;
			
		}else{
			if(i == wordBeginningIndex && !isalpha(text[i])) firstCharIsAlpha = false;
			if(i != wordBeginningIndex && isupper(text[i])) hasUpper = true;
			if(text[i] == '-') hasHyphen = true;
			if(i == wordBeginningIndex && text[i] == ('.' || ',' || '!' || '?')) punctAfterSpace = true;
			if(text[i-1] == ' ' && text[i] == ' ') repeatedSpace = true;
		}
	}
	
	if(countErrors == 0) printf("\n\nThe text file has 0 errors.");
	if(countErrors == 1) printf("\n\nThe text file has 1 error.");
	if(countErrors > 1) printf("\n\nThe text file has %i errors.", countErrors);
}