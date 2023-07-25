#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

/******************************************************
 * Function Name: remove_comments
 * Description: Removes comments from the input file and writes the result to the output file.
 * Parameters:
 *   - input_file: Pointer to the input file
 *   - output_file: Pointer to the output file
 * Returns: None
 ******************************************************/
void remove_comments(FILE *input_file, FILE *output_file)
{
    char line[MAX_LINE_LENGTH];
    int inside_string = 0;
    int inside_comment = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        size_t line_length = strlen(line);
        size_t i = 0;

        while (i < line_length)
        {
            // Handle different cases inside the line
            if (!inside_comment && !inside_string)   // Check if not inside a comment or string
            {
                if (line[i] == '"')
                {
                    // Check for the start of a string
                    inside_string = 1;
                    fputc(line[i], output_file);
                    i++;
                    continue;
                }

                if (line[i] == '/' && i + 1 < line_length)
                {
                    // Check for the start of a comment
                    if (line[i + 1] == '/')
                    {
                        // Skip the rest of the line, excluding the final '/'
                        while (i < line_length && line[i] != '\n')
                        {
                            i++;
                        }
                        fputc(line[i], output_file); // Write the final '/' to output
                        break;
                    } else if (line[i + 1] == '*')
                    {
                        // Multi-line comment
                        inside_comment = 1;
                        i++; // Skip the '*'
                        continue;
                    }
                }
            }

            if (inside_comment && line[i] == '*' && i + 1 < line_length && line[i + 1] == '/')
            {
                // Check for the end of a multi-line comment
                inside_comment = 0;
                i += 2; // Skip the '*/'
                continue;
            }

            if (!inside_comment)
            {
                // Check if not inside a comment
                fputc(line[i], output_file);
            }

            if (inside_string && line[i] == '"')
            {
                // Check for the end of a string
                inside_string = 0;
            }

            i++;
        }
    }
}

/******************************************************
 * Function Name: main
 * Description: The entry point of the program.
 * Returns:
 *   - EXIT_SUCCESS: If the program executes successfully
 ******************************************************/
int main(int argc, char *argv[])
{
    FILE *input_file = fopen("test_case_1.c", "r"); // Read with comment file
    FILE *output_file = fopen("test_case_1_nocomment.c", "w"); // Updated file create and write without comment

    if (input_file == NULL || output_file == NULL)
    {
        printf("Failed to open files.\n");
        return 1;
    }

    remove_comments(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Comments removed successfully.\n");

    return 0;
}

