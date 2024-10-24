#include <stdio.h>
#include <stdbool.h>
int main(){
	
	double db = 47344.293822;
	float fl = 47344.293822;
	
	printf("%-10.5f\n", fl);
	printf("%-10.5g\n", db);
	
	printf("%-10.5f\n", fl);
	printf("%-10.5f\n", db);
	
	printf("%-10.5g\n", fl);
	printf("%-10.5g\n", db);
	
	bool yes = true;
	if(yes) printf("yep this works bro");
	
	if(yes) printf("y");
	else printf("n");
}