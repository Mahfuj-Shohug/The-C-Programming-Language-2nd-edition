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

/************************************************************************
 * Function: detab                                                      *
 * Description: Replaces tab characters with spaces in the given line.  *
 *                                                                      *
 * Inputs:                                                              *
 *   - line: The input line to detab.                                   *
 *   - tab_width: The width of each tab character.                      *
 *   - tab_stops: Array of custom tab stops.                            *
 *   - num_stops: The number of custom tab stops.                       *
 *                                                                      *
 * Outputs:                                                             *
 *   - Modifies the 'line' array in-place by replacing tabs with spaces.*
 ************************************************************************/
void detab(char line[], int tab_width, int *tab_stops, int num_stops)
{
    int i, j, k, tab_count, stop_index;
    char detab_line[MAXLINE];
    i = j = tab_count = stop_index = 0;

    while (line[i] != '\0')
	{
        if (line[i] == '\t')
		{ // If a tab character is found
            if (num_stops > 0)
			{ // If custom tab stops are specified
                while (j % tab_stops[stop_index] != 0) // Fill with spaces until the next custom tab stop
                    detab_line[j++] = ' ';
                stop_index = (stop_index + 1) % num_stops; // Move to the next custom tab stop
            } else
			{ // If no custom tab stops are specified, use the default tab width
                while (j % tab_width != 0) // Fill with spaces until the next default tab stop
                    detab_line[j++] = ' ';
            }
        } else
		{ // If a non-tab character is found, copy it to the detabbed line
            detab_line[j++] = line[i];
        }
        i++;
    }
    detab_line[j] = '\0';

    // Copy the detabbed line back to the original line array
    for (k = 0; detab_line[k] != '\0'; k++)
        line[k] = detab_line[k];
    line[k] = '\0';
}

/*******************************************************************************************
 * Function: main                                                                          *
 * Description: Entry point of the program. Reads input lines and performs detab operation.*
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
    int tab_width = DEFAULT_TAB_WIDTH; // Default tab width
    int tab_stops[MAXLINE]; // Array to store custom tab stops
    int i, num_stops = 0; // Number of custom tab stops

    if (argc > 1)
	{
        tab_width = atoi(argv[1]); // Set tab width from command line argument
        if (tab_width <= 0)
		{
            printf("Invalid tab width. Using default.\n");
            tab_width = DEFAULT_TAB_WIDTH;
        }
    }

    for (i = 2; i < argc; i++)
	{
        tab_stops[num_stops] = atoi(argv[i]); // Store custom tab stops from command line arguments
        if (tab_stops[num_stops] <= 0)
		{
            printf("Invalid tab stop. Ignoring.\n");
        } else
		{
            num_stops++;
        }
    }

    char line[MAXLINE]; // Array to store input line
    while (get_line(line, MAXLINE) > 0)
	{ // Read input lines until end of file
        detab(line, tab_width, tab_stops, num_stops); // Replace tabs with spaces
        printf("%s", line); // Print detabbed line
    }

    return 0;
}

