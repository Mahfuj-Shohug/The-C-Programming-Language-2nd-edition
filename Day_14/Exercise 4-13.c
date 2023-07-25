#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/**************************************************************************************
** Function Name: main, getInput, reverse_str	 					  				 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: str[]		-- Inputed string		                         	     **
** 				: temp		-- store reverse char on this							 **
**				: size	 	-- 	size of string										 **
**				: start,end	-- 	loop variable 						 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:recursive version of the string reversing							 **
***************************************************************************************/
/*Function to get user input*/
void getInput(char input[], int size)
{
    fgets(input, size, stdin);
    /*Remove the trailing newline character from the input*/
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n')
	{
        input[input_length - 1] = '\0';
    }
}

/* Function for reversing the string */
void reverse_str(char str[], int start, int end)
{
    if (start >= end)
	{
        return; /* Base case: string is already reversed or empty*/
    }

    /* Swap characters at start and end indices*/
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    /*Recursive call to reverse the substring between start and end*/
    reverse_str(str, start + 1, end - 1);
}

/* Main Function*/
int main(int argc, char *argv[])
{
    char str[MAX];
    printf("Enter any string: ");
    getInput(str, sizeof(str));

    printf("Your Inputted String: %s\n", str);

    int start = 0;
    int end = strlen(str) - 1;
    reverse_str(str, start, end);

    printf("Updated reversed string: %s\n", str);

    return 0;
}
