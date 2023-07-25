#include <stdio.h>
int atoi(const char *s);
void itoa(int n, char *s);
void s_reverse(char *s);

/*Main function*/
int main(int argc, char *argv[])
{
    char s[100];

    // Test atoi
    int num = atoi("12345");
    printf("Integer value: %d\n", num);

    // Test itoa
    itoa(-12345, s);
    printf("String representation: %s\n", s);

    //Test reverse
    s_reverse(s);
    printf("Reversed string: %s\n", s);

    return 0;
}

/************************************************************************************
 * Function Name: atoi                                                              *
 * Description: Converts a string representation of an integer to an integer value. *
 * Parameters:                                                                      *
 *   - s: Pointer to the string representation of the integer.                      *
 * Returns:                                                                         *
 *   - The integer value represented by the string.                                 *
 ************************************************************************************/
int atoi(const char *s)
{
    int sign = 1;
    int n = 0;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
    {
        n = n * 10 + (*s - '0');
        s++;
    }

    return sign * n;
}
/*****************************************************************************************
 * Function Name: itoa                                                                   *
 * Description: Converts an integer to its string representation.                        *
 * Parameters:                                                                           *
 *   - n: The integer value to be converted.                                             *
 *   - s: Pointer to the character array where the string representation will be stored. *
 * Returns:                                                                              *
 *   - None.                                                                             *
 *****************************************************************************************/
void itoa(int n, char *s)
{
    int sign = n;

    if (sign < 0)
    {
        n = -n;
    }

    char *p = s;

    do
    {
        *p++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        *p++ = '-';
    }
    *p = '\0';
    s_reverse(s);
    return ;
}
/**********************************************************
 * Function Name: s_reverse                               *
 * Description: Reverses a string in-place.               *
 * Parameters:                                            *
 *   - s: Pointer to the string to be reversed.           *
 * Returns:                                               *
 *   - None.                                              *
 **********************************************************/
void s_reverse(char *s)
{
    char *start = s;
    char *end = s;

    while (*end)
    {
        end++;
    }
    end--;  // Move back from null character

    while (start < end)
    {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

