#include <stdio.h>
int main(void){
    int dogs, cats, total;
	
    printf("How many dogs do you have?\n");
    scanf("%i", &dogs);
    printf("So you have %i dog(s)!\n", dogs);
	
	printf("How many cats do you have?\n");
    scanf("%i", &cats);
    printf("So you have %i cats(s)!\n", cats);
    
    total = dogs + cats;
    
    printf("Therefore, you have %i pets(s)!\n", total);
	
    return 0;
}