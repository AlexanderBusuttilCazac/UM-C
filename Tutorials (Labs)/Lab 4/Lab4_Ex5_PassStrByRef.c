#include <stdio.h> // This is my first program using the proper C naming conventions.
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void ManipulateString(char buffer[]);

void ManipulateString(char buffer[]){
	int size = 0;
	
	while(buffer[size] != '\0'){
		if(isdigit(buffer[size])) printf("WARNING: char '%c' at position %i is a digit.\n", buffer[size], size);
		size++;
	}
	
	printf("size = %i\n", size);
	printf("first character = %c\n", buffer[0]);
	
	char mostFrequent;
	int count = 1, modeCount = 1, nextFreeIndex = 0;
	char modeArray[10];
	for(int i = 1; i < size; i++)
	{
		if (buffer[i-1] == buffer[i]){
			count++;
		}else{
			if(count > modeCount){
				modeArray[0] = buffer[i-1];
				modeCount = count;
				nextFreeIndex = 1;
				count = 1;
			}
			else if(count == modeCount && modeCount > 1){
				modeArray[nextFreeIndex] = buffer[i-1];
				nextFreeIndex++;
				count = 1;
			}
			else if(count < modeCount){
				count = 1;
			}
		}
	}
	if(modeCount == 1) printf("\nMode: NO MODE");
	else if(nextFreeIndex == 1){
		printf("\nMode: %c", modeArray[0]);
	}else{
		printf("\nModes: ");
		for(int i = 0; i < nextFreeIndex - 1; i++) printf("%c, ", modeArray[i]);
		printf("%c", modeArray[nextFreeIndex-1]);
	}
}