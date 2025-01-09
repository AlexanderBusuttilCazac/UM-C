#include <stdio.h>

typedef struct {
    char title[40];
    char author[40];
    float price;
} Book;

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
    if (fp == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }
    fwrite(&book1, sizeof(Book), 1, fp);
    fwrite(&book2, sizeof(Book), 1, fp);
    fclose(fp);
	
    Book read_book1, read_book2;
    Book books[10];
    books[0] = book1;
    printf("%s", book1.title);
	
    fp = fopen("book.dat", "rb");
    if (fp == NULL) {
        perror("Unable to open file for reading");
        return 1;
    }
    fread(&read_book1, sizeof(Book), 1, fp);
    fread(&read_book2, sizeof(Book), 1, fp);
    fclose(fp);
	
    printf("\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n\n", read_book1.title, read_book1.author, read_book1.price);
    printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n", read_book2.title, read_book2.author, read_book2.price);
}
