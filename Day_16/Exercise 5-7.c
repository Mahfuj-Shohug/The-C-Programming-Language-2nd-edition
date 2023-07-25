#include <stdio.h>
#include <string.h>

#define MAXLINES 10000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines, char *storStr, int *nextFreeLoc);
void writelines(char *lineptr[], int nlines);

#define MAXLEN 10000

void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

#define MAXSTRLEN 10000

/******************************************************************************************
** Function: main
** Description: Entry point of the program.
** Inputs:
**     - None
** Outputs:
**     - Returns 0 on success, non-zero on failure.
*******************************************************************************************/
int main(int argc, char *argv[]) 
{
    int nlines;
    char storStr[MAXSTRLEN];
    int nextFreeLoc = 0;
    printf("Enter Some Lines->\n");
    if ((nlines = readlines(lineptr, MAXLINES, storStr, &nextFreeLoc)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/******************************************************************************************
** Function: getline
** Description: Reads a line from input and stores it in the provided string.
** Inputs:
**     - s: Pointer to the string where the line will be stored.
**     - lim: Maximum length of the string.
** Outputs:
**     - Returns the length of the line read (excluding the null terminator).
*******************************************************************************************/
int getline(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/******************************************************************************************
** Function: readlines
** Description: Reads lines from input and stores them in an array of strings.
** Inputs:
**     - lineptr: Array of string pointers to store the lines.
**     - maxlines: Maximum number of lines that can be stored.
**     - storStr: Buffer to store the lines.
**     - nextFreeLoc: Pointer to the next free location in the buffer.
** Outputs:
**     - Returns the number of lines read on success, -1 on failure.
*******************************************************************************************/
int readlines(char *lineptr[], int maxlines, char *storStr, int *nextFreeLoc) // Change here for parameter pointer 
{
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (MAXSTRLEN - *nextFreeLoc) < len) //add condition for replacing alloc function 
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(&storStr[*nextFreeLoc], line);
            lineptr[nlines] = &storStr[*nextFreeLoc];
            *nextFreeLoc += len;
            nlines++;
        }
    }
    return nlines;
}

/******************************************************************************************
** Function: writelines
** Description: Writes the lines stored in an array of strings to the output.
** Inputs:
**     - lineptr: Array of string pointers containing the lines.
**     - nlines: Number of lines to write.
** Outputs:
**     - None
*******************************************************************************************/
void writelines(char *lineptr[], int nlines)
{
    while (nlines--)
    {
        printf("%s\n", *lineptr++);
    }
}

/******************************************************************************************
** Function: qsort
** Description: Sorts an array of strings using the quicksort algorithm.
** Inputs:
**     - v: Array of string pointers to be sorted.
**     - left: Starting index of the array.
**     - right: Ending index of the array.
** Outputs:
**     - None
*******************************************************************************************/
void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/******************************************************************************************
** Function: swap
** Description: Swaps two string pointers.
** Inputs:
**     - v: Array of string pointers.
**     - i: Index of the first pointer.
**     - j: Index of the second pointer.
** Outputs:
**     - None
*******************************************************************************************/
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

