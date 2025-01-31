#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int iterative(int n);
int recursive(int n);

int main(){
	int in;
	
	printf("Enter number for fibonacci sequence: ");
	scanf("%i", &in);
	printf("\n\nIterative ans = %i", iterative(in));
	printf("\nRecursive ans = %i", recursive(in));
}

int iterative(int n){
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

int recursive(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (recursive(n-1) + recursive(n-2)); 
}