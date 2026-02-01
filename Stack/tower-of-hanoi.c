#include <stdio.h>

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    hanoi(n - 1, A, C, B);
    printf("Move disk %d from %c to %c\n", n, A, B);
    hanoi(n - 1, C, B, A);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
