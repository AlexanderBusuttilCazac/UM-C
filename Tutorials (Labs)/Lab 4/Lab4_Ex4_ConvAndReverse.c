#include <stdio.h> // UNFINISHED CODE
#include <string.h>

void hex();
void reverseString();

int main(){
	hex();
	reverseString();
}

void hex(){
	int in;
	printf("Please enter decimal number to be converted to hexadecimal: ");
	scanf("%i", &in);
	printf("That number converts to %X.", in);
}
void reverseString(){
	char buffer[127];
	buffer[0] = 'a';
	printf("\n\nPlease enter string to be reversed: ");
	fgets(buffer, 127, stdin);
	printf("\n\n\n%s", buffer);
}