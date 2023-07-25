#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void fieldSort(void *lineptr[], int left, int right, int field, int (*comp)(const char *, const char *));
int numcmp(const char *s1, const char *s2);
int foldcmp(const char *s1, const char *s2);

/**********************************************************************
 * Function Name: main                                                *
 * Description: Entry point of the program.                           *
 * Parameters:                                                        *
 *   - argc: Number of command-line arguments.                        *
 *   - argv: Array of strings containing the command-line arguments.  *
 * Returns:                                                           *
 *   - 0 on successful execution, 1 on error.                         *
 **********************************************************************/
int main(int argc, char *argv[])
{
    int nlines, i;
    int field = 0;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;

    // Check command-line arguments for flags
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if (strcmp(argv[i], "-r") == 0)
            reverse = 1;
        else if (strcmp(argv[i], "-f") == 0)
            fold = 1;
        else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc)
            field = atoi(argv[++i]);
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        int i, j;
		fieldSort((void **)lineptr, 0, nlines - 1, field, (int (*)(const char *, const char *))(numeric ? numcmp : (fold ? foldcmp : strcmp)));
        if (reverse)
        {
            // Reverse the sorted lines
            for (i = 0, j = nlines - 1; i < j; i++, j--)
            {
                void *temp = lineptr[i];
                lineptr[i] = lineptr[j];
                lineptr[j] = temp;
            }
        }
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

/******************************************************************************************
 * Function Name: readlines                                                               *
 * Description: Reads lines from input and stores them in an array of pointers to strings.*
 * Parameters:                                                                            *
 *   - lineptr: Array of pointers to strings where the lines will be stored.              *
 *   - maxlines: Maximum number of lines to read.                                         *
 * Returns:                                                                               *
 *   - The number of lines read.                                                          *
 ******************************************************************************************/
int readlines(char *lineptr[], int maxlines)
{
    int nlines = 0;
    char line[MAXLEN];

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character
        lineptr[nlines] = strdup(line); // Store a copy of the line
        nlines++;
    }

    return nlines;
}

/*****************************************************************************************
 * Function Name: writelines                                                             *
 * Description: Writes the lines stored in an array of pointers to strings to the output.*
 * Parameters:                                                                           *
 *   - lineptr: Array of pointers to strings containing the lines to write.              *
 *   - nlines: Number of lines to write.                                                 *
 * Returns:                                                                              *
 *   - None.                                                                             *
 *****************************************************************************************/
void writelines(char *lineptr[], int nlines)
{
    int i;
	for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

/*****************************************************************************************
 * Function Name: fieldSort                                                              *
 * Description: Sorts an array of pointers based on a specific field in each line.       *
 * Parameters:                                                                           *
 *   - lineptr: Array of pointers to be sorted.                                          *
 *   - left: Left index of the array to start sorting.                                   *
 *   - right: Right index of the array to end sorting.                                   *
 *   - field: Field number to consider for sorting (1-based indexing).                   *
 *   - comp: Comparison function for determining the order of elements.                  *
 * Returns: None.                                                                        *
 *****************************************************************************************/
void fieldSort(void *v[], int left, int right, int field, int (*comp)(const char *, const char *))
{
    int i, j, count;
    void *temp;
    char *line1, *line2;
    char *token1, *token2;

    for (i = left; i < right; i++)
    {
        for (j = i + 1; j <= right; j++)
        {
            line1 = strdup((char *)v[i]); // Create a copy of line1
            line2 = strdup((char *)v[j]); // Create a copy of line2

            // Extract fields from lines
            count = 1;
            token1 = strtok(line1, " "); // Tokenize line1 by space

            while (count < field && token1 != NULL)
            {
                token1 = strtok(NULL, " "); // Move to the next field
                count++;
            }

            count = 1;
            token2 = strtok(line2, " "); // Tokenize line2 by space

            while (count < field && token2 != NULL)
            {
                token2 = strtok(NULL, " "); // Move to the next field
                count++;
            }

            // Compare field values
            if ((*comp)(token1, token2) > 0)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }

            free(line1); // Free the memory allocated for line1
            free(line2); // Free the memory allocated for line2
        }
    }
}



/****************************************************
 * Function Name: numcmp                            *
 * Description: Compares two strings numerically.   *
 * Parameters:                                      *
 *   - s1: Pointer to the first string to compare.  *
 *   - s2: Pointer to the second string to compare  *
 * Returns:                                         *
 *   - -1 if s1 < s2, 0 if s1 == s2, 1 if s1 > s2.  *
 ****************************************************/
int numcmp(const char *s1, const char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/**********************************************************
 * Function Name: foldcmp                                 *
 * Description: Compares two strings case-insensitively.  *
 * Parameters:                                            *
 *   - s1: First string to compare.                       *
 *   - s2: Second string to compare.                      *
 * Returns:                                               *
 *   - Negative value if s1 is less than s2.              *
 *   - Positive value if s1 is greater than s2.           *
 *   - 0 if s1 and s2 are equal.                          *
 **********************************************************/
int foldcmp(const char *s1, const char *s2)
{
    for (; *s1 && *s2; s1++, s2++)
    {
        if (tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
    }

    return *s1 - *s2;
}

