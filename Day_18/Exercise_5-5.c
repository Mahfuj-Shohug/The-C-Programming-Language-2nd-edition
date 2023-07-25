#include <stdio.h>
#include <string.h>
#define MAX 100
/***************************************************************************************
 * Function Name: get_input                                                            *
 * Description: Reads input from the user and removes the trailing newline character.  *
 * Parameters:                                                                         *
 *    - input: char array to store the user input                                      *
 *    - size: maximum size of the input array                                          *
 ***************************************************************************************/
void get_input(char input[], int size)
{
    fgets(input, size, stdin);

    // Remove the trailing newline character from the input
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n')
        input[input_length - 1] = '\0';
}

/**********************************************************************************************
 * Function Name: str_ncpy                                                                    *
 * Description: Copies the first n characters of the source string to the destination string. *
 * Parameters:                                                                                *
 *    - s_str: pointer to the destination string                                              *
 *    - t_str: pointer to the source string                                                   *
 *    - n: maximum number of characters to be copied                                          *
 **********************************************************************************************/
void str_ncpy(char *s_str, const char *t_str, int n)
{
    while (*t_str && n > 0)
    {
        *s_str++ = *t_str++;
        n--;
    }
    while (n > 0)
    {
        *s_str++ = '\0';  // pad remaining characters with null
        n--;
    }
}

/***********************************************************************************************
 * Function Name: str_ncat                                                                     *
 * Description: Appends the first n characters of the source string to the destination string. *
 * Parameters:                                                                                 *
 *    - s_str: pointer to the destination string                                               *
 *    - t_str: pointer to the source string                                                    *
 *    - n: maximum number of characters to be appended                                         *
 ***********************************************************************************************/
void str_ncat(char *s_str, const char *t_str, int n)
{
    while (*s_str)
        s_str++;  // find the end of s
    while (*t_str && n > 0)
    {
        *s_str++ = *t_str++;
        n--;
    }
    *s_str = '\0';  // null-terminate s
}

/*********************************************************************************
 * Function Name: str_ncmp                                                       *
 * Description: Compares the first n characters of two strings.                  *
 * Parameters:                                                                   *
 *    - s_str: pointer to the first string                                       *
 *    - t_str: pointer to the second string                                      *
 *    - n: number of characters to compare                                       *
 * Returns:                                                                      *
 *    - 0 if the first n characters of both strings match                        *
 *    - 1 if the strings do not match or n characters are not equal              *
 *********************************************************************************/
int str_ncmp(const char *s_str, const char *t_str, int n)
{
    for (; *s_str == *t_str && n > 0; s_str++, t_str++, n--)
    {
        if (*s_str == '\0')
            return 0;  // reached the end of both strings
    }
    return (n == 0) ? 0 : 1;
}

/*********************************************************************************
 * Function Name: main                                                           *
 * Description: Entry point of the program.                                      *
 *    - 0 on successful execution                                                *
 *********************************************************************************/
int main(int argc, char *argv[])
{
    char s_str1[MAX], t_str1[MAX], s_str2[MAX], t_str2[MAX], s_str3[MAX], t_str3[MAX];
    int n;

    // Input for Str N Copy
    printf("(For Str N Copy) Enter First String: ");
    get_input(s_str1, MAX);
    printf("(For Str N Copy) Enter Second String: ");
    get_input(t_str1, MAX);
    printf("(For Str N Copy) Enter the position of N: ");
    scanf("%d", &n);
    getchar(); // consume the newline character
    str_ncpy(s_str1, t_str1, n);
    printf("String copy from 1 to %d number position of the second string: %s\n\n", n, s_str1);

    // Input for Str N Cat
    printf("(For Str N Cat) Enter First String: ");
    get_input(s_str2, MAX);
    printf("(For Str N Cat) Enter Second String: ");
    get_input(t_str2, MAX);
    printf("(For Str N Cat) Enter the position of N: ");
    scanf("%d", &n);
    getchar(); // consume the newline character
    str_ncat(s_str2, t_str2, n);
    printf("String Cat from 1 to %d number position: %s\n\n", n, s_str2);

    // Input for Str N Compare
    printf("(For Str N Compare) Enter First String: ");
    get_input(s_str3, MAX);
    printf("(For Str N Compare) Enter Second String: ");
    get_input(t_str3, MAX);
    printf("(For Str N Compare) Enter the position of N: ");
    scanf("%d", &n);
    getchar(); // consume the newline character
    int result = str_ncmp(s_str3, t_str3, n);
    if (result == 0)
        printf("Strings \"%s\" and \"%s\" Match from 1 to %d Number Position\n", s_str3, t_str3, n);
    else
        printf("Strings \"%s\" and \"%s\" Do Not Match from 1 to %d Number Position\n", s_str3, t_str3, n);

    return 0;
}

