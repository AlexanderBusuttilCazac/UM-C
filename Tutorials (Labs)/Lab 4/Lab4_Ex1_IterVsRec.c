#include <stdio.h>

long fact(int n);
long rfact(int n);
int main(){
	
	// In the iterative function, A new stack is induced after every iteration.
	printf("\nITERATIVE ANS: %d",  fact(5));
	
	// In the iterative function, the same stack grows bigger and deeper for every recursion.
	printf("\nITERATIVE ANS: %d", rfact(5));
}

// Iterative function
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}

// Recursive function
long rfact(int n) {
    long ans;
    if (n > 0)
        ans = n * rfact(n - 1);
    else
        ans = 1;
    return ans;
}
