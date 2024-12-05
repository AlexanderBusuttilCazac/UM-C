#include <stdio.h>
int main(){
	double dollars, euros;
	
	for(int i=0; i<=9; i++){ // input
		printf("\n%i)\tPlease enter the amount in dollars: $", i+1);
		scanf("%lf", &dollars);
		
		euros = dollars * 0.93; // calculation
		
		printf("\t$%.2f USD are equivalent to €%.2f EUR.\n", dollars, euros); // output
	}
}