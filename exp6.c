#include <stdio.h>

void decimalToBinary(int num, int bin[4]) {
    for (int i = 3; i >= 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
}

void printBinary(int bin[4]) {
    for (int i = 0; i < 4; i++) printf("%d", bin[i]);
}

// Subtraction: A = A - M
void subtract(int A[4], int M[4]) {
    int borrow = 0;
    for (int i = 3; i >= 0; i--) {
        int diff = A[i] - M[i] - borrow;
        if (diff >= 0) {
            A[i] = diff;
            borrow = 0;
        } else {
            A[i] = diff + 2;
            borrow = 1;
        }
    }
}

// Addition: A = A + M
void add(int A[4], int M[4]) {
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = A[i] + M[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

int main() {
    int dividend, divisor;
    int A[4] = {0, 0, 0, 0};
    int Q[4], M[4];

    printf("Enter dividend (0-15): ");
    scanf("%d", &dividend);
    printf("Enter divisor (1-15): ");
    scanf("%d", &divisor);

    decimalToBinary(dividend, Q);
    decimalToBinary(divisor, M);

    // --- 4 iterations ---
    for (int step = 0; step < 4; step++) {

        // Left shift (A,Q)
        A[0] = A[1];
        A[1] = A[2];
        A[2] = A[3];
        A[3] = Q[0];
        Q[0] = Q[1];
        Q[1] = Q[2];
        Q[2] = Q[3];
        Q[3] = 0;

        // If A[0]==0 (A positive) → A = A - M
        // If A[0]==1 (A negative) → A = A + M
        if (A[0] == 0)
            subtract(A, M);
        else
            add(A, M);

        // Set Q[3] based on sign of A
        if (A[0] == 0)
            Q[3] = 1;
        else
            Q[3] = 0;
    }

    // Final correction: if A negative → A = A + M
    if (A[0] == 1)
        add(A, M);

    printf("\nFinal Quotient (binary): ");
    printBinary(Q);
    printf("\nFinal Remainder (binary): ");
    printBinary(A);
    printf("\n");

    return 0;
}
