#include <stdio.h>
#include <stdlib.h>
#include "Lab4_Ex1_IterVsRec.c"
#include "Lab4_Ex3_GCD.c"
#include "Lab4_Ex4_ConvAndReverse.c"
#include "Lab4_Ex5_PassStrByRef.c"
#include "Lab4_Ex6_UsingMath.c"

int main(){
	int input, num;
	
	while(1){
		while(1){
			printf("\n\n-------- MENU --------\n1. Factorial Computation\n3. Fibonacci Computation\n3. GCD Computation\n4. Decimal Rounding\n5. Decimal to HEX\n6. String Reversal\n7. String Analysis and Manipulation\n8. QUIT\n\nPlease select by entering an integer between 1 and 8: ");
			scanf("%i", &input);
			
			if(input < 1 || input > 8) printf("Please enter an integer between 1 and 8.\n\n");
			else break;
		}
		switch(input){
			case 1:
				printf("Please enter value to compute factorial with: ");
				scanf("%i", &num);
				printf("Answer = %i", factorial(num));
				break;
			case 2:
				printf("Please enter value to compute Fibonacci with: ");
				scanf("%i", &num);
				printf("Answer = %i", Fibonacci(num));
				break;
			case 3:
				int num1, num2;
				printf("Please enter value 1 to compute GCD with: ");
				scanf("%i", &num1);
				printf("Please enter value 2 to compute GCD with: ");
				scanf("%i", &num2);
				printf("Answer = %i", GCD(num1, num2));
				break;
			case 4:
				Rounding();
				break;
			case 5:
				hex();
				break;
			case 6:
				reverseString();
				break;
			case 7:
				char buffer[32];
				getchar();
				printf("Please enter string to analyse (Maximum 32 characters): ");
				fgets(buffer, 32, stdin);
				while ((getchar()) != '\n');
				ManipulateString(buffer);
				break;
			case 8:
				exit(0);
			default:
				fprintf(stderr, "\nFATAL ERROR - Exiting program - CODE 1");
				exit(1);
		}
	}
}