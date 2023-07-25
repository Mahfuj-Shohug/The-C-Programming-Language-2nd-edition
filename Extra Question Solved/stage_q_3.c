#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char a1[3][4]={"1XYZ123", "2XYZ123", "3XYZ123"}; // Given input and waitch
    char (*p1)[4];
    char (*pa1)[4] = a1;  // Modified declaration

    // Loop through the array 'a1' using pointer arithmetic
    for(p1=a1; p1<a1+3; p1++, pa1++){
        printf("*p1 = %s\n", *p1);
        printf("pa1 = %s\n", *pa1);  // Dereference 'pa1'
    }

    printf("a[3][4]=%d\n",a1[2][3]);  // Access the correct element [2][3]
    printf("a1 size: %zu Bytes\n",sizeof(a1));  // Updated format specifier

    char *a2[3]={"1XYZ123","2XYZ123","3XYZ123"};
    char **p2;

    // Loop through the array 'a2' using pointer arithmetic
    for(p2=a2; p2<a2+3; p2++){ 
        printf("%s\n", *p2);
    }
    printf("a2 size: %zu Bytes\n",sizeof(a2));  // Updated format specifier
    printf("a2[1] size: %zu Bytes\n",sizeof(a2[1]));  // Updated format specifier
    printf("a2 size: %zu Bytes\n",sizeof(*a2[1]));  // Updated format specifier
    return 0;
}

