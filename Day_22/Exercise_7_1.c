#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 500

/******************************************************
 * Function Name: convert_lower
 * Description: Converts a string to lowercase and prints it.
 * Parameters:
 *   - str: Pointer to the string to be converted
 ******************************************************/
void convert_lower(const char *str)
{
    int i;
	printf("Converted string is: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        putchar(tolower(str[i]));
    }
    printf("\n");
}

/******************************************************
 * Function Name: convert_upper
 * Description: Converts a string to uppercase and prints it.
 * Parameters:
 *   - str: Pointer to the string to be converted
 ******************************************************/
void convert_upper(const char *str)
{
    int i;
	printf("Converted string is: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        putchar(toupper(str[i]));
    }
    printf("\n");
}

/******************************************************
 * Function Name: main
 * Description: Entry point of the program.
 * Parameters:
 *   - argc: Number of command-line arguments
 *   - argv: Array of command-line argument strings
 * Returns: Integer indicating the exit status of the program
 ******************************************************/
int main(int argc, char *argv[])
{
    char str[MAX_LENGTH + 1];
    char c;
    int i = 0;

    printf("Please enter a string: ");

    while ((c = getchar()) != EOF && c != '\n' && i < MAX_LENGTH)
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';

    if (strcmp(argv[0], "lower") == 0)
    {
        convert_lower(str);
    } else if (strcmp(argv[0], "upper") == 0)
    {
        convert_upper(str);
    } else
    {
        printf("Wrong argument passed.\n");
    }

    return 0;
}

