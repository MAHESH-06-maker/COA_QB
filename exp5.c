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

// A = A - M
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

// A = A + M
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
    int A[4] = {0, 0, 0, 0};  // Accumulator (remainder)
    int Q[4];                 // Quotient
    int M[4];                 // Divisor
    int tempA[4];

    printf("Enter dividend (0–15): ");
    scanf("%d", &dividend);
    printf("Enter divisor (1–15): ");
    scanf("%d", &divisor);

    decimalToBinary(dividend, Q);
    decimalToBinary(divisor, M);

    // --- 4 iterations (4-bit division) ---
    for (int step = 0; step < 4; step++) {

        // Left shift (A, Q)
        A[0] = A[1];
        A[1] = A[2];
        A[2] = A[3];
        A[3] = Q[0];
        Q[0] = Q[1];
        Q[1] = Q[2];
        Q[2] = Q[3];
        Q[3] = 0;

        // Subtract M → A = A - M
        subtract(A, M);

        // If A is negative (A[0] == 1), restore → A = A + M, Q[3] = 0
        // Else, keep A, and set Q[3] = 1
        if (A[0] == 1) {
            add(A, M);   // restore
            Q[3] = 0;
        } else {
            Q[3] = 1;
        }
    }

    printf("\nFinal Quotient (binary): ");
    printBinary(Q);
    printf("\nFinal Remainder (binary): ");
    printBinary(A);
    printf("\n");

    return 0;
}
