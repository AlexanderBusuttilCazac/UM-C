#include <stdio.h>
int main(){
	int integer;
	
	printf("Please enter an integer between 0 and 127: ");
	scanf("%i", &integer); // input
	
	char c = (char) integer;
	printf("Your integer, after conversion using the character set, becomes '%c'", c); // output
}