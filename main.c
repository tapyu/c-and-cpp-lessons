#include <stdio.h>

// Function to generate and print the Fibonacci sequence
void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first);
            continue;
        }
        if (i == 2) {
            printf("%d ", second);
            continue;
        }
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;

    // Prompt the user for input
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        generateFibonacci(terms);
    }

    return 0;
}