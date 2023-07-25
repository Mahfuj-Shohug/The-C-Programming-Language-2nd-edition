#include <stdio.h>
#include <stdlib.h> // for malloc and free functions
#include <string.h> // for strlen function
#define MAX 20 // Define max length

void strcat_ptr(char *s, char *t, size_t max_length)
{
    if (s == NULL || t == NULL)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    size_t s_length = strlen(s);
    size_t t_length = strlen(t);
    if (s_length + t_length >= max_length)
    {
        printf("Error: Not Enough Specess for concatenation.\n");
        return;
    }

    // Move s pointer to the end of the string
    while (*s)
        s++;

    // Copy characters from t to the end of s
    while ((*s++ = *t++)) //got this logic from the book
        ;

    *s = '\0'; // Add the null-terminating character at the end
}

int main()
{
    // Test cases
    char str1[MAX] = "Hello, ";
    char *str2 = "Mahfuj!";
    printf("Test Case 1\nInput 1: %s\nInput 2: %s\n", str1, str2);
    strcat_ptr(str1, str2, MAX);
    printf("Concatenated string Output: %s\n\n", str1);

    char str3[MAX] = "Hi";
    char *str4 = "My Name Is Mahfuj Hasan Shohug!";
    printf("Test Case 2\nInput 1: %s\nInput 2: %s\n", str3, str4);
    strcat_ptr(str3, str4, MAX);
    printf("Concatenated string Output: %s\n\n", str3);

    char *str5 = malloc(10 * sizeof(char));
    strcpy(str5, "This is a");
    char *str6 = " test.";
    printf("Test Case 3\nInput 1: %s\nInput 2: %s\n", str5, str6);
    strcat_ptr(str5, str6, MAX);
    printf("Concatenated string Output: %s\n\n", str5);
    free(str5);

    // NULL pointer test case
    char *str7 = NULL;
    char *str8 = "Oops!";
    printf("Test Case 4\nInput 1: %s\nInput 2: %s\n", str7, str8);
    strcat_ptr(str7, str8, MAX);
    printf("\n");

    char *str9 = NULL;
    char *str10 = NULL;
    printf("Test Case 4\nInput 1: %s\nInput 2: %s\n", str9, str10);
    strcat_ptr(str9, str10, MAX);
    printf("\n");

    char str11[MAX] = "My Name Is Mahfuj ";
    char *str12 = " Hi";
    printf("Test Case 5\nInput 1: %s\nInput 2: %s\n", str11, str12);
    strcat_ptr(str11, str12, MAX);
    printf("Concatenated string Output: %s\n\n", str11);

    char str13[MAX] = "123456";
    char *str14 = "7890";
    printf("Test Case 5\nInput 1: %s\nInput 2: %s\n", str13, str14);
    strcat_ptr(str13, str14, MAX);
    printf("Concatenated string Output: %s\n\n", str13);
    return 0;
}

