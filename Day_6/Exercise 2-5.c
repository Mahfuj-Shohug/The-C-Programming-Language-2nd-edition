#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	any													       	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_str1[] 	-- arry of characters to inpuut and compare              **
** 				: input_str2	-- 2nd arry of characters to inpuut and compare       	 **
**															    						 **
**				: i,j,		   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: character in input_str1 that matches any character show Match found or not **
                                														 **
*******************************************************************************************/
// function for return the match index number
int any(const char str1[], const char str2[]) {
    int i, j;

    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                return i;  // Match found, return the index
            }
        }
    }

    return -1;  // No match found
}

/*main function*/
int main(int argc, char *argv[])
{
    char input_str1[100], input_str2[100];

    printf("Enter the input string 1: ");
    gets(input_str1);

    printf("Enter the input string 2: ");
    gets(input_str2);

    int first_index_result = any(input_str1, input_str2);
    if (first_index_result != -1) 
	{
        printf("Match found at index: %d\n", first_index_result);
    } else
	{
        printf("No match found\n");
    }

    return 0;
}

