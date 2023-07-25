#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************************************
 * Function Name: find_longest_word_length
 * Description: Finds the length of the longest word in the given line.
 * Parameters:
 *   - line: The line to be analyzed
 * Returns:
 *   - The length of the longest word in the line
 ******************************************************/
int find_longest_word_length(char line[])
{
    int i, max_word_length = 0;
    int length = strlen(line);
    int word_length = 0;

    for (i = 0; i < length; i++)
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            word_length++;
        } else
        {
            if (word_length > max_word_length)
            {
                max_word_length = word_length;
            }
            word_length = 0;
        }
    }

    // Check if the last word is the longest
    if (word_length > max_word_length)
    {
        max_word_length = word_length;
    }

    return max_word_length;
}

/******************************************************
 * Function Name: fold_lines
 * Description: Folds long lines in the given line to fit within the specified maximum length.
 * Parameters:
 *   - line: The line to be folded
 *   - max_length: The maximum length of each folded line
 * Returns: None
 ******************************************************/
void fold_lines(char line[], int max_length)
{
    int length = strlen(line);

    if (length <= max_length)
    {
        printf("%s\n", line);  // No need to fold if line is shorter than or equal to max_length
    } else
    {
        int i, start_index = 0;
        int end_index = max_length - 1;

        while (end_index < length)
        {
            // Find the previous space or tab from end_index
            while (end_index >= start_index && line[end_index] != ' ' && line[end_index] != '\t')
            {
                end_index--;
            }

            // If no space or tab found, fold at end_index
            if (end_index < start_index)
            {
                end_index += max_length;
            }

            // Print the folded line
            for (i = start_index; i <= end_index; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");

            start_index = end_index + 1;
            end_index = start_index + max_length - 1;
        }

        // Print the remaining part of the line
        if (start_index < length)
        {
            for (i = start_index; i < length; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

/******************************************************
 * Function Name: main
 * Description: The entry point of the program.
 * Returns:
 *   - EXIT_SUCCESS: If the program executes successfully
 ******************************************************/
int main()
{
    int max_line_length = 0;
    char line[1000];
    printf("Enter your input here:\n");
    fgets(line, sizeof(line), stdin);

    // Find the length of the longest word
    int max_word_length = find_longest_word_length(line);

    // Adjust max_line_length based on the longest word
    max_line_length = (max_word_length > 0) ? max_word_length : 1;
    printf("\nThe Longest word length on this paragraph is = %d\n\n", max_word_length);
    fold_lines(line, max_line_length);

    return 0;
}

