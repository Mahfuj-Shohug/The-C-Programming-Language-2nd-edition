#include <stdio.h>

int strindex(const char *s, const char *t);
int getop(const char *s);

/*Main function*/
int main(int argc, char *argv[])
{
    // Test strindex
    const char *str = "Hello, World!";
    const char *substr = "World";
    int index = strindex(str, substr);
    printf("The pattern found in the index num: %d\n", index);

    // Test getop
    const char *expr = "4 5 3 2";
    int result = getop(expr);
    printf("Top value: %d\n", result);

    return 0;
}

/******************************************************************************************************
 * Function Name: strindex                                                                            *
 * Description: Searches for the last occurrence of a substring within a string and returns its index.*
 * Parameters:                                                                                        *
 *   - s: Pointer to the string to search in.                                                         *
 *   - t: Pointer to the substring to search for.                                                     *
 * Returns:                                                                                           *
 *   - The index of the last occurrence of the substring within the string, or -1 if not found.       *
 ******************************************************************************************************/
int strindex(const char *s, const char *t)
{
    const char *start = s;
    const char *p, *q;

    while (*s) {
        p = s;
        q = t;

        while (*p && *q && (*p == *q))
		{
            p++;
            q++;
        }

        if (*q == '\0')
		{
            return s - start;
        }

        s++;
    }

    return -1;
}

/**************************************************************************************
 * Function Name: getop                                                               *
 * Description: Parses the next operand from a string and returns its integer value.  *
 * Parameters:                                                                        *
 *   - s: Pointer to the string containing the expression.                            *
 * Returns:                                                                           *
 *   - The integer value of the operand, or 0 if not a valid operand.                 *
 **************************************************************************************/
int getop(const char *s)
{
    // Simulating a simplified getop function for illustration purposes
    return (*s >= '0' && *s <= '9') ? (*s - '0') : 0;
}

