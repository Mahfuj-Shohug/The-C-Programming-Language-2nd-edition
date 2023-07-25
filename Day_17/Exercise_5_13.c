#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

/*********************************************************************************
 * Function: readlines                                                           *
 * Description: Reads lines from stdin and stores them in an array of pointers.  *
 *              It returns the number of lines read.                             *
 * Inputs:                                                                       *
 *   - lines: An array of pointers to store the lines.                           *
 *   - maxlines: The maximum number of lines that can be stored.                 *
 * Outputs:                                                                      *
 *   - Returns the number of lines read.                                         *
 *********************************************************************************/
int readlines(char *lines[], int maxlines) // Given this function on the book 
{
    int num_lines = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
    {
        lines[num_lines] = malloc(strlen(line) + 1);
        strcpy(lines[num_lines], line);
        num_lines++;
        if (num_lines >= maxlines)
        {
            printf("Input exceeds maximum line limit. Only storing %d lines.\n", maxlines);
            break;
        }
    }
    return num_lines;
}

/*********************************************************************************
 * Function: print_tail                                                          *
 * Description: Prints the last 'n' lines from the given array of pointers.      *
 * Inputs:                                                                       *
 *   - lines: An array of pointers containing the lines.                         *
 *   - n: The number of lines to print.                                          *
 * Outputs:                                                                      *
 *   - None. Prints the lines to stdout.                                         *
 *********************************************************************************/
void print_tail(char *lines[], int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        printf("%s", lines[i]);
        free(lines[i]); // Free the memory allocated for each line
    }
}

/************************************************************************
 * Function: main                                                       *
 * Description: The entry point of the program.                         *
 * Inputs:                                                              *
 *   - argc: The number of command-line arguments.                      *
 *   - argv: An array of strings containing the command-line arguments. *
 * Outputs:                                                             *
 *   - Returns 0 on successful execution.                               *
 ************************************************************************/
int main(int argc, char *argv[])
{
    int n = 10; // Default number of lines to print

    if (argc > 2 && strcmp(argv[1], "-n") == 0) // for -n
    {
        n = atoi(argv[2]); // Convert the argument to an integer
        if (n <= 0)
        {
            printf("Invalid input. Using default value.\n");
            n = 10; // Invalid input, use the default
        }
    }

    char *lines[MAX_LINES]; // Array to store lines
    int num_lines = readlines(lines, MAX_LINES);

    if (num_lines > 0)
    {
        int start = (num_lines > n) ? num_lines - n : 0;
        print_tail(&lines[start], num_lines - start);
    }

    return 0;
}

