#include <stdio.h>
int main(){
	char word1[15], word2[15], word3[15];
	
	printf("Please enter three words: "); // input
	scanf("%s%s%s", word1, word2, word3);
	printf("Your three words in reverse order are: %s %s %s", word3, word2, word1); // output
}