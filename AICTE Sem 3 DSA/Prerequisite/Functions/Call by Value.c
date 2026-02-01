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
