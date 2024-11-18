#include <stdio.h>
#include <string.h>

void hex();
void reverseString();

void hex(){
	int in;
	
	printf("Please enter decimal number to be converted to hexadecimal: ");
	scanf("%i", &in);
	
	printf("That number converts to %X.", in);
}
void reverseString(){
	char buffer[32];
	char reversedBuffer[32];
	
	printf("\n\nPlease enter string to be reversed: ");
	getchar(); // discard newline character \n
	fgets(buffer, 32, stdin);
	
	int endOfBuffer;
	for(int i=0; i<=32; i++){
		if(buffer[i] == '\0'){
			printf("\\0 terminator found at position %i.\n", i);
			endOfBuffer = i;
			break;
		}
	}
	
	if(endOfBuffer % 2 == 0){
		endOfBuffer -= 2;
		for(int i=0; i <= ((endOfBuffer / 2) - 1), endOfBuffer >= (endOfBuffer / 2); i++, endOfBuffer--){
			reversedBuffer[i] = buffer[endOfBuffer];
			reversedBuffer[endOfBuffer] = buffer[i];
		}
	}else{
		endOfBuffer--;
		for(int i=0; i <= ((endOfBuffer / 2) - 1), endOfBuffer >= ((endOfBuffer / 2) + 1); i++, endOfBuffer--){
			reversedBuffer[i] = buffer[endOfBuffer];
			reversedBuffer[endOfBuffer] = buffer[i];
		}
	}
	printf("reversed array: %s", reversedBuffer);
}