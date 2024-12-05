#include <stdio.h>
int main(){
	int num, ans = 1;
	
	// input
	printf("\nPlease enter the number you would like to compute factorial on: ");
	scanf("%i", &num);
	
	for(int i=1; i<=num; i++) ans *= i;
	printf("ans = %i", ans); // output
}