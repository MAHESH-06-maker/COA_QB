// #include <stdio.h>

// int main() {
//     int num1, num2;
//     int arr1[8] = {0};
//     int arr2[8] = {0};
//     int add[8] = {0};
//     int sub[8] = {0};
//     int carry = 0;
//     int borrow = 0;
//     printf("Enter number1 : ");
//     scanf("%d", &num1);
//     printf("Enter number2 : ");
//     scanf("%d", &num2);

//     // Convert to binary (8-bit)
//     for (int i = 7; i >= 0; i--) {
//         arr1[i] = num1 % 2;
//         num1 /= 2;
//     }
//     for (int i = 7; i >= 0; i--) {
//         arr2[i] = num2 % 2;
//         num2 /= 2;
//     }
//     for(int i = 7; i>=0 ;i--){
//         int sum = arr1[i]+arr2[i]+carry;
//         add[i]= sum%2;
//         carry = sum/2;
//     }
//     printf("\nBinary 8-bit addition result: ");
//     if (carry)
//         printf("1");
//     for (int i = 0; i < 8; i++)
//         printf("%d", add[i]);
//     printf("\n");



//     for (int i= 7 ;i >=0; i--){
//         int diff = arr1[i]-arr2[i] -borrow;
//         if(diff>=0){
//             sub[i]=diff;
//             borrow= 0;
//         }
//         else{
//             sub[i]= diff + 2;
//             borrow= 1;
//         }
//     }
//     printf("Binary 8-bit subtraction result: ");
//     for(int i = 0; i < 8; i++)
//         printf("%d", sub[i]);

//     if (borrow)
//         printf("  (Result is negative in 2's complement form)");

//     printf("\n");
// }

#include <stdio.h>

// Function to print binary of a number
void printBinary(int num) {
    for (int i = 15; i >= 0; i--) {   // 16-bit representation
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int num1, num2;
    int sum, diff;

    printf("Enter first decimal number: ");
    scanf("%d", &num1);
    printf("Enter second decimal number: ");
    scanf("%d", &num2);

    // Convert to hexadecimal using %X
    printf("\n--- Conversion ---\n");
    printf("Number 1 in Hexadecimal: %X\n", num1);
    printf("Number 2 in Hexadecimal: %X\n", num2);

    // Perform addition and subtraction
    sum = num1 + num2;
    diff = num1 - num2;

    printf("\n--- Results ---\n");

    // Addition
    printf("Addition (Hex): %X\n", sum);
    printf("Addition (Binary): ");
    printBinary(sum);
    printf("\n");

    // Subtraction
    printf("Subtraction (Hex): %X\n", diff);
    printf("Subtraction (Binary): ");
    printBinary(diff);
    printf("\n");

    return 0;
}




