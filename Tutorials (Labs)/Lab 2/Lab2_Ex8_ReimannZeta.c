#include <stdio.h> // UNFINISHED CODE
#include <math.h>
int main(){
	int S, iter;
	double ans;
	
	// input
	printf("\nEnter value for variable 'S': ");
	scanf("%i", &S);
	S = (double) S;
	printf("\nEnter number of iterations: ");
	scanf("%i", &iter);
	iter = (double) iter;
	
	// calculation
	for(double i=1; i<=iter; i++) ans += (1/(pow(i, S)));
	
	// output
	printf("The summation results to %.20lf", ans);
}