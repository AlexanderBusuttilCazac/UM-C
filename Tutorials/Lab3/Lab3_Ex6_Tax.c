#include <stdio.h>
#include <stdbool.h>
int main(){
	double input, output, firstBracket = 10000, secondBracket = 18000;
	char boolInput;
	
	printf("\nPlease input the initial, untaxed amount: €");
	scanf("%lf", &input);
	
	do{
		printf("\nDo you collect old electronic equipment for green disposal? Please enter 'Y' or 'N': ");
		scanf("%c", &boolInput);
		scanf("%c", &boolInput);
		
		if(boolInput == 'N' || boolInput == 'n') break;
		if(boolInput == 'Y' || boolInput == 'y'){
			firstBracket = 15000;
			secondBracket = 23000;
			break;
		}
		printf("\nPlease enter either 'Y' or 'N'.\n");
	}while(1);
	
	if(input <= firstBracket){
		output = input * 1.18;
	}else if(input <= secondBracket){
		output = (firstBracket * 1.18) + ((input - firstBracket) * 1.20);
	}else if(input > secondBracket){
		output = (firstBracket * 1.18) + ((secondBracket - firstBracket) * 1.20) + ((input - secondBracket) * 1.25);
	}
	
	do{
		printf("\nDo you work in the ICT industry? Please enter 'Y' or 'N': ");
		scanf("%c", &boolInput);
		
		if(boolInput == 'N' || boolInput == 'n') break;
		if(boolInput == 'Y' || boolInput == 'y'){
			output *= 0.95;
			break;
		}
		printf("\nPlease enter either 'Y' or 'N'.\n");
	}while(1);
	
	printf("\nThe final, taxed sum of money amounts to €%.2lf", output);
}