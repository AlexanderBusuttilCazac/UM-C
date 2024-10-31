#include <stdio.h> // UNFINISHED CODE
#include <string.h>
int main(){
	char PIN[4] = "4836";
	char input[4];
	for(int i=5; i>0; i--){		
		printf("\n\nPlease enter your 4-digit PIN. You have %i tries left.\nPIN: ", i);
		scanf("%4s", input);
		if(strcmp(PIN, input)){
			printf("You have entered the right PIN and have gained access to the account. Welcome!");
			break;
		}else printf("You have entered the wrong PIN. ");
	}
}