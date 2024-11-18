#include <stdio.h>
#include <math.h>

void Rounding();

void Rounding(){
	double num;
	printf("enter decimal value: ");
	scanf("%lf", &num);
	
	printf("\nusing math.h:\nceil() returns %i\nfloor() returns %i", (int)ceil(num), (int)floor(num));
	
	int top, bottom;
	if(fmod(num, 1) == 0){
		top = num;
		bottom = num;
	}else{
		bottom = (int)num;
		top = (int)num + 1;
	}
	
	printf("\n\nwithout math.h:\ntop = %i\nbottom = %i", top, bottom);
}