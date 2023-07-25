#include <stdio.h>
#include <stdlib.h>
#define IN 1 /* define IN as a 1  inside a word */
#define	OUT 0 /* define out as a 0 outside a word */
/**************************************************************************************
** Function Name: main    								  						     ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: num_line 	-- number of line on the string input                    **
** 				: num_word	-- number of word on the string input                    **
**				: num_char  -- number of Char on the string input                    **
**				: num_state	-- State number ither 1 or 0			 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			: Line, word, and char count on program								 **
***************************************************************************************/

int main(int argc, char *argv[])
{
	int num_line, num_word, num_char, num_state;  // decliring variables
	num_line = num_word = num_char = 0; //initializing the int variables with 0
  	num_state = OUT;

  	char c;
  	while ((c = getchar()) != EOF)
  	{
    	++num_char;
    	
    	if (c == '\n')
    	{
     	 	++num_line;
    	}

    	if (c == ' ' || c == '\n' || c == '\t')
    	{
      		num_state = OUT;
    	}
    	else if (num_state == OUT)
    	{
      		num_state = IN;
      		++num_word;
    	}
  	}

  	printf("lines: %d\nwords: %d\ncharacters: %d\n", num_line, num_word, num_char);
  	return 0;
}
