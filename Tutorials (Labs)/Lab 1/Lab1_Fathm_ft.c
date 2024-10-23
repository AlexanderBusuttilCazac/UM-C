#include <stdio.h>
int main(void){
	
    //symbolic identifiers: feet & fathoms
    int feet, fathoms; //declarations

    //lvalue        rvalue
    fathoms         = 2;
    //lvalue        rvalue
    feet            = 6 * fathoms;


    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);

    return 0;
}