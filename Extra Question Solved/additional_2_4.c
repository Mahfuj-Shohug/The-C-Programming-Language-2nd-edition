#include <stdio.h>

int main()
{
    char array2[3][5] = {"a123", "b456", "c789"};
    char (*p2)[5] = array2;

    printf("array2 + 1: %d\n", array2 + 1);
    printf("&array2 + 1: %d\n", &array2 + 1);
    printf("&array2[0] + 1: %d\n", &array2[0] + 1);
    printf("p2++: %d\n", p2++);
    printf("*p2 + 1: %d\n", *p2 + 1);

    return 0;
}

