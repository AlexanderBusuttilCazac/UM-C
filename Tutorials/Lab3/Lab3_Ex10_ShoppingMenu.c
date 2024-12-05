#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define EUR '€'

int addItem();
void checkout(int* items, int itemsSize, double total);
int main(){
	int input, items[10], itemsSize = 0;
	double total = 0.0;
	
	while(1){
		while(1){
			if(itemsSize > 9){
				checkout(items, itemsSize, total);
				return 1;
			}
			
			printf("\n\n-------- MENU --------\n1. Add items to shopping cart\n2. Show current total\n3. Checkout\n4. Cancel session\n5. Quit\n\nPlease select by entering an integer between 1 and 5: ");
			scanf("%i", &input);
			
			if(input < 1 || input > 5) printf("Please enter an integer between 1 and 5.\n\n");
			else break;
		}
		switch(input){
			case 1: 
				items[itemsSize] = addItem();
				switch(items[itemsSize]){
					case 1: total += 2.99; break;
					case 2: total += 3.99; break;
					case 3: total += 4.99; break;
					case 4: total += 5.99; break;
					case 5: total += 6.99; break;
					case 6: total += 7.99; break;
					default:
						fprintf(stderr, "\nFATAL ERROR - Exiting program - CODE 1");
						exit(1);
				}
				itemsSize++;
				break;
			case 2: printf("Current total: €%.2lf", total); break;
			case 3: 
				checkout(items, itemsSize, total); 
				itemsSize = 0;
				total = 0.0;
				printf("\nStarting new session:");
				main();
				break;
			case 4: 
				itemsSize = 0;
				total = 0.0;
				printf("\nStarting new session:");
				break;
			case 5: 
				printf("Exiting program: CODE 0");
				exit(0);
			default:
				fprintf(stderr, "\nFATAL ERROR - Exiting program - CODE 2");
				exit(1);
		}
	}
}

int addItem(){
	int localInput;
	do{
		printf("\n\n-------- ITEMS --------\n1. Apple\n2. Banana\n3. Orange\n4. Pear\n5. Grapes\n6. Watermelon\n\nPlease select by entering an integer between 1 and 6: ");
		scanf("%i", &localInput);
		
		if(localInput < 1 || localInput > 6) printf("\nPlease enter an integer between 1 and 6.\n\n");
		else break;
	}while(1);
	
	switch(localInput){
		case 1:
			printf("You have added an apple to your cart.");
			return 1;
		case 2:
			printf("You have added a banana to your cart.");
			return 2;
		case 3:
			printf("You have added an orange to your cart.");
			return 3;
		case 4:
			printf("You have added a pear to your cart.");
			return 4;
		case 5:
			printf("You have added grapes to your cart.");
			return 5;
		case 6:
			printf("You have added a watermelon to your cart.");
			return 6;
		default: printf("\nPlease choose an option between 1 and 6.\n");
	}
}

void checkout(int *items, int itemsSize, double total){
	printf("\n-------- BILL --------\n[No][   Item   ][Price]");
	for(int i=0; i<itemsSize; i++){
		char itemName[11];
		double itemPrice;
		
		switch(items[i]){
			case 1: 
				strcpy(itemName, "Apple");
				itemPrice = 2.99;
				break;
			case 2: 
				strcpy(itemName, "Banana");
				itemPrice = 3.99;
				break;
			case 3: 
				strcpy(itemName, "Orange");
				itemPrice = 4.99;
				break;
			case 4: 
				strcpy(itemName, "Pear");
				itemPrice = 5.99;
				break;
			case 5: 
				strcpy(itemName, "Grapes");
				itemPrice = 6.99;
				break;
			case 6: 
				strcpy(itemName, "Watermelon");
				itemPrice = 7.99;
				break;
			default:
				fprintf(stderr, "\nFATAL ERROR - Exiting program - CODE 3");
				exit(1);
		}
		printf("\n[%2i][%10s][€%4.2lf]", i, itemName, itemPrice);
	}
	printf("\n[TOTAL: %-14.2lf]", total);
}