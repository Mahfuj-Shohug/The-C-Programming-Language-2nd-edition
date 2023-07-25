#include <stdio.h>
#include <string.h>

#define MAXLINE 100 /* maximum input line length */

int getline(char line[], int maxline);
void remove_trailing_blanks(char line[], int length);

/***************************************************
 * Function Name: main
 * Description: Reads lines of input from the user, removes trailing blanks, and prints the result.
 * Parameters:
 *   - argc: Number of command-line arguments
 *   - argv: Array of command-line arguments
 * Returns: 0 on successful execution
 ****************************************************/
int main(int argc, char *argv[])
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("Input: %s", line);
        printf("Input Length: %d\n", len - 1); // Subtract 1 to exclude newline character

        remove_trailing_blanks(line, len);

        if (line[0] != '\n')
        {
            printf("Output: %s", line);
            printf("Output Length: %d\n\n", len - 1 - (len - 1 - strlen(line))); // Subtract trailing blanks length
        }
    }

    return 0;
}

/***************************************************
 * Function Name: getline
 * Description: Reads a line of input and stores it in the provided buffer.
 * Parameters:
 *   - s: Pointer to the buffer for storing the line
 *   - lim: Maximum length of the line buffer
 * Returns: The actual length of the line read
 ****************************************************/
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/***************************************************
 * Function Name: remove_trailing_blanks
 * Description: Removes trailing blanks and tabs from the end of a line.
 * Parameters:
 *   - line: Pointer to the line string
 *   - length: Length of the line
 ****************************************************/
void remove_trailing_blanks(char line[], int length)
{
    int i;

    // Start from the end of the line and move backward
    for (i = length - 2; i >= 0; --i)
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            break;
        }
    }

    line[i + 1] = '\n'; // Add back the newline character
    line[i + 2] = '\0'; // Terminate the line after the newline character
}

