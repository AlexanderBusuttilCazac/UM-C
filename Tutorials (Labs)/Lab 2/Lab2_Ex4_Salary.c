#include <stdio.h> // UNFINISHED CODE
#include <stdbool.h>
#define INFINITE 1 // for infinite loop with break;
int main(){
	char firstName[10][20], lastName[10][20];
	int age[10];
	float FSalary[10], FTotalSalary; //		low accuracy
	double DSalary[10], DTotalSalary; //	high accuracy
	bool highAccuracy = true;
	
	// infinite loop with break case
	do{
		char tempAccuracy;
		printf("Would you like high accuracy for calculations? Enter 'Y' for yes or 'N' for no: ");
		scanf("%c", &tempAccuracy);
		
		if(tempAccuracy == 'Y' || tempAccuracy == 'y'){
			printf("You have chosen high accuracy.\n"); break;
		}else if(tempAccuracy == 'N' || tempAccuracy == 'n'){
			printf("You have chosen low accuracy.\n"); 
			highAccuracy = false; break;
		}
		
		printf("\nPlease enter either 'Y' or 'N'.\n");
	}while(INFINITE);
	
	
	// data entry
	for(int i=0; i<=9; i++){
		printf("\n\nPlease enter person %i's first name: ", (i+1));
		scanf("%10s", firstName[i]);
		
		printf("\nPlease enter person %i's last name: ", (i+1)); //? string continuing to next question
		scanf("%10s", lastName[i]);
		
		printf("\nPlease enter person %i's age: ", (i+1));
		scanf("%i", &age[i]);
		
		printf("\nPlease enter person %i's monthly pay-cheque salary: €", (i+1));
		if(highAccuracy){ //high accuracy
			scanf("%9.2lf", &DSalary[i]); // NOT SCANNING
			DTotalSalary += DSalary[i];
			printf("%9.2f", DSalary[i]);
		}else{ // low accuracy
			scanf("%9.2f", &FSalary[i]);
			FTotalSalary += FSalary[i];
			printf("%9.2f", FSalary[i]);
		}
	}
	
	// average salary calculation
	if(highAccuracy) DTotalSalary /= 10;
	else FTotalSalary /= 10;
	
	// table output
	printf("\t\t--TABLE OF EMPLOYEES--\n[Num.][First Name][Last Name ][Age][Mo. Salary][Ye. Salary]\n");
	if(highAccuracy){ // high-accuracy
		for(int i=0; i<=9; i++) printf("[ %-2i ][%-10s][%-10s][%-3i][€%9.2f][€%9.2f]\n", i+1, firstName[i], lastName[i], age[i], FSalary[i], 13*FSalary[i]);
		printf("Average Monthly Salary: €%.2f", FTotalSalary);
		printf("Average Yearly Salary: €%.2f", 13*FTotalSalary);
	}else{ // low-accuracy
		for(int i=0; i<=9; i++) printf("[ %-2i ][%-10s][%-10s][%-3i][€%9.2f][€%9.2f]\n", i+1, firstName[i], lastName[i], age[i], DSalary[i], 13*DSalary[i]);
		printf("Average Monthly Salary: €%.2f\n", DTotalSalary);
		printf("Average Yearly Salary: €%.2f\n", 13*DTotalSalary);
	}
}