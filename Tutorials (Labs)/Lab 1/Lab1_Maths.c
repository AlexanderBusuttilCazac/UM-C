#include <stdio.h>
float add(float num1, float num2);
float sub(float num1, float num2);
float mul(float num1, float num2);
float div(float num1, float num2);

int main (){//eee
	float num1, num2;
	
	printf("Please enter number 1\nNumber 1:  ");
	scanf("%f", &num1);
	printf("Please enter number 2\nNumber 2: ");
	scanf("%f", &num2);
	
	printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
	printf("%.2f - %.2f = %.2f\n", num1, num2, sub(num1, num2));
	printf("%.2f x %.2f = %.2f\n", num1, num2, mul(num1, num2));
	printf("%.2f / %.2f = %.2f\n", num1, num2, div(num1, num2));
	
	return 0;
}
float add(float num1, float num2){
	return (num1+num2);
}
float sub(float num1, float num2){
	return (num1-num2);
}
float mul(float num1, float num2){
	return (num1*num2);
}
float div(float num1, float num2){
	return (num1/num2);
}