#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char title[40];
	char author[40];
	float price;
} Book;

typedef struct{
	long offset;
	Book book;
} BookIndex;

void generateIndexes(const char *filename, BookIndex **indexes, int *count){
	FILE *file = fopen(filename, "rb");
	if(file == NULL){
		perror("Unable to open file for reading");
		return;
	}
	
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	*count = fileSize / sizeof(Book);
	*indexes = (BookIndex *)malloc(*count * sizeof(BookIndex));
	
	for(int i = 0; i < *count; i++){
		(*indexes)[i].offset = ftell(file);
		fread(&(*indexes)[i].book, sizeof(Book), 1, file);
	}
	
	fclose(file);
}

void saveIndexes(const char *indexFile, BookIndex *indexes, int count) {
	FILE *file = fopen(indexFile, "wb");
	if (file == NULL) {
		perror("Unable to open index file for writing");
		return;
	}
	fwrite(&count, sizeof(int), 1, file);
	fwrite(indexes, sizeof(BookIndex), count, file);
	fclose(file);
}

void loadIndexes(const char *indexFile, BookIndex **indexes, int *count) {
	FILE *file = fopen(indexFile, "rb");
	if (file == NULL) {
		perror("Unable to open index file for reading");
		return;
	}
	fread(count, sizeof(int), 1, file);
	*indexes = (BookIndex *)malloc(*count * sizeof(BookIndex));
	fread(*indexes, sizeof(BookIndex), *count, file);
	fclose(file);
}

void selectionSort(BookIndex *indexes, int count, int (*compare)(Book, Book)){
	for(int i = 0; i < count - 1; i++){
		int minIdx = i;
		for(int j = i + 1; j < count; j++){
			if (compare(indexes[j].book, indexes[minIdx].book) < 0){
				minIdx = j;
			}
		}
		if(minIdx != i){
			BookIndex temp = indexes[i];
			indexes[i] = indexes[minIdx];
			indexes[minIdx] = temp;
		}
	}
}

int compareByTitle(Book a, Book b){
	return strcmp(a.title, b.title);
}

int compareByAuthor(Book a, Book b){
	return strcmp(a.author, b.author);
}

int compareByPrice(Book a, Book b){
	return (a.price > b.price) - (a.price < b.price);
}

void displayBooks(const char *filename, BookIndex *indexes, int count){
	FILE *file = fopen(filename, "rb");
	if(file == NULL){
		perror("Unable to open file for reading");
		return;
	}
	
	for(int i = 0; i < count; i++){
		fseek(file, indexes[i].offset, SEEK_SET);
		Book book;
		fread(&book, sizeof(Book), 1, file);
		printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n", book.title, book.author, book.price);
	}
	
	fclose(file);
}

int main(void){
	Book book1 = {
		"The C Programming Language",
		"Kernighan & Ritchie",
		29.99
	};
	Book book2 = {
		"Clean Code",
		"Robert C. Martin",
		24.99
	};
	
	FILE *fp = fopen("book.dat", "wb");
	if(fp == NULL){
		perror("Unable to open file for writing");
		return 1;
	}
	fwrite(&book1, sizeof(Book), 1, fp);
	fwrite(&book2, sizeof(Book), 1, fp);
	fclose(fp);
	
	BookIndex *indexes;
	int count;
	
	// Load indexes from file if available, otherwise generate them
	if(fopen("book.idx", "rb") != NULL){
		loadIndexes("book.idx", &indexes, &count);
	}else{
		generateIndexes("book.dat", &indexes, &count);
		saveIndexes("book.idx", indexes, count);
	}
	
	printf("Books sorted by title (ascending):\n");
	selectionSort(indexes, count, compareByTitle);
	displayBooks("book.dat", indexes, count);
	
	printf("Books sorted by author (ascending):\n");
	selectionSort(indexes, count, compareByAuthor);
	displayBooks("book.dat", indexes, count);
	
	printf("Books sorted by price (ascending):\n");
	selectionSort(indexes, count, compareByPrice);
	displayBooks("book.dat", indexes, count);
	
	free(indexes);
}