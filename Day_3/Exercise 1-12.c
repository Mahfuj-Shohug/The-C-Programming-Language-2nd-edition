#include <stdio.h>
#include <stdlib.h>
/**************************************************************************************
** Function Name: main    								  						     ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: input_char -- string variable to input     			             **	
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			: prints string input one word per line.							 **
***************************************************************************************/

int main(int argc, char *argv[])
{
	char input_char;	// declired variable
	printf("Enter the string: ");
	
	while((input_char = getchar()) != EOF)
	{
		if(input_char == ' ' || input_char == '\n')
		{
			putchar('\n'); // put a new line per word
		}else
		{
			putchar(input_char); // put a word in every new line
		}
	}
	return 0;
}
