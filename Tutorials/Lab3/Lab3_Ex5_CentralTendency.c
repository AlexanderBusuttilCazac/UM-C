#include <stdio.h>
int main(){
	int size;
	float total;
	
	do{
		printf("\nEnter the amount of numbers would you like to enter: ");
		scanf("%i", &size);
		
		if(size < 5 || size > 20) printf("Please enter a number between 5 and 20.\n");
		else break;
	}while(1);
	float inputs[size];
	
	for(int i = 0; i < size; i++){
		do{
			printf("\nPlease enter number %i of %i: ", i+1, size);
			scanf("%f", &inputs[i]);
			if(inputs[i] < 1 || inputs[i] > 100) printf("\nPlease enter a number between 1 and 100");
			else{
				total += inputs[i];
				break;
			}
		}while(1);
	}
	
	for(int i = 0; i < (size); i++){
		for(int j = 0; j < (size-1); j++)
		{
			if(inputs[j] > inputs[j+1]){
				int temp = inputs[j+1];
				inputs[j+1] = inputs[j];
				inputs[j] = temp;
			}
		}
	}
	
	printf("\nMean: %f", total/size);
	
	if(size % 2 != 0) printf("\nMedian: %f", inputs[(size-1) / 2]);
	else printf("\nMedian: %f", (inputs[(size/2) - 1] + inputs[size/2]) / 2);
	
	// MODE CALCULATION
	int count = 1, modeCount = 1, nextFreeIndex = 0;
	float modeArray[10];
	for(int i = 1; i < size; i++)
	{
		if (inputs[i-1] == inputs[i]){
			count++;
		}else{
			if(count > modeCount){
				modeArray[0] = inputs[i-1];
				modeCount = count;
				nextFreeIndex = 1;
				count = 1;
			}
			else if(count == modeCount && modeCount > 1){
				modeArray[nextFreeIndex] = inputs[i-1];
				nextFreeIndex++;
				count = 1;
			}
			else if(count < modeCount){
				count = 1;
			}
		}
	}
	if(modeCount == 1) printf("\nMode: NO MODE");
	else if(nextFreeIndex == 1){
		printf("\nMode: %f", modeArray[0]);
	}else{
		printf("\nModes: ");
		for(int i = 0; i < nextFreeIndex - 1; i++) printf("%f, ", modeArray[i]);
		printf("%f", modeArray[nextFreeIndex-1]);
	}
}