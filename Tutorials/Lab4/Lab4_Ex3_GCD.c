#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Fibonacci(int n);
int iFibonacci(int n);
int rFibonacci(int n);
int GCD(int num1, int num2);
int rGCD(int num1, int num2);
int iGCD(int num1, int num2);

int Fibonacci(int n){
	if(iFibonacci(n) == rFibonacci(n)) return rFibonacci(n);
	else return -1;
}
int GCD(int num1, int num2){
	if(rGCD(num1, num2) == iGCD(num1, num2)) return rGCD(num1, num2);
	else return -1;
}

int iFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	bool flag = 1;
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