#include <stdio.h>
#include <string.h>
#define MAX 100

/*********************************************************************************
 * Function Name: getInput                                                       *
 * Description: Reads input from the user and removes the trailing newline       *
 *              character.                                                       *
 * Inputs:                                                                       *
 *   - input: The input string to store the user input.                          *
 *   - size: The maximum size of the input string.                               *
 * Outputs: None                                                                 *
 *********************************************************************************/
void get_input(char input[], int size)
{
    fgets(input, size, stdin);

    // Remove the trailing newline character from the input
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n')
        input[input_length - 1] = '\0';
}

/*********************************************************************************
 * Function Name: str_copy                                                       *
 * Description: Copies the characters from the source string to the destination  *
 *              string.                                                          *
 * Inputs:                                                                       *
 *   - s_str: The destination string to copy into.                               *
 *   - t_str: The source string to copy from.                                    *
 * Outputs: None                                                                 *
 *********************************************************************************/

void str_copy(char *s_str, char *t_str)
{
    // Find the end of the destination string s_str
    while (*s_str != '\0')
        s_str++;

    // Copy characters from the source string t_str to s_str
    while (*s_str++ = *t_str++)
        ;
}
/* Main function where copy t and store in s */
int main(int argc, char *argv[])
{
    char s_str[MAX], t_str[MAX];
    printf("Enter First String: ");
    get_input(s_str, MAX);
    printf("Enter Second String: ");
    get_input(t_str, MAX);

    // Copy the second string into the first string
    str_copy(s_str, t_str);

    printf("The copied string is: %s\n", s_str);

    return 0;
}

