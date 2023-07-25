#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
/**************************************************************************************
** Function Name: main, getInput, string_index, 					  				 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: str[], str_p[]-- Inputed string		                             **
** 				: low_temp	-- lowest value of tempture 0							 **
**				: size	 	-- 	size of string										 **
**				: i, j, k	-- 	loop variable 						 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:The position of the rightmost occurrence							 **
***************************************************************************************/

// Function to get user input
void getInput(char input[], int size) 
{
    fgets(input, size, stdin);

    // Remove the trailing newline character from the input
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n')
    {
        input[input_length - 1] = '\0';    	
	}

}
// Function to find the rightmost occurrence of a substring in a string
int string_index(const char str[], const char str_p[]) {
    int str_len = strlen(str);
    int str_p_len = strlen(str_p);
    int i, j, k;

    // Iterate through the string str from right to left
    for (i = str_len - 1; i >= 0; i--) 
	{
        j = i, k = str_p_len - 1;
        // Check if the substring str_p matches with str starting from the current index
        while (k >= 0 && str[j] == str_p[k]) {
            j--;
            k--;
        }

        // If the substring str_p matches completely, return the starting position of the occurrence
        if (k == -1)
            return j + str_p_len;
    }

    // If no match is found, return -1
    return -1;
}

//Main Function
int main(int argc, char *argv[])
{
    char str[100], str_p[100];

    printf("Enter First String: ");
    getInput(str, sizeof(str));

    printf("Enter Second String: ");
    getInput(str_p, sizeof(str_p));

    printf("The position of the rightmost occurrence of %s: %d\n", str_p, string_index(str, str_p));

    return 0;
}
