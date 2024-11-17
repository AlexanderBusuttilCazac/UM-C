#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int iFibonacci(int n);
int rFibonacci(int n);
int rGCD(int num1, int num2);
int iGCD(int num1, int num2);

int main(){
	int in1, in2;
	
	printf("Enter number for fibonacci sequence: ");
	scanf("%i", &in1);
	printf("\nFibonacci iterative ans = %i", iFibonacci(in1));
	printf("\nFibonacci recursive ans = %i", rFibonacci(in1));
	
	printf("\n\nEnter number 1 for greatest common divisor: ");
	scanf("%i", &in1);
	printf("\nEnter number 2 for greatest common divisor: ");
	scanf("%i", &in2);
	printf("\nGCD iterative ans = %i", iGCD(in1, in2));
	printf("\nGCD recursive ans = %i\n\n", rGCD(in1, in2));
}

int iFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	bool flag = true;
	int num1 = 0, num2 = 1;
	
	for(int i=0; i<(n-1); i++){
		if(flag) num1 += num2;
		else num2 += num1;
		flag = !flag;
	}
	if(flag) return num2;
	else return num1;
}
int rFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (rFibonacci(n-1) + rFibonacci(n-2)); 
}

int rGCD(int num1, int num2){
	if(num1 == 0 && num2 == 0) return 0;
	if(num1 == 0){
		if(num2 < 0) return num2*-1;
		else return num2;
	}
	if(num2 == 0){
		if(num1 < 0) return num1*-1;
		else return num1;
	}
	return rGCD(num2, num1 % num2);
}
int iGCD(int num1, int num2){
	if(num1 == 0 && num2 == 0) return 0;
	if(num1 == 0){
		if(num2 < 0) return num2*-1;
		else return num2;
	}
	if(num2 == 0){
		if(num1 < 0) return num1*-1;
		else return num1;
	}
	
	int i;
	if(num1 == num2) i = num1;
	else if(num1 < num2) i = num1;
	else if(num1 > num2) i = num2;
	
	for(i; i>0; i--){
		if(num1 % i == 0 && num2 % i == 0) return i;
	}
}