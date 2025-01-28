#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void replaceWordInText(char *text, const char *oldWord, const char *newWord){
    char *pos, temp[1024];
    int index = 0;
    int owlen;
	
    owlen = strlen(oldWord);
    while ((pos = strstr(text, oldWord)) != NULL){
        strcpy(temp, text);
        index = pos - text;
        text[index] = '\0';
        strcat(text, newWord);
        strcat(text, temp + index + owlen);
    }
}

int main(){
    FILE *file;
    char *buffer;
    long fileLen;
    char filePath[100];
    char oldWord[100], newWord[100];
	
    printf("Enter the file path: ");
    scanf("%s", filePath);
	
    printf("Enter the word to replace: ");
    scanf("%s", oldWord);
	
    printf("Enter the new word: ");
    scanf("%s", newWord);
	
    file = fopen(filePath, "rb");
    if(!file){
        fprintf(stderr, "Unable to open file %s\n", filePath);
        return 1;
    }
	
    fseek(file, 0, SEEK_END);
    fileLen = ftell(file);
    fseek(file, 0, SEEK_SET);
	
    buffer = (char *)malloc(fileLen + 1);
    if(!buffer){
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }
	
    fread(buffer, fileLen, 1, file);
    fclose(file);
    buffer[fileLen] = '\0';
	
    replaceWordInText(buffer, oldWord, newWord);
	
    file = fopen(filePath, "wb");
    if(!file){
        fprintf(stderr, "Unable to open file %s\n", filePath);
        free(buffer);
        return 1;
    }
	
    fwrite(buffer, fileLen, 1, file);
    fclose(file);
    free(buffer);
    printf("Word replacement completed.\n");
}