#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/******************************************************
 * Function Name: compare_files
 * Description: Compares two files line by line and returns the line number where they differ.
 * Parameters:
 *   - file1: Pointer to the first file
 *   - file2: Pointer to the second file
 * Returns:
 *   - Line number where the files differ
 *   - -1 if the files are the same
 *   - -2 if the files have different lengths
 ******************************************************/
int compareFiles(FILE *file1, FILE *file2);

/******************************************************
 * Function Name: main
 * Description: Entry point of the program.
 * Parameters:
 *   - argc: Number of command-line arguments
 *   - argv: Array of command-line argument strings
 * Returns:
 *   - 0 if the program executed successfully
 *   - 1 if incorrect command-line arguments are provided
 *   - 2 if there are issues opening the files
 ******************************************************/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", argv[1]);
        return 2;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", argv[2]);
        fclose(file1);
        return 2;
    }

    int lineNum = compare_files(file1, file2);
    if (lineNum == -1)
    {
        printf("Files are Same.\n");
    }
    else if (lineNum == -2)
    {
        printf("Files have different lengths.\n");
    }
    else
    {
        printf("Files diffrent at line %d\n", lineNum);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}

int compare_files(FILE *file1, FILE *file2)
{
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int lineNum = 1;

    while (fgets(line1, sizeof(line1), file1) != NULL && fgets(line2, sizeof(line2), file2) != NULL)
    {
        if (strcmp(line1, line2) != 0)
        {
            return lineNum;
        }
        lineNum++;
    }

    if (!feof(file1) || !feof(file2))
    {
        return -2; // Files have different lengths
    }

    return -1; // Files are same
}

