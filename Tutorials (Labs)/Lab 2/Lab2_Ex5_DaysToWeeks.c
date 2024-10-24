#include <stdio.h>
int main(){
	int inDays, outDays, outWeeks;
	
	for(int i=0; i<=9; i++){
		printf("\n%i)\tPlease enter the number of days: ", i+1);
		scanf("%i", &inDays);
		
		outWeeks = inDays / 7;
		outDays = inDays % 7;
		printf("\t%i days are equivalent to %i weeks and %i days. \n", inDays, outWeeks, outDays);
	}
}