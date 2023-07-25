#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define DEFAULT_TAB_WIDTH 4

/********************************************************************************
 * Function: get_line                                                           *
 * Description: Reads a line of input from the user.                            *
 *                                                                              *
 * Inputs:                                                                      *
 *   - line: An array to store the line read from input.                        *
 *   - maxline: The maximum length of the line that can be stored.              *
 *                                                                              *
 * Outputs:                                                                     *
 *   - Returns the number of characters read, including the newline character.  *
 ********************************************************************************/
int get_line(char line[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
	{
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/****************************************************************************************
 * Function: entab                                                                      *
 * Description: Replaces spaces with tabs and spaces according to the given tab width.  *
 *                                                                                      *
 * Inputs:                                                                              *
 *   - line: An array representing the input line to be modified.                       *
 *   - tab_width: The desired width of each tab in spaces.                              *
 *                                                                                      *
 * Outputs:                                                                             *
 *   - Modifies the 'line' array to contain the modified line with tabs and spaces.     *
 ****************************************************************************************/
void entab(char line[], int tab_width)
{
    int i, j, space_count, tab_count;
    char entab_line[MAXLINE];
    i = j = space_count = tab_count = 0;

    while (line[i] != '\0')
	{
        if (line[i] == ' ')
		{
            space_count++;
            if (space_count == tab_width)
			{
                tab_count++;
                space_count = 0;
            }
        } else
		{
            // Convert accumulated spaces to tabs
            for (; tab_count > 0; tab_count--)
			{
                entab_line[j] = '\t';
                j++;
            }

            // Add remaining individual spaces
            if (space_count > 0)
			{
                for (; space_count > 0; space_count--)
				{
                    entab_line[j] = ' ';
                    j++;
                }
            }

            // Add the non-space character
            entab_line[j] = line[i];
            j++;
        }
        i++;
    }

    // Terminate the modified line
    entab_line[j] = '\0';

    // Copy the modified line back to the original line array
    for (i = 0; entab_line[i] != '\0'; i++)
        line[i] = entab_line[i];
    line[i] = '\0';
}
/*******************************************************************************************
 * Function: main                                                                          *
 * Description: Entry point of the program. Reads input lines and performs entab operation.*
 *                                                                                         *
 * Inputs:                                                                                 *
 *   - argc: Number of command-line arguments passed to the program.                       *
 *   - argv: Array of strings containing the command-line arguments.                       *
 *                                                                                         *
 * Outputs:                                                                                *
 *   - Returns 0 to indicate successful execution of the program.                          *
 *******************************************************************************************/
int main(int argc, char *argv[])
{
    int tab_width = DEFAULT_TAB_WIDTH;

    if (argc > 1)
	{
        tab_width = atoi(argv[1]);
        if (tab_width <= 0)
		{
            printf("Invalid tab width. Using default.\n");
            tab_width = DEFAULT_TAB_WIDTH;
        }
    }

    char line[MAXLINE];
    while (get_line(line, MAXLINE) > 0)
	{
        entab(line, tab_width);
        printf("%s", line);
    }

    return 0;
}


