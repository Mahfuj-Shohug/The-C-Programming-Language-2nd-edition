#include <stdio.h>

#define MAX  1000 // Maximum word length

/******************************************************************************************
** Function: word_count
** Inputs: int word[], int *longest, int *most
** Variables: int status, i, len; char c;
** Return: void
** Description: This function counts the occurrences of words with different lengths in the input text.
*******************************************************************************************/
void word_count(int word[], int *longest, int *most)
{
    int status, i, len;
    char c;

    for (i = 0; i < MAX; i++)
	{
        word[i] = 0; // Initialize word count array
    }

    len = 0;
    status = 0;

	printf("Enter any text:\n");
    while ((c = getchar()) != EOF) // Read characters until the end of input
	{ 
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') // Check if the character is a letter
		{ 
            if (status == 0)
			{
                status = 1; // Start of a new word
                ++word[len]; // Increment the count for the current word length
                len = 1; // Reset length for the new word
            } else 
			{
                ++len; // Increment the length of the current word
            }
        } else
		{
            status = 0; // Non-alphabetic character, word ended
        }
    }
    ++word[len]; // Increment the count for the last word length

    *longest = 0;
    *most = 0;

    for (i = 1; i < MAX; i++) // Find the longest word length and most frequent word length
	{ 
        if (word[i] && i > *longest)
		{
            *longest = i; // Update the longest word length
        }
        if (word[i] > *most)
		{
            *most = word[i]; // Update the count for the most frequent word length
        }
    }
}

/******************************************************************************************
** Function: print_horizontal_histogram
** Inputs: int word[], int longest
** Variables: int i, j;
** Return: void
** Description: This function prints a horizontal histogram representing the word count for each word length.
*******************************************************************************************/
void print_horizontal_histogram(int word[], int longest)
{
    int i, j;

    puts("\nHORIZONTAL HISTOGRAM");
    puts("\nword length => graph");

    for (i = 1; i <= longest; i++) // Iterate over word lengths up to the longest
	{ 
        printf("%11d => ", i);
        for (j = 1; j <= word[i]; j++) // Print 'x' for each occurrence of the word length
		{ 
            printf("\4");
        }
        putchar('\n');
    }
}

/******************************************************************************************
** Function: print_vertical_histogram
** Inputs: int word[], int longest, int most
** Variables: int i, j, k;
** Return: void
** Description: This function prints a vertical histogram representing the word count for each word length.
*******************************************************************************************/
void print_vertical_histogram(int word[], int longest, int most)
{
    int i, j, k;

    puts("\nVERTICAL HISTOGRAM");
    puts("\nWd Ct:");

    for (k = most; k > 0; k--) // Iterate from the most frequent word length down to 1
	{ 
        printf("%5d=>  ", k);
        for (i = 1; i <= longest; i++) // Iterate over word lengths up to the longest
		{ 
            if (word[i] < k)
			{
                printf("    "); // Print empty space if the count is less than the current level
            } else
			{
                printf("\4   "); // Print 'x' if the count is equal to or greater than the current level
            }
        }
        putchar('\n');
    }

    printf("      ");
    for (i = 1; i <= longest; i++)
	{
        printf("===="); // Print horizontal line for the word lengths
    }
    printf("\nWd Ln:");
    for (i = 1; i <= longest; i++)
	{
        printf("%4d", i); // Print the word lengths at the bottom
    }
    putchar('\n');
}

/******************************************************************************************
** Function: main
** Inputs: int argc, char *argv[]
** Variables: int word[MAX], longest, most;
** Return: int
** Description: This is the main function that executes the word counting and histogram printing operations.
*******************************************************************************************/
int main(int argc, char *argv[]) 
{
    int word[MAX]; // Array to store word count for each length
    int longest, most; // Variables to store the longest word length and most frequent word count

    word_count(word, &longest, &most); // Count word lengths and find the longest and most frequent lengths
    printf("\ngreatest word length: %d\n", longest);
    printf("most words of a given length: %d\n", most);
    print_horizontal_histogram(word, longest); // Print the horizontal histogram
    print_vertical_histogram(word, longest, most); // Print the vertical histogram

    return 0;
}

