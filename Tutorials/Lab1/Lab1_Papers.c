#include <stdio.h>
#include <string.h>

int main(void){
	
	int A3 = 1000;
	int A4 = 1000;
	int A5 = 1000;
	int A3Subtract, A4Subtract, A5Subtract;
	int conditionMet = 0;
	
	do{
		printf("Please input the amount of A3 papers you would like to order:\n");
		scanf("%i", &A3Subtract);
		if (A3Subtract <= 1000) conditionMet = 1;
	}while (conditionMet == 0);
	
	conditionMet = 0;
	do{
		printf("Please input the amount of A4 papers you would like to order:\n");
		scanf("%i", &A4Subtract);
		if (A4Subtract <= 1000) conditionMet = 1;
	}while (conditionMet == 0);
	
	conditionMet = 0;
	do{
		printf("Please input the amount of A5 papers you would like to order:\n");
		scanf("%i", &A5Subtract);
		if (A5Subtract <= 1000) conditionMet = 1;
	}while (conditionMet == 0);
	
	A3 = A3 - A3Subtract;
	A4 = A4 - A4Subtract;
	A5 = A5 - A5Subtract;
	
	printf("[A3]\nOrder Amount: %i \nUpdated Stock: %i\n\n", A3Subtract, A3);
	printf("[A4]\nOrder Amount: %.3i \nUpdated Stock: %.3i\n\n", A4Subtract, A4);
	printf("[A5]\nOrder Amount: %-6i \nUpdated Stock: %+6i", A5Subtract, A5);
	
	return 0;
}