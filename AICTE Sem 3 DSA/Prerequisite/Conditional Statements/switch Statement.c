#include <stdio.h>

int main() {
    int choice;

    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("One\n"); break;
        case 2: printf("Two\n"); break;
        case 3: printf("Three\n"); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
