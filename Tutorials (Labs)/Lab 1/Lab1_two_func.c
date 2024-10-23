#include <stdio.h>
#include <string.h>
// a program using two functions in one file
void butler(char *str);      	/* ISO/ANSI C function prototyping */

int main(void){
	
	char myString[30];
    printf("Please enter your name:\n");
    scanf("%s", myString);
    printf("I will summon the butler function.\n");
    butler(myString);
    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");
	
    return 0;
}

void butler(char *str){
    printf("You rang, %s?\n", str);
}