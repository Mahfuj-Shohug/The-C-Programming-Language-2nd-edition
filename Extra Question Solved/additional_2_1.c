#include <stdio.h>

int main()
{
    char array1[20] = "hello world!";

    printf("Address of array1: %d\n", array1); // Address of array1: 6487552
    printf("Address of array1 + 1: %d\n", array1 + 1); //Address of array1: 6487552 + 1 = 6487553
    printf("Address of &array1 + 1: %d\n", &array1 + 1); //Address of array1: 6487552 + 20 = 6487572
    printf("Address of &array1[0] + 1: %d\n", &array1[0] + 1); //Address of array1: 6487552 + 1 = 6487553

    return 0;
}

