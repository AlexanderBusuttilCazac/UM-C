#include <stdio.h>
int sortArray(float array[]);

int main(){
	int size;
	float total;
	float modeCalc[10][2];
	
	do{
		printf("Enter the amount of numbers would you like to enter: ");
		scanf("%i", &size);
		
		if(size<5 || size>20) printf("Please enter a number between 5 and 20.");
		else break;
	}while(1);
	float inputs[size];
	
	for(int i=0; i<size; i++){
		do{
			printf("\nPlease enter number %i of %i: ", i+1, size);
			scanf("%f", inputs[i]);
			if(inputs[i]<1 || inputs[i]>100) printf("\nPlease enter a number between 1 and 100");
			else{
				total += inputs[i];
				break;
			}
		}while(1);
	}
	
	printf("\nMean: %f", total/size);
	printf("\nMedian: %f");
	printf("\nMode: %f");
}
int sortArray(float array[]){
	for(int i=0; i<(array.size()-1), i++)
	return array[];
}
