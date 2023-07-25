#include <stdio.h>
#include <stdlib.h> // Include this header for getchar()

#define MAX 100

/*********************************************************************************
 * Function Name: my_getline                                                     *
 * Description: Reads a line from input and stores it in a character array.      *
 *              Returns the length of the line.                                  *
 * Variables:                                                                    *
 *   - str_s: Pointer to the character array where the line is stored.           *
 *   - max: Maximum length of the line (including the null terminator).          *
 *********************************************************************************/
int my_getline(char *str_s, int max)
{
    int c;
    char *point_str = str_s;
    printf("Enter any string: ");
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        *point_str++ = c;
    if (c == '\n')
        *point_str++ = c;
    *point_str = '\0';
    return point_str - str_s;
}

int main(int argc, char *argv[])
{
    char str_s[MAX];
    while (my_getline(str_s, MAX) > 0)
        printf("Output from getline function with pointer: %s", str_s);

    return 0;
}

