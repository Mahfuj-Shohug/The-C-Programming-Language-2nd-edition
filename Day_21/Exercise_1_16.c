#include <stdio.h>

#define MAXLENGTH 100

int getLine(char *, int);
void copy_long_str(char *, char *);

/***************************************************
 * Function Name: main
 * Description: Reads lines of input from the user, finds the longest line, and prints it.
 * Parameters:
 *   - argc: Number of command-line arguments
 *   - argv: Array of command-line arguments
 * Returns: 0 on successful execution
 ****************************************************/
int main(int argc, char *argv[])
{
    int len, max = 0;
    char line[MAXLENGTH], longest[MAXLENGTH];
    char *linePtr = line;        // Pointer to the line array
    char *longestPtr = longest;  // Pointer to the longest array

    printf("Enter any string:\n");
    while ((len = getLine(linePtr, MAXLENGTH)) > 0)  // Read lines until len becomes 0
    {
        if (len > max)  // Check if the current line is longer than the previously stored longest line
        {
            max = len;  // Update the maximum length
            copy_long_str(longestPtr, linePtr);  // Copy the current line to the longest line buffer
        }
    }

    if (max > 0)  // Check if there is a longest line
    {
        if (max > MAXLENGTH)  // Check if the longest line exceeds the maximum allowed length
        {
            printf("\n\nStorage limit exceeded by: %d", max - MAXLENGTH);
            printf("\nString length: %d", max);
            printf("\nPlease enter a maximum %d length string", MAXLENGTH);
        }
        else
        {
            printf("\nString length: %d", max);
            printf("\nThe longest string is: %s", longest);
        }
    }
    printf("\n");
    return 0;
}

/***************************************************
 * Function Name: getLine
 * Description: Reads a line of input and stores it in the provided buffer.
 * Parameters:
 *   - line: Pointer to the buffer for storing the line
 *   - limit: Maximum length of the line buffer
 * Returns: The actual length of the line read
 ****************************************************/
int getLine(char *line, int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (((c = getchar()) != EOF) && (c != '\n')); i++)
        *(line++) = c;  // Store the character in the current pointer position and move the pointer

    if (i == (limit - 1))  // If the loop exited due to reaching the limit
    {
        while ((c = getchar()) != '\n')  // Continue reading characters until newline
        {
            ++i;
        }
    }

    if (c == '\n')
    {
        *(line++) = c;  // Store the newline character and move the pointer
        ++i;
    }

    *line = '\0';
    return i;  // Return the actual length of the line
}

/***************************************************
 * Function Name: copy_long_str
 * Description: Copies a string from the source to the destination.
 * Parameters:
 *   - to: Pointer to the destination string
 *   - from: Pointer to the source string
 ****************************************************/
void copy_long_str(char *to, char *from)
{
    while ((*to = *from) != '\0')  // Copy characters until the null terminator is encountered
    {
        ++to;
        ++from;
    }
}

