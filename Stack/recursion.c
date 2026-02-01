#include <stdio.h>

void rec(int n) {
    // base case
    if(n==0) return;
    printf("%d ", n);
    // recursive case
    rec(n-1);
}

int main() {
    int n = 3;

    rec(n);
    return 0;
}
