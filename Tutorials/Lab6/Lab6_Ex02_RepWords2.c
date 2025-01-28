#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

void replaceWords(const char *inputFile, const char *outputFile, const char *oldWord, const char *newWord){
	FILE *inFile = fopen(inputFile, "r");
	FILE *outFile = fopen(outputFile, "w");
	char word[MAX_WORD_LEN];
	int c, i = 0;
	
	if(inFile == NULL || outFile == NULL){
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	
	while((c = fgetc(inFile)) != EOF){
		if(c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?') {
			word[i] = '\0';
			if(strcmp(word, oldWord) == 0){
				fputs(newWord, outFile);
			}else{
				fputs(word, outFile);
			}
			fputc(c, outFile);
			i = 0;
		}else{
			word[i++] = c;
		}
	}
	
	if(i > 0){
		word[i] = '\0';
		if(strcmp(word, oldWord) == 0){
			fputs(newWord, outFile);
		}else{
			fputs(word, outFile);
		}
	}
	
	fclose(inFile);
	fclose(outFile);
}

int main(){
	char inputFile[256], outputFile[256], oldWord[MAX_WORD_LEN], newWord[MAX_WORD_LEN];
	
	printf("Enter the input file path: ");
	scanf("%255s", inputFile);
	printf("Enter the output file path: ");
	scanf("%255s", outputFile);
	printf("Enter the word to be replaced: ");
	scanf("%99s", oldWord);
	printf("Enter the new word: ");
	scanf("%99s", newWord);
	
	replaceWords(inputFile, outputFile, oldWord, newWord);
}