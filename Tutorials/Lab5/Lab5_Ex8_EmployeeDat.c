#include <stdio.h> // UNFINISHED CODE
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define clearBuffer() {while((getchar()) != '\n');}

struct Employee{
	char ID[8];
	char name[15];
	char surname[30];
	double salary;
};

void AddEmployee(struct Employee *employees, int nextEmp);
void editEmployee(struct Employee *employees, int index);
bool printEmployees(struct Employee *employees, int nextEmp, bool isSorted, bool sortedByID);

int main(){
	struct Employee employees[10];
	int nextEmp = 0;
	bool firstTime = 1, isSorted = 0, sortedByID = 1;
	
	while(1){
		if(!firstTime) clearBuffer();
		firstTime = 0;
		fputs("\n\n\n---MENU---\n1. Add Employee\n2. Edit Employee\n3. Remove Employee\n4. Print Employees\n5. Quit Program\n\nSelection: ", stdout);
		char input = fgetc(stdin);
		clearBuffer();
		
		switch(input){
			case '1':
				AddEmployee(employees, nextEmp);
				isSorted = 0;
				nextEmp++;
				break;
			case '2':
				AddEmployee(employees, nextEmp);
				isSorted = 0;
				break;
			case '3':
				AddEmployee(employees, nextEmp);
				break;
				nextEmp--;
			case '4':
				sortedByID = printEmployees(employees, nextEmp, isSorted, sortedByID);
				isSorted = 1;
				break;
			case '5':
				exit(0);
				break;
			default: 
				fputs("\nPlease enter a number between 1 and 5.\n", stdout);
				break;
		}
	}
}

void AddEmployee(struct Employee *employees, int nextEmp){
	struct Employee emp;
	
	printf("Please enter ID for employee %i: ", nextEmp + 1);
	fgets(emp.ID, 8, stdin);
	emp.ID[strcspn(emp.ID, "\n")] = '\0';
	
	printf("Please enter name for employee %i: ", nextEmp + 1);
	fgets(emp.name, 15, stdin);
	emp.name[strcspn(emp.name, "\n")] = '\0';
	
	printf("Please enter surname for employee %i: ", nextEmp + 1);
	fgets(emp.surname, 30, stdin);
	emp.surname[strcspn(emp.surname, "\n")] = '\0';
	
	printf("Please enter monthly salary for employee %i: ", nextEmp + 1);
	scanf("%lf", &emp.salary);
	
	employees[nextEmp] = emp;
}

void editEmployee(struct Employee *employees, int index){
	printf("\n\n                 --------- EMPLOYEES ---------"                            );
	printf( "\n    [   ID   ][      NAME     ][            SURNAME           ][Mon.Salary]");
	for(int i=0; i<index; i++) printf("\n%2i. [%-8s][%-15s][%-30s][€%-9.2f]", i+1, employees[i].ID, employees[i].name, employees[i].surname, employees[i].salary);
	
	while(1){
		fputs("\nPlease choose an ID to edit: ", stdout);
		char input[8];
		fgets(input, 8, stdin);
		clearBuffer();
	}
}

bool printEmployees(struct Employee *employees, int lastEmp, bool isSorted, bool sortedByID){
	if (lastEmp == 0) {
        printf("\nNo employees to display.\n");
        return sortedByID;
    }
	lastEmp--;
	
	while(1){
		fputs("\nWould you like to sort by surname or ID?\nEnter '1' to sort by ID or '2' to sort by surname.\nSelection: ", stdout);
		char input = fgetc(stdin);
		
		switch(input){
			case '1':
				if(isSorted == 0 || sortedByID == 0){
					struct Employee temp;
					for(int i=0; i<lastEmp-1; i++){
						for(int j=0; j<lastEmp-1; j++){
							if(strcmp(employees[j+1].ID, employees[j].ID) < 0){
								temp = employees[j];
								employees[j] = employees[j+1];
								employees[j+1] = temp;
							}
						}
					}
				}
				
				printf("\n\n--- EMPLOYEES ---");
				printf( "\n    [   ID   ][      NAME     ][            SURNAME           ][Mon.Salary]");
				for(int i=0; i<=lastEmp; i++) printf("\n%2i. [%-8s][%-15s][%-30s][€%-9.2f]", i+1, employees[i].ID, employees[i].name, employees[i].surname, employees[i].salary);
				
				return 1;
			case '2':
				if(isSorted == 0 || sortedByID == 1){
					struct Employee temp;
					for(int i=0; i<lastEmp-1; i++){
						for(int j=0; j<lastEmp; j++){
							if(strcmp(employees[j+1].surname, employees[j].surname) < 0){
								temp = employees[j];
								employees[j] = employees[j+1];
								employees[j+1] = temp;
							}
						}
					}
				}
				
				printf("\n\n--- EMPLOYEES ---");
				printf( "\n    [   ID   ][      NAME     ][            SURNAME           ][Mon.Salary]");
				for(int i=0; i<=lastEmp; i++) printf("\n%2i. [%-8s][%-15s][%-30s][€%-9.2f]", i+1, employees[i].ID, employees[i].name, employees[i].surname, employees[i].salary);
				
				return 0;
			default: 
				fputs("\nPlease enter a number between 1 and 5.\n", stdout);
				break;
		}
	}
	perror("ERROR");
	return sortedByID;
}

