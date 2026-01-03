#include <stdio.h>

void hanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    hanoi(n - 1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    hanoi(n - 1, aux, source, dest);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
