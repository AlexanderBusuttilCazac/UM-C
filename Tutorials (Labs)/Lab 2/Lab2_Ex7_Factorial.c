#include <stdio.h>
int main(){
	int num, ans = 1;
	
	printf("\nPlease enter the number you would like to compute factorial with: ");
	scanf("%i", &num);
	
	while(num > 1){
		printf("%i x ", num);
		ans *= num;
		num--;
	}
	printf("1 = %i", ans);	
}