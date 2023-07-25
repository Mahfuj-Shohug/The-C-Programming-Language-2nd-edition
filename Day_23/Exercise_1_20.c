#include <stdio.h>

#define TAB_WIDTH 8  // Number of spaces for each tab

/******************************************************
 * Function Name: detab
 * Description: Reads input from standard input and replaces tabs with spaces.
 *              The number of spaces per tab is determined by the TAB_WIDTH constant.
 * Parameters: None
 * Returns:   void
 ******************************************************/
void detab()
{
    int i, c, position;

    position = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spaces = TAB_WIDTH - (position % TAB_WIDTH);
            for (i = 0; i < spaces; i++) {
                putchar('^');  // Print '^' as a space instead of a tab for understand
                position++;
            }
        }
        else if (c == '\n')
        {
            putchar(c);  // Print the newline character
            position = 0;  // Reset the position to the beginning of the line
        }
        else
        {
            putchar(c);  // Print other characters as is
            position++;
        }
    }
}

int main()
{
    detab();  // Call the detab function to perform tab replacement

    return 0;
}

