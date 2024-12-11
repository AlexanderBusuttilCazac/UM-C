#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[40];
	char suf[8];
	
	fputs("\nPlease enter a string of text: ", stdout);
	fgets(str, 32, stdin);
	
	for(int i=0; i<=32; i++){
		if (str[i] == '\0') break;
		if (str[i] == '\n'){
			str[i] = '\0';
			break;
		}
	}
	
	fputs("\nPlease enter a suffix for your previously-entered string: ", stdout);
	fgets(suf, 8, stdin);
	
	strcat(str, suf);
	printf("The new string: %s", str);
}