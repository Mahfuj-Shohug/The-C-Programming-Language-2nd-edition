#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function Declarations

/******************************************************
 * Function Name: isupper_lookup
 * Description: Checks if a character is uppercase using a lookup table.
 * Parameters:
 *   - c: The character to check
 * Returns:
 *   - true if the character is uppercase
 *   - false otherwise
 ******************************************************/
bool isupper_lookup(char c);

/******************************************************
 * Function Name: isupper_strchr
 * Description: Checks if a character is uppercase using the strchr function.
 * Parameters:
 *   - c: The character to check
 * Returns:
 *   - true if the character is uppercase
 *   - false otherwise
 ******************************************************/
bool isupper_strchr(char c);

/******************************************************
 * Function Name: isupper_custom
 * Description: Checks if a character is uppercase using a custom implementation.
 * Parameters:
 *   - c: The character to check
 * Returns:
 *   - true if the character is uppercase
 *   - false otherwise
 ******************************************************/
bool isupper_custom(char c);

/******************************************************
 * Function Name: main
 * Description: Reads characters from input until 'x' is entered and
 *              checks if each character is uppercase using different methods.
 * Returns:
 *   - EXIT_SUCCESS: If the program runs successfully
 ******************************************************/
int main(void)
{
    int c;

    while ((c = getchar()) != 'x')
	{
        if (c == '\n')
            continue;

        printf("Lookup: %s\n", isupper_lookup(c) ? "true" : "false");
        printf("Strchr: %s\n", isupper_strchr(c) ? "true" : "false");
        printf("Custom: %s\n", isupper_custom(c) ? "true" : "false");
    }

    return EXIT_SUCCESS;
}

// Method 1: Lookup Table
bool isupper_lookup(char c) {
    static const bool lookup_table[256] = {
        ['A'] = true, ['B'] = true, ['C'] = true, ['D'] = true, ['E'] = true,
        ['F'] = true, ['G'] = true, ['H'] = true, ['I'] = true, ['J'] = true,
        ['K'] = true, ['L'] = true, ['M'] = true, ['N'] = true, ['O'] = true,
        ['P'] = true, ['Q'] = true, ['R'] = true, ['S'] = true, ['T'] = true,
        ['U'] = true, ['V'] = true, ['W'] = true, ['X'] = true, ['Y'] = true,
        ['Z'] = true
    };
    return lookup_table[(unsigned char)c];
}

// Method 2: Strchr Function
bool isupper_strchr(char c)
{
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}

// Method 3: Custom Implementation
bool isupper_custom(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

