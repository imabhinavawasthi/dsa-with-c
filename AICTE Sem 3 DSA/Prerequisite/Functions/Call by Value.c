#include <stdio.h>

void change(int x) {
    x = 100;
}

int main() {
    int a = 10;
    change(a);
    printf("a = %d\n", a);  // remains 10
    return 0;
}


int fun(int a, int b) {
    // rocket science
    a = a + 10;
    b = b + 20;
    return a + b;
}