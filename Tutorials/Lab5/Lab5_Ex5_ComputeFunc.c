#include <stdio.h> // C
#include <stdlib.h>
#include <stdbool.h>

int main(){
	bool flag = 0;
	double arr[101];
	double *** threeDIM;
    // f(x, y, z) = x + 6y + 7.2z
	
	threeDIM = (double ***) malloc(101 * sizeof(double **));
	for(int x=0; x<101; x++){
		threeDIM[x] = (double **) malloc(101 * sizeof(double *));
		for(int y=0; y<101; y++){
			threeDIM[x][y] = arr;
		}
	}
	
	for(int x=0; x<101; x++){
		for(int y=0; y<101; y++){
			for(int z=0; z<101; z++){
				threeDIM[x][y][z] = (x + 6*y + 7.2*z);
			}
		}
	}
	
	while(1){
		flag = 0;
		int x, y, z;
		printf("\nPlease enter the x value, which must be between 0 and 100.\nX: ");
		scanf("%i", &x);
		printf("\nPlease enter the y value, which must be between 0 and 100.\nY: ");
		scanf("%i", &y);
		printf("\nPlease enter the z value, which must be between 0 and 100.\nZ: ");
		scanf("%i", &z);
		
		printf("\n\n%d + 6*%d + 7.2*%d = %lf", x, y, z, threeDIM[x][y][z] - 700);
		
		while(1){
			char input;
			printf("\n\nWould you like to calculate another answer? Enter 'Y' for yes or 'N' for no.");
			getchar();
			scanf("%c", &input);
			
			switch(input){
				case 'Y':
				case 'y':
					flag = 1;
					break;
				case 'N':
				case 'n':
					exit(1);
				default: printf("\nPlease enter 'Y' or 'N'");
			}
			if (flag == 1) break;
			else continue;
		}
	}
	
	// char ch = 'x';
	// for(int i=0; i<=2; i++){
	// 	printf("%c", ch);
	// 	ch++;
	// }
	
	for(int x=0; x<101; x++){
		free(threeDIM[x]);
	}
	free(threeDIM);
}