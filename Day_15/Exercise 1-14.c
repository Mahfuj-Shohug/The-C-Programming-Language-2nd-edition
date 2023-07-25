#include <stdio.h>

#define MAX 128

/******************************************************************************************
** Function: count_char
** Inputs: int char_counts[], int max_chars
** Variables: int input_char
** Return: void
** Description: This function reads characters from input and counts their frequencies.
*******************************************************************************************/
void count_char(int char_counts[], int max_chars)
{
    int input_char;

    printf("Enter any string:\n");

    while ((input_char = getchar()) != EOF)
	{
        if (input_char >= 0 && input_char < max_chars)
		{
            char_counts[input_char]++;
        }
    }
}

/******************************************************************************************
** Function: char_histogram
** Inputs: int char_counts[], int max_chars
** Variables: int i, j
** Return: void
** Description: This function prints a histogram of character frequencies.
*******************************************************************************************/
void char_histogram(int char_counts[], int max_chars)
{
    printf("\nCharacter Histogram:\n");
	
	int i, j;
    for (i = 0; i < max_chars; i++)
	{
        if (char_counts[i] > 0)
		{
            printf("%c: ", i);

            for (j = 0; j < char_counts[i]; j++)
			{
                printf("\4");
            }

            printf("\n");
        }
    }
}

int main()
{
    int char_counts[MAX] = {0}; // Initialize array

    count_char(char_counts, MAX); // Count character frequencies
    char_histogram(char_counts, MAX); // Print character histogram

    return 0;
}

