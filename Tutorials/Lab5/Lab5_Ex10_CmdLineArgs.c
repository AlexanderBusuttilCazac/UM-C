#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char* endptr;
    
    if(argc == 1){
        printf("USAGE: %s <num1> <num2>", argv[0]);
        return 0;
    }
    
    if (argc != 3){
        printf("You did not enter two numerical arguments to %s.", argv[0]);
        return 1;
    }
    
    int num1 = strtol(argv[1], &endptr, 10);
    if(*endptr != '\0'){
        printf("You did not enter two numerical arguments to %s.", argv[0]);
        return 1;
    }
    
    int num2 = strtol(argv[2], &endptr, 10);
    if(*endptr != '\0'){
        printf("You did not enter two numerical arguments to %s.", argv[0]);
        return 1;
    }
    
    printf("%i + %i = %i", num1, num2, num1 + num2);
    
    return 0;
}