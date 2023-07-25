#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // for tolower()

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void reverseSort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
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
    int nlines, i, j;
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
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        // Choose the appropriate comparison function based on flags
        int (*comp)(void *, void *);
        if (numeric)
            comp = (int (*)(void *, void *))(numcmp);
        else if (fold)
            comp = (int (*)(void *, void *))(foldcmp);
        else
            comp = (int (*)(void *, void *))(strcmp);

        reverseSort((void **)lineptr, 0, nlines - 1, comp);
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
    char line[MAXLINES];
	
	printf("Enter your input =>\n");
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character
        lineptr[nlines] = strdup(line);
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
	printf("The shorted output (Case Handel) is =>\n");
	for (i = 0; i < nlines; i++)
    {
        printf("\t%s\n", lineptr[i]);
    }
}
/****************************************************************************************
 * Function Name: reverseSort                                                           *
 * Description: Sorts an array of pointers using the reverse bubble sort algorithm.     *
 * Parameters:                                                                          *
 *   - lineptr: Array of pointers to sort.                                              *
 *   - left: Starting index of the range to sort.                                       *
 *   - right: Ending index of the range to sort.                                        *
 *   - comp: Pointer to the comparison function used to determine the order of elements.*
 * Returns:                                                                             *
 *   - None.                                                                            *
 ****************************************************************************************/
void reverseSort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, j;
    void *temp;

    for (i = left; i < right; i++)
    {
        for (j = i + 1; j <= right; j++)
        {
            if ((*comp)(v[i], v[j]) > 0)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
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
    while (*s1 && *s2)
    {
        if (tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
        s1++;
        s2++;
    }

    return 0;
}


