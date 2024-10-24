#include <stdio.h>
int main(){
	int num, ans = 1;
	
	// input
	printf("\nPlease enter the number you would like to compute factorial with: ");
	scanf("%i", &num);
	
	while(num > 1){ // loop to calculate
		printf("%i x ", num);
		ans *= num;
		num--;
	}
	printf("1 = %i", ans); // output
}