#include <stdio.h> // UNFINISHED CODE
#include <string.h>
#include <stdbool.h>

int main(){
	char PIN[4] = "4836";
	char input[4];
	bool isDifferent = true;
	
	for(int i=5; i>0; i--){		
		printf("\n\nPlease enter your 4-digit PIN. You have %i tries left.\nPIN: ", i);
		scanf("%4s", input);
		
		for(int i=0; i<4; i++){
			if(PIN[i] != input[i]){
				isDifferent = false;
				break;
			}
		}
		if(isDifferent){
			printf("You have entered the right PIN and have gained access to the account. Welcome!");
		}else{
			printf("You have entered the wrong PIN. ");
		}
		
		
	}
}