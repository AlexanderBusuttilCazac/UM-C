#include <stdio.h>
int main() {
	
	// case 1 using double
	float weight1;	// float output: $4234725.00
	double value1;	// double output: $1073741824
	printf("Enter your weight in pounds: \n");
	scanf("%d", &weight1);
  	// Platinum is $1770 / pound
  	// 14.5 troy ounces in 1 pound
  	value1 = 1770.0 * weight1 * 14.5;
	printf ("Your weight in platinum costs $%.4d. \n", value1);
	
	// case 2.1 using int - float
	float weight2;
	int value2;
	printf("Enter your weight in pounds: \n");
	scanf("%f", &weight2);
  	// Platinum is $1770 / pound
  	// 14.5 troy ounces in 1 pound
  	value2 = 1770.0 * weight2 * 14.5;
	printf ("Your weight in platinum costs $%f. \n", value2);
	
	// case 2.2 using int - double
	float weight3;
	int value3;
	printf("Enter your weight in pounds: \n");
	scanf("%f", &weight3);
  	// Platinum is $1770 / pound
  	// 14.5 troy ounces in 1 pound
  	value3 = 1770.0 * weight3 * 14.5;
	printf ("Your weight in platinum costs $%d. \n", value3);
	
	int value4;
	printf("Enter an integer: \n");
	scanf("%i", &value4);
	
	printf("Character: %c.\n", (char) value4);
	printf("Hexadecimal: %#o.\n", value4);
	printf("Octal Integer: %#x.\n", value4);
	
	// 4) The results are $0.0 because 'int' takes less width in bits/bytes than float and double, and therefore they overflow.
	// 5) A (?) placeholder symbol is printed.
}