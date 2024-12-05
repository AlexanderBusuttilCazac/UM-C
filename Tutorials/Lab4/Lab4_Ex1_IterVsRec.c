#include <stdio.h>

long factorial(int n);
long fact(int n);
long rfact(int n);

long factorial(int n){
    if(fact(n) == rfact(n)) return fact(n);
    else return -1;
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
