#include <stdio.h>
// Macro to swap values using a temporary variable
#define SWAP_MACRO(a, b, type) { \
    type temp = a; \
    a = b; \
    b = temp; \
}

/***************************************************
 * Function Name: swap_values
 * Description: Swaps two values without using pointers.
 * Parameters:
 *   - a: First value to be swapped
 *   - b: Second value to be swapped
 ****************************************************/
void swap_values(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("\nAfter swapping without using pointers:\n");
    printf("\ta = %d\n", a);
    printf("\tb = %d\n", b);
}

/***************************************************
 * Function Name: swap_temp
 * Description: Swaps two values using a temporary variable and pointers.
 * Parameters:
 *   - a: Pointer to the first value to be swapped
 *   - b: Pointer to the second value to be swapped
 ****************************************************/
void swap_temp(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/***************************************************
 * Function Name: swap_xor
 * Description: Swaps two values using XOR bitwise operation and pointers.
 * Parameters:
 *   - a: Pointer to the first value to be swapped
 *   - b: Pointer to the second value to be swapped
 ****************************************************/
void swap_xor(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/***************************************************
 * Function Name: swap_arithmetic
 * Description: Swaps two values using arithmetic operations and pointers.
 * Parameters:
 *   - a: Pointer to the first value to be swapped
 *   - b: Pointer to the second value to be swapped
 ****************************************************/
void swap_arithmetic(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    // Variable declaration and initialization
    char char1 = 'A';
    char char2 = 'B';

    printf("Before swapping using Macro Define Method:\n");
    printf("\tchar1 = %c\n", char1);
    printf("\tchar2 = %c\n", char2);

    // Swapping values using SWAP_MACRO
    SWAP_MACRO(char1, char2, char);

    printf("\nAfter swapping using Macro Define Method:\n");
    printf("\tchar1 = %c\n", char1);
    printf("\tchar2 = %c\n", char2);

    // Variable declaration and initialization
    int num1 = 10;
    int num2 = 20;

    printf("\nBefore swapping using temporary variable and pointers:\n");
    printf("\tnum1 = %d\n", num1);
    printf("\tnum2 = %d\n", num2);

    // Swapping values using swap_temp function
    swap_temp(&num1, &num2);

    printf("\nAfter swapping using temporary variable and pointers:\n");
    printf("\tnum1 = %d\n", num1);
    printf("\tnum2 = %d\n", num2);

    // Variable declaration and initialization
    int a = 5;
    int b = 8;

    printf("\nBefore swapping using XOR bitwise operation and pointers:\n");
    printf("\ta = %d\n", a);
    printf("\tb = %d\n", b);

    // Swapping values using swap_xor function
    swap_xor(&a, &b);

    printf("\nAfter swapping using XOR bitwise operation and pointers:\n");
    printf("\ta = %d\n", a);
    printf("\tb = %d\n", b);

    // Variable declaration and initialization
    int x = -15;
    int y = 30;

    printf("\nBefore swapping using arithmetic operations and pointers:\n");
    printf("\tx = %d\n", x);
    printf("\ty = %d\n", y);

    // Swapping values using swap_arithmetic function
    swap_arithmetic(&x, &y);

    printf("\nAfter swapping using swap_arithmetic:\n");
    printf("\tx = %d\n", x);
    printf("\ty = %d\n", y);



    // Variable declaration and initialization
    int value1 = 100;
    int value2 = 200;

    printf("\nBefore swapping without using pointers:\n");
    printf("\tvalue1 = %d\n", value1);
    printf("\tvalue2 = %d\n", value2);

    // Swapping values using swap_values function (without pointers)
    swap_values(value1, value2);

    return 0;
}

