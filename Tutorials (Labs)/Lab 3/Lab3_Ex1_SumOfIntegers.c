#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L; /* initialize sum to zero */
    int status;    
    
    printf("Please enter the two integers, separated by a space: ");
    status = scanf("%ld %ld", &sum, &num);
	sum += num;
		
    printf("Those integers sum to %ld.\n", sum);
	
    return 0;
}
