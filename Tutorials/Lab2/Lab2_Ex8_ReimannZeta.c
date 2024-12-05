#include <stdio.h>
#include <math.h>
double reimann(double S, int n);

int main(){
	double S;
	int iter;
	
	
	// input
	printf("\nEnter value for variable 'S': ");
	scanf("%lf", &S);
	printf("\nEnter number of iterations: ");
	scanf("%i", &iter);
	
	// calculation and output
	printf("The summation results to %.20lf", reimann(S, iter));
}
double reimann(double S, int n){
	double ans = 0;
	for(double i=1; i<=n; i++) ans += (1/(pow(n, S)));
	return ans;
}